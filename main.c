#include "pixel.h"
#include "ponto.h"
#include "primitiva.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(int argc, char **argv){
    FILE *especificacao=NULL;

    Pixel **imagem;
    //Abertura do arquivo de especificação
    especificacao = fopen("especificacao.txt", "r");
    lerArquivoExp( especificacao ,imagem);

    /* Sucesso */
    return EXIT_SUCCESS;
}
