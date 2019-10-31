all: main

main: ponto.o circulo.o quadrado.o desenho.o main.c
	gcc main.c -o main ponto.o circulo.o quadrado.o desenho.o

desenho.o: desenho.c
	gcc -c desenho.c

circulo.o: circulo.c
	gcc -c circulo.c

quadrado.o: quadrado.c
	gcc -c quadrado.c

ponto.o: ponto.c
	gcc -c ponto.c
	
clean:
	rm -f *.o