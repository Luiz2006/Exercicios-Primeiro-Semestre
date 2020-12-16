/*
Name: Alocacao Dinamica 03 Calloc
Copyright: MIT License
Author: Luiz Araujo - luizcarlos_bsb2006@hotmail.com
Date: 
Description: 03 Calloc
-> malloc	= aloca, reserva, separa espaço na mem, recebe tamanho em byts;
-> calloc	= faz o mesmo que malloc, mas recebe um outro parâmetro antes, num inteiro positivos que fala qtas vezes vai ser alocado o tamanho do parâmetro seguinte;
	obs.: calloc inicializa todo o bloco de mem. com 0, o malloc não!!!
	obs2.: pra fazer o segundo parâmetro no malloc teria que multiplicar.
-> realloc	= 
-> free		= devolve, desaloca o espaço da mem. antes do progrma terminar(sempre que termina, desaloca auto);
	obs.: Sempre desalocar quando não estiver usando as variáveis
-> sizeof	= operar, retorna tamanho de
*/

#include<stdio.h>
#include<stdlib.h>

int main(void){
	int *p, indice;
	p = (int *) calloc(5, sizeof(int));	//aloca 20 bytes, zerados| 5 partes/membros de 4 bytes
//	p = (int *) malloc(5 * sizeof(int));//aloca 20 bytes, com lixo de mem
	
	///membros - todo poonteiro é vetor
//	*(p+1) = 10;
//	p[3] = 20;

	
	printf("%i", *p);
	printf("\n%i", *(p+1));
	printf("\n%i", *(p+2));
	printf("\n%i", *(p+3));
	printf("\n%i", *(p+4));
	
	
	printf("\n\n\n");
	
	for(indice = 0; indice < 5; indice++){
		printf("%i\n", p[indice]);
	}	
	
	printf("\n\n\n");
	
	for(indice = 0; indice < 5; indice++){
//		printf("\nEndereco de p%i = %p | Valor de p%i = %i", indice, (p+1), indice, *(p+1));
		printf("\nEndereco de p%i = %p | Valor de p%i = %i", indice, &p[indice], indice, *(p+1));
	}
	
	printf("\n\n\nPRESSIONE QUALQUER TECLA PARA ENCERRAR.\n");
	getch();
	return 0;
}
