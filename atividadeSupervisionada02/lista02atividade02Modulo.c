/*
Name: lista02atividade02Modulo
Copyright: MIT License
Author: Luiz Araujo - luizcarlos_bsb2006@hotmail.com
Date: 03/12/20 21:35
Description: Efetuar a leitura de um número e apresentá-lo como o seu módulo 
(somente seu valor absoluto) elaborando os cálculos matemáticos para isso.
*/
#include<stdio.h>

int main(void){
	int numero, modulo, contador = 0;
	
	printf("INFORME UM NUMERO: ");
	scanf("%d", &numero);
	
//	poderia fazer assim:
//	if(numero < 0){
//		contador = numero * (-1);
//	}
	
	if(numero == 0){
		printf("MODULO: 0");
	}else{
		if(numero < 0){
			while(numero < 0){
				numero++;
				contador++;
			}
		}
		if(numero > 0){
			while(numero > 0){
				numero--;
				contador++;
			}
		}
		printf("MODULO: %i", contador);
	}
	
	printf("\n\n\nPRESSIONE QUALQUER TECLA PARA ENCERRAR.\n");
	getch();
	return 0;
}

