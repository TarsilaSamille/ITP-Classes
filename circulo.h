#ifndef CIRCULO_H
#define CIRCULO_H

#include "ponto.h"

typedef struct circulo {
	Ponto centro;
	int raio;
} Circulo;

Circulo defineCirculo (int raio, Ponto centro);
Circulo mudaCentro (Circulo c, Ponto centro);
Circulo mudaRaio (Circulo c, int raio);
float calculaAreaCirculo (Circulo c);
int valorRaio (Circulo c);
Ponto valorCentro (Circulo c);

#endif