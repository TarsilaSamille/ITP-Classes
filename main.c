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

void linha(int x, int y,  Pixel *color)
{
    if (x==y){
       *color = colorir(30, 0, 0);
    }
}

int main(int argc, char **argv)
{
    int x ;
    int y ;
    FILE *fp = NULL;
    Pixel colorir(int r, int g, int b);
    /* Abre arquivo para gravacao */
    fp = fopen("imagee4em.ppm", "w");

    /*  Grava Cabeçalho (Header) no arquivo PPM  */
    fprintf(fp, "P3\n");
    fprintf(fp, "%d %d\n", DIMX, DIMY);
    fprintf(fp, "255\n");

    Pixel imagem[DIMX][DIMY];
    Pixel *pointer;

    for (y = 0; y < DIMY; ++y){
        for (x = 0; x < DIMX; ++x){
            pointer =  &imagem[x][y] ;
            clear(pointer,0, 200, 0);
            linha (x,y,pointer);
        }
    }

    for (y = 0; y < DIMY; ++y){
        for (x = 0; x < DIMX; ++x){
           todo( imagem[x][y], fp);
        }
    }

    /* fecha arquivo */
    fprintf(fp, "\n");



    /* Sucesso */
    return EXIT_SUCCESS;
}
