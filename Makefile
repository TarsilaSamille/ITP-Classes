all: main

main: ponto.o pixel.o primitiva.o imagem.o main.c
	gcc main.c -o main ponto.o pixel.o primitiva.o imagem.o -lm

ponto.o: ponto.c
	gcc -c ponto.c

pixel.o: pixel.c
	gcc -c pixel.c

primitiva.o: primitiva.c
	gcc -c primitiva.c
	
imagem.o: imagem.c
	gcc -c imagem.c 

clean:
	rm -f *.o