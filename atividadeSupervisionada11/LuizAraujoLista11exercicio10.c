/*
Name: Luiz Araujo
Description: Escrever um algoritmo que solicite e leia letra por letra o nome completo de uma pessoa. 
O caractere sustenido “#” indica o fim do nome. Depois de lê-lo apresente todo o nome informado, sem o #.
*/

#include<stdio.h>
#include<stdlib.h>

#define MAX_NOME 30

int main(void){
	char nome[MAX_NOME];
	int contador = 0, indice;

	puts("INFORME O SEU NOME COMPLETO:");
	do{
//		fflush(stdin);
		nome[contador] = getche();

		if(nome[contador] == '#'){
			break;
		}
		
		contador++;
		if(contador == (MAX_NOME - 1)){
			puts("\nTAMANHO MAXIMO EXCEDIDO!");
			break;
		}
	}while(contador < MAX_NOME);
	
		printf("\n\nSEU NOME COMPLETO:\n");
		
	for(indice = 0; indice < contador; indice++){
		printf("%c", nome[indice]);
		
	}
	
	getch();
	return 0;
}
