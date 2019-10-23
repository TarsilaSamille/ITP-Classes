#include "quadrado.h"

Quadrado defineQuadrado (int lado, Ponto topo) {
	Quadrado q;
	q.lado = lado;
	q.topo = topo;
	return q;
}

Quadrado mudaTopo (Quadrado q, Ponto topo) {
	Quadrado novo_q;
	novo_q.lado = q.lado;
	novo_q.topo = topo;
	return novo_q;
}

Quadrado mudaLado (Quadrado q, int lado) {
	Quadrado novo_q;
	novo_q.lado = lado;
	novo_q.topo = q.topo;
	return novo_q;
}

float calculaAreaQuadrado (Quadrado q) {
	return q.lado*q.lado;
}

int valorLado (Quadrado q) {
	return q.lado;
}

Ponto valorTopo (Quadrado q) {
	return q.topo;
}
