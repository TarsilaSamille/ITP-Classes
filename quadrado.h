#ifndef QUADRADO_H
#define QUADRADO_H

#include "ponto.h"

typedef struct quadrado {
	Ponto topo;
	int lado;
} Quadrado;

Quadrado defineQuadrado (int lado, Ponto topo);
Quadrado mudaTopo (Quadrado q, Ponto topo);
Quadrado mudaLado (Quadrado q, int lado);
float calculaAreaQuadrado (Quadrado q);
int valorLado (Quadrado q);
Ponto valorTopo (Quadrado q);

#endif