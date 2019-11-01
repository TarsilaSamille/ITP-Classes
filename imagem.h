#ifndef IMAGEM_H
#define IMAGEM_H

#include "pixel.h"

typedef struct Imagem {
	Pixel **pixels;
	int dx;
	int dy;
} Imagem;

void gravarPixel( Pixel color, FILE *fp);
void finalizarImagem( Pixel **imagem , FILE *fp, char nome[], int dx, int dy);
void fundo(Pixel **color, int dx, int dy ,int r, int g,int b);
void bresenham(Ponto p1, Ponto p2, Pixel **color);
Pixel **alocar_matriz (int m, int n);
Pixel **liberar_matriz (int m, int n, Pixel **v);

#endif