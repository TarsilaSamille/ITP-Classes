#include "imagem.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>


int pitagoras (int x, int y){
    double total = (x*x)+(y*y);
    return (int) abs(sqrt(total));
}

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

void fundo(Pixel **color, int dx, int dy ,Pixel cor)  { 
    int y,x;
    for (y = 0; y < dy; ++y){
        for (x = 0; x < dx; ++x){
            color[x][y] = colorir(cor.r, cor.g, cor.b);
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


void circulo(Ponto p1, int r, Pixel **color, Pixel cor)
{
	int x = -r, y = 0, err = 2-2*r; /* II. Quadrant */ 
	do {
		color[p1.x-x][p1.y+y] = colorir(cor.r, cor.g, cor.b); /*   I. Quadrant */
		color[p1.x-y][p1.y-x] = colorir(cor.r, cor.g, cor.b); /*  II. Quadrant */
		color[p1.x+x][p1.y-y] = colorir(cor.r, cor.g, cor.b); /* III. Quadrant */
		color[p1.x+y][p1.y+x] = colorir(cor.r, cor.g, cor.b); /*  IV. Quadrant */
		r = err;
		if (r <= y) err += ++y*2+1;           /* e_xy+e_y < 0 */
		if (r > x || err > y) err += ++x*2+1; /* e_xy+e_x > 0 or no 2nd y-step */
	} while (x < 0);
}

void fill(Ponto p,int dx, int dy , Pixel **color, Pixel cor, Pixel background){
        int y,x;
        Ponto ponto;
        color[p.x][p.y] = colorir(background.r, background.g, background.b);  

        for (x = 0; x < dx - p.x; ++x){
            if(color[p.x+x][p.y].r != background.r || color[p.x+x][p.y].g != background.g || color[p.x+x][p.y].b != background.b){
                break;
            }
            ponto = definePonto(p.x+x,p.y);
            //fillY( ponto, dx, dy , color, cor, background);
            color[p.x+x][p.y] = colorir(cor.r, cor.g, cor.b);
        }
        for (x = 1; x < p.x; ++x){
            if(color[p.x-x][y].r != background.r || color[p.x-x][p.y].g != background.g || color[p.x-x][p.y].b != background.b){
                break;
            }
            ponto = definePonto(p.x-x,p.y);
            //fillY( ponto, dx, dy , color, cor, background);
            color[p.x-x][p.y] = colorir(cor.r, cor.g, cor.b);
        }
         for (y = 1; y < dy; ++y){
            if(color[p.x][p.y+y].r != background.r || color[p.x][p.y+y].g != background.g || color[p.x][p.y+y].b != background.b){
                break;
            }
            ponto = definePonto(p.x,p.y+y);
            //fillX( ponto, dx, dy , color, cor, background);
            color[p.x][p.y+y] = colorir(cor.r, cor.g, cor.b);
        }
        for (y = 1; y < p.y; ++y){
            if(color[p.x][p.y-y].r != background.r || color[p.x][p.y-y].g != background.g || color[p.x][p.y-y].b != background.b){
                break;
            }
            ponto = definePonto(p.x,p.y-y);
            //fillX( ponto, dx, dy , color, cor, background);
            color[p.x][p.y-y] = colorir(cor.r, cor.g, cor.b);
        }
        for (x = 1; x < pitagoras ( dx - p.x, dy- p.y); ++x){
            if(color[p.x+x][p.y+x].r != background.r || color[p.x+x][p.y+x].g != background.g || color[p.x+x][p.y+x].b != background.b){
                break;
            }
            ponto = definePonto(p.x+x,p.y+x);
            fillY( ponto, dx, dy , color, cor, background);
            fillX( ponto, dx, dy , color, cor, background);
            color[p.x+x][p.y+x] = colorir(cor.r, cor.g, cor.b);
        }
        for (x = 1; x < pitagoras (dx - p.x, dy- p.y); ++x){
            if(color[p.x-x][p.y-x].r != background.r || color[p.x-x][p.y-x].g != background.g || color[p.x-x][p.y-x].b != background.b){
                break;
            }
            ponto = definePonto(p.x-x,p.y-x);
            fillY( ponto, dx, dy , color, cor, background);
            fillX( ponto, dx, dy , color, cor, background);
            color[p.x-x][p.y-x] = colorir(cor.r, cor.g, cor.b);
        }
         for (x = 1; x < pitagoras (dx - p.x, dy- p.y); ++x){
            if(color[p.x+x][p.y-x].r != background.r || color[p.x+x][p.y-x].g != background.g || color[p.x+x][p.y-x].b != background.b){
                break;
            }
            ponto = definePonto(p.x+x,p.y-x);
            fillY( ponto, dx, dy , color, cor, background);
            fillX( ponto, dx, dy , color, cor, background);
            color[p.x+x][p.y-x] = colorir(cor.r, cor.g, cor.b);
        }
         for (x = 1; x < pitagoras (dx - p.x, dy- p.y); ++x){
            if(color[p.x-x][p.y+x].r != background.r || color[p.x-x][p.y+x].g != background.g || color[p.x-x][p.y+x].b != background.b){
                break;
            }
            ponto = definePonto(p.x-x,p.y+x);
            fillY( ponto, dx, dy , color, cor, background);
            fillX( ponto, dx, dy , color, cor, background);
            color[p.x-x][p.y+x] = colorir(cor.r, cor.g, cor.b);
        }

}



void fillY(Ponto p,int dx, int dy , Pixel **color, Pixel cor, Pixel background){
        int y,x;
        color[p.x][p.y] = colorir(background.r, background.g, background.b);  

         for (y = 1; y < dy; ++y){
            if(color[p.x][p.y+y].r != background.r || color[p.x][p.y+y].g != background.g || color[p.x][p.y+y].b != background.b){
                break;
            }
            color[p.x][p.y+y] = colorir(cor.r, cor.g, cor.b);
        }
        for (y = 1; y < p.y; ++y){
            if(color[p.x][p.y-y].r != background.r || color[p.x][p.y-y].g != background.g || color[p.x][p.y-y].b != background.b){
                break;
            }
            color[p.x][p.y-y] = colorir(cor.r, cor.g, cor.b);
        }

}


void fillX(Ponto p,int dx, int dy , Pixel **color, Pixel cor, Pixel background){
        int y,x;
        color[p.x][p.y] = colorir(background.r, background.g, background.b);  

        for (x = 0; x < dx - p.x; ++x){
            if(color[p.x+x][p.y].r != background.r || color[p.x+x][p.y].g != background.g || color[p.x+x][p.y].b != background.b){
                break;
            }
            color[p.x+x][p.y] = colorir(cor.r, cor.g, cor.b);
        }
        for (x = 1; x < p.x; ++x){
            if(color[p.x-x][y].r != background.r || color[p.x-x][p.y].g != background.g || color[p.x-x][p.y].b != background.b){
                break;
            }
            color[p.x-x][p.y] = colorir(cor.r, cor.g, cor.b);
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