#include "ponto.h"
#include <stdio.h>

Ponto definePonto (int x, int y) {
	Ponto p;
	p.x = x;
	p.y = y;
	return p;
}

int valorX (Ponto p) {
	return p.x;
}

int valorY (Ponto p) {
	return p.y;
}

int ehOrigem(Ponto p) {
	if (p.x == 0 && p.y == 0) return 1;
	else return 0;
}
