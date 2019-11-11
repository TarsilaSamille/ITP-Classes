#include "primitiva.h"
#include "imagem.h"
#include "ponto.h"
#include "pixel.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// void abreArquivoExp(FILE *fp, char *nome){
//fp = fopen(nome, "r");
// }

void lerArquivoExp(FILE *especificacao, Pixel **imagem){
    char primitiva[100];
    //image
    char dx[4] ="";
    char dy[4] ="";
    //clear
    char r[3] = ""; 
    char g[3] = ""; 
    char b[3] = "";

    Ponto p ,p1,p2; 

    Pixel cor, background;
    int intr, intg, intb, dimx, dimy, x1 ,y2,x2 ,y1,x,y,i, vertices, raio;
    //save
    char nomeArquivo[15] = "";
    while(strcmp(primitiva, "save") != 0){
        fscanf(especificacao, "%s", primitiva);
        if(strcmp(primitiva, "image") == 0){
            fscanf(especificacao,"%s %s\n",dx, dy);
            dimx = atoi(dx);
            dimy = atoi(dy);
            imagem = alocar_matriz(dimx, dimy);            
        }else if(strcmp(primitiva, "clear") == 0){
            fscanf(especificacao, "%d %d %d\n", &intr, &intg, &intb);
            background = colorir(intr, intg, intb);
            fundo(imagem, dimx, dimy, background);
         }else if(strcmp(primitiva, "color") == 0){
            fscanf(especificacao, "%d %d %d\n", &intr, &intg, &intb);
            cor = colorir(intr, intg, intb);
        }else if(strcmp(primitiva, "line") == 0){
            fscanf(especificacao, "%d %d %d %d\n", &x1, &y1,&x2, &y2);
            p1= definePonto(x1,y1);
            p2= definePonto(x2,y2);
            bresenham(p2 , p1, imagem,cor);
        }else if(strcmp(primitiva, "polygon") == 0){
            fscanf(especificacao, "%d", &vertices);
            Ponto pontos[vertices]; 
            for(i = 0 ; i < vertices ; i++ ){
                fscanf(especificacao, "%d %d", &x1, &y1);
                pontos[i]= definePonto(x1,y1);
                if(i > 0)  bresenham(pontos[i] , pontos[i-1], imagem,cor);
                if(i < vertices) bresenham(pontos[i] , pontos[0], imagem,cor);
            }
            fscanf(especificacao, "\n");            
        }else if(strcmp(primitiva, "circle") == 0){
            fscanf(especificacao, "%d %d %d\n", &x1, &y1,&raio);
            p= definePonto(x1,y1);
            circulo(p, raio, imagem,cor);
        }else if(strcmp(primitiva, "fill") == 0){
            fscanf(especificacao, "%d %d\n", &x1, &y1);
            p= definePonto(x1,y1);
            imagem[x1][y1] = colorir(cor.r, cor.g, cor.b);  
            fill(p, dimx, dimy, imagem, cor, background);      
        }else if(strcmp(primitiva, "save") == 0){
            fscanf(especificacao, "%s\n", nomeArquivo);
            finalizarImagem(imagem, nomeArquivo, dimx, dimy);
        }
    }
}