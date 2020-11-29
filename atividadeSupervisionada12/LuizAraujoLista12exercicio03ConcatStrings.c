/*
Name: 
Copyright: MIT License
Author: Luiz Araujo: luizcarlos_bsb2006@hotmail.com
Date: 28/11/20 23:07
Description: Faça um programa que solicite o primeiro e o último nome de 5 pessoas. 
Assim que a pessoa informar os dois
nomes, apresente em tela o tamanho de cada um deles e se for possível concatene-os 
em uma única variável
fazendo o uso da função de concatenação de strings.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_PESSOAS 5	// certo: 5

struct pessoa{
	char nome[MAX_PESSOAS][30];
	char sobrenome[MAX_PESSOAS][30]; 
};
struct pessoa lerValidarNome(struct pessoa nomes);
int main(void){
	int indice;
	struct pessoa nomes;
	
	nomes = lerValidarNome(nomes);
	printf("\n\n\nPRESSIONE QUALQUER TECLA PARA ENCERRAR.\n");
	getch();
	return 0;
}

struct pessoa lerValidarNome(struct pessoa nomes){
	int indice, tamanho;
	char completo[60];
	puts("INFORME");
	for(indice = 0; indice < MAX_PESSOAS; indice++){
		printf("\n%i%c PESSOA", indice + 1, 166);
		printf("\nPRIMEIRO NOME: ");
		fflush(stdin);
		gets(nomes.nome[indice]);
		while(strlen(nomes.nome[indice]) <= 1){
			printf("Entrada invalida!");			
			printf("\nPRIMEIRO NOME: ");
			fflush(stdin);
			gets(nomes.nome[indice]);
		}
		printf("ULTIMO NOME  : ");
		fflush(stdin);
		gets(nomes.sobrenome[indice]);		
		while(strlen(nomes.nome[indice]) <= 1){
			printf("Entrada invalida!");			
			printf("ULTIMO NOME  : ");
			fflush(stdin);
			gets(nomes.sobrenome[indice]);
		}
		
//		CONTAR CARACTERES
		tamanho = strlen(nomes.nome[indice]);
		printf("\n%s tem %i caracteres.", nomes.nome[indice], tamanho);		
		tamanho = strlen(nomes.sobrenome[indice]);
		printf("\n%s tem %i caracteres.", nomes.sobrenome[indice], tamanho);
		
		strcpy(completo, nomes.nome[indice]);
		strcat(completo, " ");
		strcat(completo, nomes.sobrenome[indice]);
		printf("\nNOME COMPLETO: %s\n\n", completo);
	}

	return nomes;
}






