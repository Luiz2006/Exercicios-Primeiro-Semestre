/*
Name: lista01atividade03MediaAritmetica
Copyright: MIT License
Author: Luiz Araujo: luizcarlos_bsb2006@hotmail.com
Date: 03/12/20 16:50
Description: algoritmo que calcula a média aritmética de 3 números 
quaisquer fornecidos pelo usuário.
*/
#include<stdio.h>
#define MAX 3

float calcularMedia(float numeros[]);
int main(void){
//	declarações
	int indice;
	float numeros[MAX], media;
	
//	instruções
	puts("INFORME TRES NUMEROS: ");
	for(indice = 0; indice < MAX; indice++){
		scanf("%f", &numeros[indice]);
	}
	media = calcularMedia(numeros);	
	printf("MEDIA: %.3f", media);

	printf("\n\n\nPRESSIONE QUALQUER TECLA PARA ENCERRAR.\n");
	getch();
	return 0;
}

float calcularMedia(float numeros[]){
	float media = 0;
	int indice;
	
	for(indice = 0; indice < MAX; indice++){
		media += numeros[indice];
	}
	media /= MAX;	
	return media;
}








