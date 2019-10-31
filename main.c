#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define DIMX (600)
#define DIMY (400)



typedef struct Pixel{
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Pixel;

Pixel colorir(int r, int g, int b)
{
    Pixel color;
    color.r = r; /* red */
    color.g = g; /* green */
    color.b = b; /* blue */
    return color;
}

void todo( Pixel color, FILE *fp)
{
   fprintf( fp, "%d %d %d\n",color.r,color.g,color.b);
    
}

void clear(Pixel *color, int r, int g, int b)
{
    *color = colorir(r, g, b);    
}

void linha(int x, int y,  Pixel *color)
{
    if (x==y){
       *color = colorir(30, 0, 0);
    }
}

void bresenham(int x1, int y1, int x2,int y2, Pixel *color[DIMX][DIMY])     { 
    int m_new = 2 * (y2 - y1); 
    int slope_error_new = m_new - (x2 - x1); 
    for (int x = x1, y = y1; x <= x2; x++) { 
        // Add slope to increment angle formed 
        slope_error_new += m_new; 
        // Slope error reached limit, time to 
        // increment y and update slope error. 
        if (slope_error_new >= 0) { 
                y++; 
                slope_error_new -= 2 * (x2 - x1); 
        } 
        clear(color[x][y],0, 200, 0);
    } 
}          
int main(int argc, char **argv)
{
    int x,y;
    FILE *fp = NULL;
    Pixel colorir(int r, int g, int b);
    fp = fopen("imagee4em.ppm", "w");


    /*  Grava Cabeçalho (Header) no arquivo PPM  */
    fprintf(fp, "P3\n");
    fprintf(fp, "%d %d\n",DIMX , DIMY);
    fprintf(fp, "255\n");

    Pixel imagem[DIMX][DIMY];
    Pixel *ima[DIMX][DIMY];
    Pixel *pointer;

    for (y = 0; y < DIMY; ++y){
        for (x = 0; x < DIMX; ++x){
            ima[x][y] =  &imagem[x][y];
            pointer =  &imagem[x][y];
            clear(pointer , 255, 255, 255);
            linha (x,y,pointer);
        }
    }


    bresenham(100, 50, 200, 50, ima) ;


    for (y = 0; y < DIMY; ++y){
        for (x = 0; x < DIMX; ++x){
           todo( imagem[x][y] , fp);
        }
    }

    /* fecha arquivo */
    fprintf(fp, "\n");



    /* Sucesso */
    return EXIT_SUCCESS;
}
