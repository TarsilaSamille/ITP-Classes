#ifndef DESENHO_H
#define DESENHO_H

#include "circulo.h"
#include "quadrado.h"
#include "ponto.h"

typedef struct desenho {
	Quadrado q[100];
	Circulo c[100];
	Ponto p[100];
	int num_circ;
	int num_quad;
	int num_pont;
} Desenho;

Desenho criaDesenho();
void insereCirculo(Desenho *d, Circulo c);
void insereQuadrado(Desenho *d, Quadrado q);
void inserePonto(Desenho *d, Ponto p);
int numeroFormas(Desenho d);
float areaTotal(Desenho d);

#endif