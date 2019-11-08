#include "imagem.h"
#include <stdlib.h>

void gravarPixel( Pixel color, FILE *fp){
   fprintf( fp, "%d %d %d\n",color.r,color.g,color.b);
}

void finalizarImagem( Pixel **imagem ,  char nome[], int dx, int dy){
    int y,x;
    FILE *fp = fopen(nome, "w");
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
    fclose(fp);
}

void fundo(Pixel **color, int dx, int dy ,int r, int g,int b)  { 
    int y,x;
    for (y = 0; y < dy; ++y){
        for (x = 0; x < dx; ++x){
            color[x][y] = colorir(r, g, b);
        }
    }
}


void bresenham(Ponto p1, Ponto p2, Pixel **color, Pixel cor)
{
	int dx =  abs(p2.x-p1.x), sx = p1.x<p2.x ? 1 : -1;
	int dy = -abs(p2.y-p1.y), sy = p1.y<p2.y ? 1 : -1; 
	int err = dx+dy, e2; /* error value e_xy */
	while(p1.x!=p2.x || p1.y!=p2.y){  /* loop */
        color[p1.x][p1.y] = colorir(cor.r, cor.g, cor.b);
		e2 = 2*err;
		if (e2 >= dy) { err += dy; p1.x += sx; } /* e_xy+e_x > 0 */
		if (e2 <= dx) { err += dx; p1.y += sy;} /* e_xy+e_y < 0 */
	}
}

Pixel **alocar_matriz (int m, int n)
{
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

Pixel **liberar_matriz (int m, int n, Pixel **v)
{
  int  i;  
  for (i=0; i<m; i++) free (v[i]); 
  free (v);     
  return (NULL); 
}