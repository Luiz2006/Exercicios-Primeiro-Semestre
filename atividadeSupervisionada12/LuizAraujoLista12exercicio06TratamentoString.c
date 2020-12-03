/*
Name: LuizAraujoLista12exercicio06TratamentoString
Copyright: MIT License
Author: Luiz Araujo: luizcarlos_bsb2006@hotmail.com
Date:03/12/20 10:16
Description: Elabore um programa que armazene o nome completo de uma pessoa com 
até 30 caracteres e o apresente em letras maiúsculas centralizado em uma janela limpa. 
Na primeira coluna da linha 20 apresente quantos caracteres possui este nome e 
na linha 23 pergunte se o usuário quer informar outro nome. Caso deseje repita 
o processo até que o usuário não deseje mais ler nenhum nome e saia do programa 
IMEDIATAMENTE (sem pressionar qualquer tecla).
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.c>

#define MAX_CHARS 30

int main(void){
//	declaração
	char nome[MAX_CHARS],nomeAux[MAX_CHARS], continuar;
	int tamanho = 0, indice;
//	instruções
	do{
		puts("INFORME O NOME COMPLETO:");
		fflush(stdin);
		gets(nomeAux);
		
		for(indice = 0; indice < MAX_CHARS; indice++){	//porque estava ultrapassando os 30 chars
			nome[indice] = nomeAux[indice];
			
		}
		
		system("CLS");
		strupr(nome);
		gotoxy(40,1);
		printf("%s", nome);
	
		gotoxy(1,20);	
		tamanho = strlen(nome);
		printf("Quantidade de caracteres: %i", tamanho);
		
		gotoxy(1,23);
		puts("Deseja informar outro nome? [s - para sim]");
		continuar = getch();
		continuar = tolower(continuar);
		system("CLS");
	}while(continuar == 's');
	return 0;
}







