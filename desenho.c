#include "desenho.h"

Desenho criaDesenho() {
	Desenho d;
	d.num_circ = 0;
	d.num_quad = 0;
	d.num_pont = 0;
	return d;
}

void insereCirculo(Desenho *d, Circulo c) {
	int i = (*d).num_circ;
	(*d).c[i] = c;
	(*d).num_circ++;
	return;
}

void insereQuadrado(Desenho *d, Quadrado q) {
	int i = (*d).num_quad;
	(*d).q[i] = q;
	(*d).num_quad++;
	return;
}

void inserePonto(Desenho *d, Ponto p) {
	int i = (*d).num_pont;
	(*d).p[i] = p;
	(*d).num_pont++;
	return;
}

int numeroFormas(Desenho d) {
	return d.num_quad + d.num_circ + d.num_pont;
}

float areaTotal(Desenho d) {
	int area = 0;
	for (int i = 0; i < d.num_circ; i++)
		area += calculaAreaCirculo(d.c[i]);
	for (int i = 0; i < d.num_quad; i++)
		area += calculaAreaQuadrado(d.q[i]);
	return area;
}
