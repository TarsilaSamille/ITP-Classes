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

//seta a cor do background
void fundo(Pixel **color, int dx, int dy ,Pixel cor)  { 
    int y,x;
    for (y = 0; y < dy; ++y){
        for (x = 0; x < dx; ++x){
            color[x][y] = colorir(cor.r, cor.g, cor.b);
        }
    }
}

//desenho de linhas e poligonos
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

//desenho de círculos
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

void pcartesianolinha(Ponto p0, int ax,int bx,int dx, int dy , Pixel **color, Pixel cor, Pixel background){
    Ponto p1,p2;
    p1= definePonto(p0.x + (bx*30), p0.y);
    int z = 1;
    while(z< 10){
        p2= definePonto(p0.x + (( z + bx)*30),p0.y - (z*ax*30));
        bresenham(p1, p2, color, cor);
        p2= definePonto(p0.x - (( z - bx)*30),p0.y + (z*ax*30));
        bresenham(p1, p2, color, cor);
        z++;
    }
    // Ponto p3;
    // p3 = definePonto(dx - p1.x, dy- p1.y);
    //     bresenham(p1,  pitagoras( dx - p1.x, dy- p1.y), color, cor);

}



//desenho do plano cartesiano e função linear
void pcartesiano(Ponto p,int dx, int dy , Pixel **color, Pixel cor, Pixel background){
         int y,x,i,j,z;
        Ponto ponto;
        Pixel traco = colorir(0, 200, 0);
        Pixel **o, temp[dx][dy];
        o = alocar_matriz(dx, dy);            
        for(i = 0; i < dx; i++) {
            for(j = 0; j < dy; j++) {
                temp[i][j] = color[i][j];
            }        
        }
        for(i = 0; i < dx; i++) {
            for(j = 0; j < dy; j++) {
                o[i][j] = temp[i][j];
            }        
        }

        for (x = 0; x < dx - p.x; ++x){
            if(o[p.x+x][p.y].r != background.r || o[p.x+x][p.y].g != background.g || o[p.x+x][p.y].b != background.b){
                break;
            }
            if((p.x+x)%30 == 0){
                z=-4;
                do{
                    color[p.x+x+z][p.y] = colorir(traco.r, traco.g,traco.b);
                    z++;
                }while(z!=4);
            }
            ponto = definePonto(p.x+x,p.y);
            color[p.x+x][p.y] = colorir(cor.r, cor.g, cor.b);
        }
        for (x = 1; x < p.x; ++x){
            if(o[p.x-x][y].r != background.r || o[p.x-x][p.y].g != background.g || o[p.x-x][p.y].b != background.b){
                break;
            }
            if((p.x-x)%30 == 0){
                z=-4;
                do{
                    color[p.x-(x+z)][p.y] = colorir(traco.r, traco.g,traco.b);
                    z++;
                }while(z!=4);
            }
            ponto = definePonto(p.x-x,p.y);
            color[p.x-x][p.y] = colorir(cor.r, cor.g, cor.b);
        }
         for (y = 1; y < dy; ++y){
            if(o[p.x][p.y+y].r != background.r || o[p.x][p.y+y].g != background.g || o[p.x][p.y+y].b != background.b){
                break;
            }
            if((p.y+y)%30 == 0){
                z=-4;
                do{
                    color[p.x][p.y+y+z] =  colorir(traco.r, traco.g,traco.b);
                    z++;
                }while(z!=4);
            }
            ponto = definePonto(p.x,p.y+y);
            color[p.x][p.y+y] = colorir(cor.r, cor.g, cor.b);
        }
        for (y = 1; y < p.y; ++y){
            if(o[p.x][p.y-y].r != background.r || o[p.x][p.y-y].g != background.g || o[p.x][p.y-y].b != background.b){
                break;
            }
            if((p.y-y)%30 == 0){
                z=-4;
                do{
                    color[p.x][p.y-(y+z)] =  colorir(traco.r, traco.g,traco.b);
                    z++;
                }while(z!=4);
            }
            ponto = definePonto(p.x,p.y-y);
            color[p.x][p.y-y] = colorir(cor.r, cor.g, cor.b);
        }
}


