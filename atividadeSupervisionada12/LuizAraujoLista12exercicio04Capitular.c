/*
Name: 
Copyright: MIT License
Author: Luiz Araujo: luizcarlos_bsb2006@hotmail.com
Date:
Description: Elabore um programa que faça o armazenamento de um texto. 
Em uma janela limpa o texto deverá ser apresentada com todas as palavras 
tendo a sua primeira letra em maiúscula e o restante das letras em minúsculo. 
,Após a apresentação de todo o texto centralize a linha na horizontal e 
escreva que este texto possui tantas palavras.
*/

#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
#include<ctype.h>

#define MAX_LETRAS 1000
void lerValidarTexto(char texto[]);
void capitular(char texto[]);

int main(void){
	char texto[MAX_LETRAS];
	
	lerValidarTexto(texto);
	capitular(texto);
	
	printf("\n\n\nPRESSIONE QUALQUER TECLA PARA ENCERRAR.\n");
	getch();
	return 0;
}


void lerValidarTexto(char texto[]){
	puts("INFORME UM TEXTO: ");
	fflush(stdin);
	gets(texto);
	while(strlen(texto) <= 5){
		puts("Informe um texto maior!");
		fflush(stdin);
		gets(texto);
	}
}

void capitular(char texto[]){
	int indice, tamanho;
	char charAtual[MAX_LETRAS];
	texto = strlwr(texto);		
	tamanho = strlen(texto);
	
	for(indice = 0; indice < tamanho; indice++){
		charAtual[indice] = texto[indice];
	}

	system("CLS");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	charAtual[0] = toupper(charAtual[0]);	
	for(indice = 0; indice < tamanho; indice++){
		if((charAtual[indice] == ' ')||(charAtual[indice] == '-')||(charAtual[indice] == '(')||(charAtual[indice] == ')')){
			charAtual[indice + 1] = toupper(charAtual[indice + 1]);
		}
		printf("%c", charAtual[indice]);
	}
	printf("\nEsse texto possui %i palavras.", tamanho);
}



















