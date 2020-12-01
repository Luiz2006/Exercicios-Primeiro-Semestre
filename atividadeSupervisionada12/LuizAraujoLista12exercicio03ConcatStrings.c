/*
Name: 
Copyright: MIT License
Author: Luiz Araujo: luizcarlos_bsb2006@hotmail.com
Date: 28/11/20 23:07
Description: Faça um programa que solicite o primeiro e o último nome de 5 pessoas. 
Assim que a pessoa informar os dois nomes, apresente em tela o tamanho de cada um 
deles e se for possível concatene-os em uma única variável fazendo o uso da função 
de concatenação de strings.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_PESSOAS 5	// certo: 5

struct dados{
	char nome[30];
	char sobrenome[30];
//	int idade;
};

struct dados lerValidarNome(struct dados pessoa, int cont);
void tamanhoNome(char nome[], char sobrenome[]);
void concatenarNomes(char nome[], char sobrenome[]);

int main(void){
	int indice, contadorPessoas = 0;
	struct dados pessoas[MAX_PESSOAS];
	
	puts("INFORME");
	do{
		pessoas[contadorPessoas] = lerValidarNome(pessoas[contadorPessoas], contadorPessoas);
		tamanhoNome(pessoas[contadorPessoas].nome, pessoas[contadorPessoas].sobrenome);
		concatenarNomes(pessoas[contadorPessoas].nome, pessoas[contadorPessoas].sobrenome);
		
		contadorPessoas++;
	}while(contadorPessoas < MAX_PESSOAS);
	
	printf("\n\n\nPRESSIONE QUALQUER TECLA PARA ENCERRAR.\n");
	getch();
	return 0;
}

struct dados lerValidarNome(struct dados pessoa, int cont){
	int tamanho;
	char completo[60];

	printf("\n%i%c PESSOA", cont + 1, 166);
	printf("\nPRIMEIRO NOME: ");
	fflush(stdin);
	gets(pessoa.nome);
	while(strlen(pessoa.nome) <= 1){
		printf("Entrada invalida!");			
		printf("\nPRIMEIRO NOME: ");
		fflush(stdin);
		gets(pessoa.nome);
	}
	printf("ULTIMO NOME  : ");
	fflush(stdin);
	gets(pessoa.sobrenome);		
	while(strlen(pessoa.sobrenome) <= 1){
		printf("Entrada invalida!");			
		printf("ULTIMO NOME  : ");
		fflush(stdin);
		gets(pessoa.sobrenome);
	}
	return pessoa;
}

void tamanhoNome(char nome[], char sobrenome[]){
	int tamanho;
	tamanho = strlen(nome);
	printf("\n%s tem %i caracteres.", nome, tamanho);		
	tamanho = strlen(sobrenome);
	printf("\n%s tem %i caracteres.", sobrenome, tamanho);
}

void concatenarNomes(char nome[], char sobrenome[]){
	char completo[60];
	
	strcpy(completo, nome);
	strcat(completo, " ");
	strcat(completo, sobrenome);
	printf("\nNOME COMPLETO: %s\n\n", completo);	
}


