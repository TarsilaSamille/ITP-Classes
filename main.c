#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define DIMX (600)
#define DIMY (400)

void clear(int x, int y, unsigned char color[])
{
    color[0] = 255; /* red */
    color[1] = 255; /* green */
    color[2] = 255; /* blue */
}

void colorir(int r, int g, int b,  unsigned char color[])
{
    color[0] = r; /* red */
    color[1] = g; /* green */
    color[2] = b; /* blue */
}

void black(int x, int y, unsigned char color[])
{
    color[0] = 0; /* red */
    color[1] = 0; /* green */
    color[2] = 0; /* blue */
}

void original(int x, int y, int color[])
{
    color[0] = x + 2 * y % 256; /* red */
    color[1] = x - y % 256;     /* green */
    color[2] = (x + y) % 256;   /* blue */
}


void todo(unsigned char color[], FILE *fp)
{

            colorir(255, 255, 255, color);
            //fwrite(color, 1, 3, fp);
        //     fread(color, 3, 1, fp);
        printf("%d %d %d\n", color[0],color[1],color[2]);
             fprintf( fp, "%d %d %d\n", color[0],color[1],color[2]);
    
}

void linha(int x, int y, unsigned char color[], FILE *fp)
{

            if (x==y){
                colorir(0, 0, 0, color);
             fprintf( fp, "%d %d %d\n", color[0],color[1],color[2]);
            }

 
}


int main(int argc, char **argv)
{
    int x = 0;
    int y = 0;
    FILE *fp = NULL;
    char color[3] = {0, 0, 0}; /* r, g, b */
    void colorir(int r, int g, int b, unsigned char color[]);
    /* Abre arquivo para gravacao */
    fp = fopen("imageeem.ppm", "w");

    /*  Grava Cabeçalho (Header) no arquivo PPM  */
    fprintf(fp, "P3\n");
    fprintf(fp, "%d %d\n", DIMX, DIMY);
    fprintf(fp, "255\n");

    for (y = 0; y < DIMY; ++y){
        for (x = 0; x < DIMX; ++x){
        todo(color, fp);
        linha(x,y,color, fp);
        }
    }
    /* fecha arquivo */
    fprintf(fp, "\n");



    /* Sucesso */
    return EXIT_SUCCESS;
}
