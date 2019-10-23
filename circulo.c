#include "circulo.h"

Circulo defineCirculo (int raio, Ponto centro) {
	Circulo c;
	c.centro = centro;
	c.raio = raio;
	return c;
}

Circulo mudaCentro (Circulo c, Ponto centro) {
	Circulo novo_c;
	novo_c.centro = centro;
	novo_c.raio = c.raio;
	return novo_c;
}

Circulo mudaRaio (Circulo c, int raio) {
	Circulo novo_c;
	novo_c.centro = c.centro;
	novo_c.raio = raio;
	return novo_c;
}

float calculaAreaCirculo (Circulo c) {
	return 3.1415*c.raio*c.raio;
}

int valorRaio (Circulo c) {
	return c.raio;
}

Ponto valorCentro (Circulo c) {
	return c.centro;
}

