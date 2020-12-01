/*
Name: 
Copyright: MIT License
Author: Luiz Araujo: luizcarlos_bsb2006@hotmail.com
Date: 30/11/20 16:47
Description: A identificação dos nomes de passageiros nas companhias de transporte aéreo são descritas obedecendo uma padronização, 
onde se deve primeiro escrever o último sobrenome e em seguida o primeiro nome, separando ambos por uma barra ‘/’. 
Por exemplo: Edson Arantes do Nascimento teria o seu nome escrito na passagem como: Nascimento/Edson. 
Faça um programa que leia um nome e apresente-o na formatação dos transportes aéreos.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
	char nome[100];
	int indice, tamanho, contadorEspacos = 0, controleEspacos = 0;
	
	puts("INFORME O NOME COMPLETO:");
	fflush(stdin);
	gets(nome);
	tamanho = strlen(nome);
	for(indice = 0; indice < tamanho; indice++){
		if(strcmp(nome[indice], " ") == 0){
			contadorEspacos++;
		}
	}
	do{
		if(strcmp(nome[indice], " ") == 0){	
			if(indice == (contadorEspacos - 1)){
				controleEspacos = indice;	
			}
		}
						
			indice++;
	}while(indice < contadorEspacos);
	printf("\n\n");
	for(indice = controleEspacos; indice < tamanho; indice++){
		printf("%c", nome[indice]);
	}
	printf("\n\n\nPRESSIONE QUALQUER TECLA PARA ENCERRAR.\n");
	getch();
	return 0;
}