//Preenchimento 
void fill(Ponto p,int dx, int dy , Pixel **color, Pixel cor, Pixel background){
        int y,x,i,j;
        Ponto ponto;

        Pixel **o, temp[dx][dy];
        o = alocar_matriz(dx, dy);            
        for(i = 0; i < dx; i++) {
            for(j = 0; j < dy; j++) {
                temp[i][j] = color[i][j];
            }        
        }
        for(i = 0; i < dx; i++) {
            for(j = 0; j < dy; j++) {
                o[i][j] = temp[i][j];
            }        
        }

        for (x = 0; x < dx - p.x; ++x){
            if(o[p.x+x][p.y].r != background.r || o[p.x+x][p.y].g != background.g || o[p.x+x][p.y].b != background.b){
                break;
            }
            ponto = definePonto(p.x+x,p.y);
            fillY( ponto, dx, dy , color, o,cor, background);
            color[p.x+x][p.y] = colorir(cor.r, cor.g, cor.b);
        }
        for (x = 1; x < p.x; ++x){
            if(o[p.x-x][y].r != background.r || o[p.x-x][p.y].g != background.g || o[p.x-x][p.y].b != background.b){
                break;
            }
            ponto = definePonto(p.x-x,p.y);
            fillY( ponto, dx, dy , color,  o,cor, background);
            color[p.x-x][p.y] = colorir(cor.r, cor.g, cor.b);
        }
         for (y = 1; y < dy; ++y){
            if(o[p.x][p.y+y].r != background.r || o[p.x][p.y+y].g != background.g || o[p.x][p.y+y].b != background.b){
                break;
            }
            ponto = definePonto(p.x,p.y+y);
            fillX( ponto, dx, dy , color,o, cor, background);
            color[p.x][p.y+y] = colorir(cor.r, cor.g, cor.b);
        }
        for (y = 1; y < p.y; ++y){
            if(o[p.x][p.y-y].r != background.r || o[p.x][p.y-y].g != background.g || o[p.x][p.y-y].b != background.b){
                break;
            }
            ponto = definePonto(p.x,p.y-y);
            fillX( ponto, dx, dy , color,o, cor, background);
            color[p.x][p.y-y] = colorir(cor.r, cor.g, cor.b);
        }
        for (x = 1; x < pitagoras ( dx - p.x, dy- p.y); ++x){
            if(o[p.x+x][p.y+x].r != background.r || o[p.x+x][p.y+x].g != background.g || o[p.x+x][p.y+x].b != background.b){
                break;
            }
            ponto = definePonto(p.x+x,p.y+x);
            fillY( ponto, dx, dy , color,o, cor, background);
            fillX( ponto, dx, dy , color,o, cor, background);
            color[p.x+x][p.y+x] = colorir(cor.r, cor.g, cor.b);
        }
        for (x = 1; x < pitagoras (dx - p.x, dy- p.y); ++x){
            if(o[p.x-x][p.y-x].r != background.r || o[p.x-x][p.y-x].g != background.g || o[p.x-x][p.y-x].b != background.b){
                break;
            }
            ponto = definePonto(p.x-x,p.y-x);
            fillY( ponto, dx, dy , color,o,  cor, background);
            fillX( ponto, dx, dy , color,o,  cor, background);
            color[p.x-x][p.y-x] = colorir(cor.r, cor.g, cor.b);
        }
         for (x = 1; x < pitagoras (dx - p.x, dy- p.y); ++x){
            if(o[p.x+x][p.y-x].r != background.r || o[p.x+x][p.y-x].g != background.g || o[p.x+x][p.y-x].b != background.b){
                break;
            }
            ponto = definePonto(p.x+x,p.y-x);
            fillY( ponto, dx, dy , color,o,  cor, background);
            fillX( ponto, dx, dy , color,o,  cor, background);
            color[p.x+x][p.y-x] = colorir(cor.r, cor.g, cor.b);
        }
         for (x = 1; x < pitagoras (dx - p.x, dy- p.y); ++x){
            if(o[p.x-x][p.y+x].r != background.r || o[p.x-x][p.y+x].g != background.g || o[p.x-x][p.y+x].b != background.b){
                break;
            }
            ponto = definePonto(p.x-x,p.y+x);
            fillY( ponto, dx, dy , color, o, cor, background);
            fillX( ponto, dx, dy , color, o,  cor, background);
            color[p.x-x][p.y+x] = colorir(cor.r, cor.g, cor.b);
        }

}


//Preenchimento no eixo Y
void fillY(Ponto p,int dx, int dy , Pixel **color, Pixel **o, Pixel cor, Pixel background){
        int y,x;
        //color[p.x][p.y] = colorir(background.r, background.g, background.b);  

         for (y = 1; y < dy; ++y){
            if(o[p.x][p.y+y].r != background.r || o[p.x][p.y+y].g != background.g || o[p.x][p.y+y].b != background.b){
                break;
            }
            color[p.x][p.y+y] = colorir(cor.r, cor.g, cor.b);
        }
        for (y = 1; y < p.y; ++y){
            if(o[p.x][p.y-y].r != background.r || o[p.x][p.y-y].g != background.g || o[p.x][p.y-y].b != background.b){
                break;
            }
            color[p.x][p.y-y] = colorir(cor.r, cor.g, cor.b);
        }

}

//Preenchimento no eixo X
void fillX(Ponto p,int dx, int dy , Pixel **color,Pixel **o, Pixel cor, Pixel background){
        int y,x;
        color[p.x][p.y] = colorir(background.r, background.g, background.b);  

        for (x = 0; x < dx - p.x; ++x){
            if(o[p.x+x][p.y].r != background.r || o[p.x+x][p.y].g != background.g || o[p.x+x][p.y].b != background.b){
                break;
            }
            color[p.x+x][p.y] = colorir(cor.r, cor.g, cor.b);
        }
        for (x = 1; x < p.x; ++x){
            if(o[p.x-x][y].r != background.r || o[p.x-x][p.y].g != background.g || o[p.x-x][p.y].b != background.b){
                break;
            }
            color[p.x-x][p.y] = colorir(cor.r, cor.g, cor.b);
        }
}
//Alocação da matriz
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
//Liberação da matriz
Pixel **liberar_matriz (int m, int n, Pixel **v){
    int  i;
    for (i=0; i<m; i++) free (v[i]); 
    free (v);
    return (NULL); 
}