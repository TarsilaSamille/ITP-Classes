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

// void bresenham2(Ponto p1, Ponto p2, Pixel **color){ 
//     int x,y,fator;


//     int m_newx = 2 * (p2.x - p1.x); 
//     int slope_error_newx = m_newx - (p2.y - p1.y); 
//     int m_newy = 2 * (p2.y - p1.y); 
//     int slope_error_newy = m_newy - (p2.x - p1.x); 
//     printf("X -%d er %d--\nY -%d er %d-\n",m_newx,slope_error_newx, slope_error_newy , m_newy);
    
//     int m_new = 2 * (p2.x - p1.x); 
//     int slope_error_new = m_new - (p2.y - p1.y); 

//          for (x = p1.x, y = p1.y; y <= p2.y; y++) { 
//             slope_error_new += m_new; 
//             if (slope_error_new >= 0) { 
//                     x++; 
//                     slope_error_new -= 2 * (p2.y - p1.y); 

//             } 
//             color[x][y] = colorir(0, 0, 255);
//          }   
// }          

void bresenham(Ponto p1, Ponto p2, Pixel **color){ 
    int x , y,fator;
    if(p2.y < p1.y) {bresenham(p2, p1, color);                       ;
}else{

 int m_newx = 2 * (p2.x - p1.x); 
     int slope_error_newx = m_newx - (p2.y - p1.y); 

    int m_newy = 2 * (p2.y - p1.y); 
    int slope_error_newy = m_newy - (p2.x - p1.x); 
    printf("X -%d er %d--\nY -%d er %d-\n",m_newx,m_newy, slope_error_newy , m_newy);

    int m_new = 2 * (p2.y - p1.y); 
    int slope_error_new = m_new - (p2.x - p1.x);

    int fatorix, fatoriy, fatorstop, diference,plus;

   printf("---%d er %d--- P1(%d, %d), p2(%d, %d)\n",m_new,slope_error_new, p1.x , p1.y,  p2.x , p2.y);

    if(m_newy < m_newx) {


        m_new = 2 * (p2.x - p1.x); 
        slope_error_new = m_new - (p2.y - p1.y); 

           if(p2.x < p1.x) {//bresenham(p2, p1, color);
         m_new = -1 * m_new; 
        slope_error_new = m_new - (p2.y - p1.y); 
        }

    if (p2.x < p1.x) { 
        fatorix = p2.x; fatoriy = p2.y; fatorstop =p1.y ; diference= (p1.y - p2.y);plus = -1;
    }else{
        fatorix = p1.x; fatoriy = p1.y; fatorstop =p2.y ; diference= (p2.y - p1.y);plus = 1;
    }
         for (x = fatorix, y = fatoriy; y <= fatorstop; y++) { 
            slope_error_new += m_new; 
            if (slope_error_new >= 0) { 
                    x = x + plus; 
                    slope_error_new -= 2 * diference; 

            } 
            color[x][y] = colorir(0, 0, 255);
         }   
    }else{
    if (p2.x < p1.x) { 
        fatorix = p2.x; fatoriy = p2.y; fatorstop =p1.x ; diference= (p1.x - p2.x);plus = -1;
    }else{
        fatorix = p1.x; fatoriy = p1.y; fatorstop =p2.x ; diference= (p2.x - p1.x);plus = 1;
                           printf("aaaaaaaaa\n");

    }
    for (x = fatorix, y = fatoriy; x <= fatorstop; x++) { 

            slope_error_new += m_new; 
            //printf(" er %d--\n",slope_error_new);

            if (slope_error_new >= 0) { 
                    y = y + plus; 
                    slope_error_new -= 2 * diference; 
                  // printf("%d er %d--- P1(%d, %d), p2(%d, %d)\n",m_new,slope_error_new, p1.x , p1.y,  p2.x ,diference);
                   if (p2.x < p1.x) { 
                       
                   //printf("%d das %d\n",( 2 * (p2.x - p1.x)) - (p2.y - p1.y), 2 * (p2.x - p1.x) );
                }
            } 
            color[x][y] = colorir(0, 0, 255);
            printf("(%d, %d)\n", x, y);

    }

    }

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
    if(strcmp(primitiva, "image") == 0)
        imagem = alocar_matriz(dimx, dimy);

    //ação
    fscanf(arquivoespecificacao, "%s %s %s %s\n", primitiva, r, g, b);

    if(strcmp(primitiva, "clear") == 0)
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

    //bresenham(p2 , p1, imagem) ;
   // bresenham(p2 , p3, imagem) ;
    bresenham(p3 , p4, imagem) ;
    //bresenham(p1 , p4, imagem) ;


    //save
    fscanf(arquivoespecificacao, "%s %s\n", primitiva,nome);

    if(strcmp(primitiva, "save") == 0)
        finalizarImagem(imagem, fp, nome, dimx, dimy);
    imagem = liberar_matriz (dimx, dimy, imagem);
    /* Sucesso */
    return EXIT_SUCCESS;
}
