#ifndef IMAGEM_H
#define IMAGEM_H
#include <stdio.h>
#include "ponto.h"
#include "pixel.h"

typedef struct Imagem {
	Pixel **pixels;
	int dx;
	int dy;
} Imagem;

void circulo(Ponto p1, int r, Pixel **color, Pixel cor);
void gravarPixel( Pixel color, FILE *fp);
void finalizarImagem( Pixel **imagem , char nome[], int dx, int dy);
void fundo(Pixel **color, int dx, int dy ,int r, int g,int b);
void bresenham(Ponto p1, Ponto p2, Pixel **color, Pixel cor);
Pixel **alocar_matriz (int m, int n);
Pixel **liberar_matriz (int m, int n, Pixel **v);

#endif