#include "pixel.h"
#include "ponto.h"

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void gravarPixel( Pixel color, FILE *fp){
   fprintf( fp, "%d %d %d\n",color.r,color.g,color.b);
}

void finalizarImagem( Pixel **imagem , FILE *fp, char nome[], int dx, int dy){
    int y,x;
    fp = fopen(nome, "w");
    /*  Grava Cabeçalho (Header) no arquivo PPM  */
    fprintf(fp, "P3\n");
    fprintf(fp, "%d %d\n", dx , dy);
    fprintf(fp, "255\n");
    for (y = 0; y < dy; ++y){
        for (x = 0; x < dx; ++x){
           gravarPixel( imagem[x][y] , fp);
        }
    }
    fprintf(fp, "\n");
}

void fundo(Pixel **color, int dx, int dy ,int r, int g,int b){ 
    int y,x;
    for (y = 0; y < dy; ++y){
        for (x = 0; x < dx; ++x){
            color[x][y] = colorir(r, g, b);
        }
    }
}




void bresenham(Ponto p1, Ponto p2, Pixel **color)
{
	int dx =  abs(p2.x-p1.x), sx = p1.x<p2.x ? 1 : -1;
	int dy = -abs(p2.y-p1.y), sy = p1.y<p2.y ? 1 : -1; 
	int err = dx+dy, e2; /* error value e_xy */

	while(p1.x!=p2.x || p1.y!=p2.y){  /* loop */
        color[p1.x][p1.y] = colorir(0, 0, 255);
		e2 = 2*err;
		if (e2 >= dy) { err += dy; p1.x += sx; } /* e_xy+e_x > 0 */
		if (e2 <= dx) { err += dx; p1.y += sy; } /* e_xy+e_y < 0 */
	}
}

Pixel **alocar_matriz (int m, int n){
  Pixel **v;  
  int   i;    
  /* aloca as linhas da matriz */
  v = (Pixel **) calloc (m, sizeof(Pixel *));
  /* aloca as colunas da matriz */
  for ( i = 0; i < m; i++ ) {
      v[i] = (Pixel*) calloc (n, sizeof(Pixel));	
  }
  return (v); 
}

Pixel **liberar_matriz (int m, int n, Pixel **v){
  int  i;  
  for (i=0; i<m; i++) free (v[i]); 
  free (v);     
  return (NULL); 
}

int main(int argc, char **argv){
    int x,y;
    FILE *fp = NULL;

    Pixel **imagem;

    FILE *arquivoespecificacao;
    int dimx, dimy;

    char primitiva[15] = "";
    char dimencaox[4] = "";
    char dimencaoy[4] = "";

    char r[3] = ""; 
    char g[3] = ""; 
    char b[3] = "";

    char nome[15] = "";

    //dimenção
    arquivoespecificacao = fopen("especificacao.txt", "r");
    fscanf(arquivoespecificacao, "%s %s %s\n", primitiva, dimencaox, dimencaoy);



    dimx = atoi(dimencaox);
    dimy = atoi(dimencaoy);


    //if(strcmp(primitiva, "image") == 0)
        imagem = alocar_matriz(dimx, dimy);

    //ação
    fscanf(arquivoespecificacao, "%s %s %s %s\n", primitiva, r, g, b);

    //if(strcmp(primitiva, "clear") == 0)
        fundo(imagem, dimx, dimy, atoi(r),atoi(g),atoi(b));


    Ponto p1, p2, p3 , p4;
    p1= definePonto(100,50);
    p2= definePonto(0,60);
    p3= definePonto(500,50);
    p4= definePonto(220,600);
    imagem[100][50] = colorir(255, 0, 0);
    imagem[0][60] = colorir(255, 0, 0);
    imagem[500][50] = colorir(0, 0, 0);
    imagem[220][600] = colorir(0, 0, 0);

    bresenham(p2 , p1, imagem) ;
    bresenham(p2 , p3, imagem) ;
    bresenham(p3 , p4, imagem) ;
    bresenham(p1 , p4, imagem) ;


    //save
    fscanf(arquivoespecificacao, "%s %s\n", primitiva,nome);

    //if(strcmp(primitiva, "save") == 0)
        finalizarImagem(imagem, fp, nome, dimx, dimy);
    imagem = liberar_matriz (dimx, dimy, imagem);
    /* Sucesso */
    return EXIT_SUCCESS;
}
