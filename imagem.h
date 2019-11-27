#ifndef IMAGEM_H
#define IMAGEM_H
#include <stdio.h>
#include <math.h>
#include "ponto.h"
#include "pixel.h"

typedef struct Imagem {
	Pixel **pixels;
	int dx;
	int dy;
} Imagem;

int pitagoras (int x, int y);
void fill(Ponto p,int dx, int dy , Pixel **color, Pixel cor, Pixel background);
void fillY(Ponto p,int dx, int dy , Pixel **color, Pixel **o,  Pixel cor, Pixel background);
void fillX(Ponto p,int dx, int dy , Pixel **color,Pixel **o,  Pixel cor, Pixel background);
void circulo(Ponto p1, int r, Pixel **color, Pixel cor);
void gravarPixel( Pixel color, FILE *fp);
void finalizarImagem( Pixel **imagem , char nome[], int dx, int dy);
void fundo(Pixel **color, int dx, int dy ,Pixel cor);
void bresenham(Ponto p1, Ponto p2, Pixel **color, Pixel cor);
void pcartesianolinha(Ponto p0, int ax,int bx,int dx, int dy , Pixel **color, Pixel cor, Pixel background);
void pcartesiano(Ponto p,int dx, int dy , Pixel **color, Pixel cor, Pixel background);
Pixel **alocar_matriz (int m, int n);
Pixel **liberar_matriz (int m, int n, Pixel **v);

#endif