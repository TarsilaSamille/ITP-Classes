#include "imagem.h"

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

void fundo(Pixel **color, int dx, int dy ,int r, int g,int b)  { 
    int y,x;
    for (y = 0; y < dy; ++y){
        for (x = 0; x < dx; ++x){
            color[x][y] = colorir(r, g, b);
        }
    }
}

void bresenham(Ponto p1, Ponto p2, Pixel **color)     { 
    int m_new = 2 * (p2.y - p1.y); 
    int slope_error_new = m_new - (p2.x - p1.x); 
    for (int x = p1.x, y = p1.y; x <= p2.x; x++) { 
        // Add slope to increment angle formed 
        slope_error_new += m_new; 
        // Slope error reached limit, time to 
        // increment y and update slope error. 
        if (slope_error_new >= 0) { 
                y++; 
                slope_error_new -= 2 * (p2.x - p1.x); 
        } 
         color[x][y] = colorir(80, 0, 255);
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