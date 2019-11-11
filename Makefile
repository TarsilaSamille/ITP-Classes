all: main

main: ponto.o circulo.o quadrado.o desenho.o pixel.o primitiva.o imagem.o main.c
	gcc main.c -o main ponto.o circulo.o quadrado.o pixel.o desenho.o primitiva.o imagem.o -lm

desenho.o: desenho.c
	gcc -c desenho.c

circulo.o: circulo.c
	gcc -c circulo.c

quadrado.o: quadrado.c
	gcc -c quadrado.c

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