Projeto Introdução a Técnicas de Programação - 2019.2

Integrantes: João Victor da Silva Saturnino
	     Társila Samille Santos da Silveira

-----------------
*O que foi feito:
-----------------
	A atividade consiste em um projeto de desenho gráfico, que ao fazer a leitura de um arquivo de texto que contém primitivas preestabelecidas no arquivo de orientação para a produção do projeto, interpreta essas instruções e gera uma imagem no formato PPM - Portable Pixel Map contendo os parâmetros passados pelo arquivo de especificações.
	Foi realizada a modularização do programa, o método de geração da imagem no formato PPM e o método de leitura do arquivo de especificações, que está apto a ler, interpretar e aplicar ao arquivo de imagem as seguintes primitivas: 
	1.image: gera uma imagem com definições estabelecidas no arquivo;
	2.clear: indica qual será a cor de fundo do arquivo, seguindo o padrão RGB;
	3.color: altera a cor atual a ser utilizada no desenho, também utilizando o padrão RGB;	
	4.line: desenha uma linha obedeçendo as cordenadas (x,y) fornecidas;
	5.circle: faz o desenho de um círculo na imagem na posição de cordenadas (x,y) e com raio fornecidos;	
	6.polygon: desenha um polígono com um número de lados fornecido pelo arquivo de especificações, bem como as cordenadas das linha que irão compor estes lados;
	7.save: salva a imagem na pasta do projeto com o nome definido no arquivo de especificações.
 	Como elemento extra, decidimos criar uma primitiva de nome "linear", que tem como objetivo desenhar na imagem, com as cores atuais, os dois eixos do plano cartesiano e desenhar sobre o plano uma função linear (f(x) = a.x) com valores de a e x fornecidos pelo arquivo de especificações.

---------------------
*O que não foi feito:
---------------------
	A primitiva "fill", que tem como objetivo preencher a área que compreende as coordenadas definidas no arquivo de especificações, não foi implementada de maneira correta. Funciona de maneira parcial e não conseguimos detectar o motivo do problema.

---------------------------------------
*O que teria sido feito diferentemente:
---------------------------------------
	Acreditamos que o projeto poderia ter sido concluído com êxito e até mesmo incrementado se tivéssemos procurado mais outras maneiras de realizar as funções necessárias. Talvez a pressa de terminar o projeto no prazo nos fez ficar presos à primeira alternativa de resolução dos nossos problemas, quando deveríamos ter feito uma busca mais profunda por outros métodos.
	Algo que impediu de termos realizado o projeto de maneira mais eficaz foi o fato de possuir computadores com o S.O. Windows em casa, o que dificultou bastante na hora de compilar o código e realizar os testes. Se houvesse a oportunidade de realizar esse projeto novamente, teríamos marcados mais horários de estudo na universidade, que possui os meios de realizar os testes de que necessitávamos, e buscaríamos uma forma de instalar o Linux em nossos computadores pessoais, para facilitar o processo. 
	Também buscaríamos uma maneira mais eficiente de fazer o controle das versões do projeto.

-------------------------
*Como compilar o projeto:
-------------------------
	1.No terminal, entre no diretório em que se encontra este arquivo;
	2. Digite "make";	
	3. Execute o projeto digitando "./main".
	- Para limpar os executáveis, digite "make clean".
	
----------------------------	
*Contribuição de cada aluno:
----------------------------
	Modularização do código - João Victor e Társila
	Leitura do arquivo de especificação - João Victor
	Geração de imagem PPM - João Victor
	Primitiva "clear" - João Victor
	Primitiva "line" - Társila
	Primitiva "color" - Társila
	Primitiva "circle" - Társila
	Primitiva "polygon" - João Victor e Társila
	Primitiva "fill" - Társila
	Primitiva "save" - João Victor
	Extra - João victor e Társila






















