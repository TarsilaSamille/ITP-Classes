#ifndef PONTO_H
#define PONTO_H

typedef struct ponto {
	int x;
	int y;
} Ponto;

Ponto definePonto (int x, int y);
int valorX (Ponto p);
int valorY (Ponto p);
int ehOrigem(Ponto p);

#endif