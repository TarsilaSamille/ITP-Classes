
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


#define DIMX         (600)
#define DIMY         (400)


void clear( int x, int y, int color[] )
{
    color[0] = 255; /* red */
    color[1] = 255; /* green */
    color[2] = 255; /* blue */
}

void colorir( int r, int g, int b,int color[] )
{
    color[0] = r; /* red */
    color[1] = g; /* green */
    color[2] = b; /* blue */
}

void black( int x, int y, int color[] )
{
        color[0] = 0; /* red */
        color[1] = 0;       /* green */
        color[2] = 0;       /* blue */

}

void red( int x, int y, int color[] )
{
        color[0] = 255; /* red */
        color[1] = 0;       /* green */
        color[2] = 0;       /* blue */

}


void green( int x, int y, int color[] )
{
    color[0] = 0;       /* red */
    color[1] = 255; /* green */
    color[2] = 0;       /* blue */
}


void blue( int x, int y, int color[] )
{
    color[0] = 0;       /* red */
    color[1] = 0;       /* green */
    color[2] = 255; /* blue */
}


void gray( int x, int y, int color[] )
{
    color[0] = x % 256; /* red */
    color[1] = x % 256; /* green */
    color[2] = x % 256; /* blue */
}


void original( int x, int y, int color[] )
{
    color[0] = x + 2 * y % 256;  /* red */
    color[1] = x - y % 256;      /* green */
    color[2] = (x + y) % 256;    /* blue */
}

void initFile(FILE *fp){
 /* Abre arquivo para gravacao */
    fp = fopen( "imagem.ppm", "w" );

    /*  Grava Cabeçalho (Header) no arquivo PPM  */
    fprintf( fp, "P6\n" );
    fprintf( fp, "%d %d\n", DIMX, DIMY );
    fprintf( fp, "255\n" );

}


int main( int argc, char ** argv )
{
    int x = 0;
    int y = 0;
    FILE * fp = NULL;
    int color[3] = { 0, 0, 0 }; /* r, g, b */
    void colorir(  int r, int g, int b,int color[] );
	 //initFile(fp);
    /* Abre arquivo para gravacao */
    fp = fopen( "imagem.ppm", "w" );

    /*  Grava Cabeçalho (Header) no arquivo PPM  */
    fprintf( fp, "P6\n" );
    fprintf( fp, "%d %d\n", DIMX, DIMY );
    fprintf( fp, "255\n" );
	
    for ( y = 0; y < DIMY; ++y )
    {
        for ( x = 0; x < DIMX; ++x )
        {
            if(x==y){
            	//black( x, y, color );
			}else{	
				colorir(50, 25,9, color );
			}
            fprintf( fp, "%d %d %d\n", color[0],color[1],color[2]);
        }
    }

	// /* fecha arquivo */
    // fclose(fp);

	// fp = fopen( "imagem.ppm", "wb" );


	//  for ( y = 0; y < DIMY; ++y )
    // {
    //     for ( x = 0; x < DIMX; ++x )
    //     {	
	// 		if(x==y){
    //         	black( x, y, color );
	// 		}	
    //         fwrite( color, sizeof(char), sizeof(color), fp );
    //     }
    // }

    /* fecha arquivo */
    fclose(fp);

    /* Sucesso */
    return EXIT_SUCCESS;
}


// #include "desenho.h"
// #include "circulo.h"
// #include "quadrado.h"
// #include "ponto.h"

// #include <stdio.h>

// int main() {
// 	char lixo, c = 'A';
// 	Desenho d = criaDesenho();
// 	while (c != 'S') {
// 		printf("\nDigite o que deseja fazer: \n");
// 		printf("C - inserir circulo\n");
// 		printf("Q - inserir quadrado\n");
// 		printf("P - inserir ponto\n");
// 		printf("A - calcular área total\n");
// 		printf("S - sair do programa\n");
// 		printf("OLA MUNDO!\n");
// 		scanf("%c", &c);
// 		if (c == 'C') {
// 			int raio, x, y;
// 			printf("Digite o raio: \n");
// 			scanf("%d", &raio);
// 			printf("Digite o centro na forma x y: \n");
// 			scanf("%d %d", &x, &y);

// 			Ponto p = definePonto(x, y);
// 			Circulo c = defineCirculo(raio, p);
// 			insereCirculo(&d, c);
// 		}
// 		else if (c == 'Q') {
// 			int lado, x, y;
// 			printf("Digite o lado: \n");
// 			scanf("%d", &lado);
// 			printf("Digite o topo esquerdo na forma x y: \n");
// 			scanf("%d %d", &x, &y);

// 			Ponto p = definePonto(x, y);
// 			Quadrado q = defineQuadrado(lado, p);
// 			insereQuadrado(&d, q);
// 		}
// 		else if (c == 'P') {
// 			int x, y;
// 			printf("Digite o ponto na forma x y: \n");
// 			scanf("%d %d", &x, &y);

// 			Ponto p = definePonto(x, y);
// 			inserePonto(&d, p);
			
// 		}
// 		else if (c == 'A') {
// 			float area = areaTotal(d);
// 			int n = numeroFormas(d);
// 			printf("Existem %d formas no desenho ocupando %f de área\n",n, area);
// 		}
// 		scanf("%c", &lixo);
// 	}
// 	return 0;
// }