/*
Name: Conjectura de COLLATZ
Copyright: MIT License
Author: Luiz Araujo - luizcarlos_bsb2006@hotmail.com
Date:05/12/20 11:46
Description: Demonstração da Conjectura de Collatz
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void conjecturaCollatz(int n);
int main(void){
	int numero; 
	do{
		printf("INFORME UM NUMERO INTEIRO: ");
		printf("\n   (0 ou menos encerra)\n\t");
		scanf("%d", &numero);
		if(numero <= 0){
			break;
		}
		conjecturaCollatz(numero);
		
		printf("\n\n\n");
	}while(numero > 0);
	
	printf("\n\n\nPRESSIONE QUALQUER TECLA PARA ENCERRAR.\n");
	getch();
	return 0;
}

void conjecturaCollatz(int n){
	int contador = 1, cont = 1;
	do{
		if(n % 2 == 0){
			printf("\n%5d%5d e par   ->   %5d%/2= %5d", cont, n, n, (n / 2));
			n /= 2;
		}else{
			printf("\n%5d%5d e impar -> %5dx3+1= %5d", cont, n, n, (n * 3 + 1));
			n = n * 3 + 1;		
		}
		
		if(n == 1){
			break;
			contador++;
		}
		cont++;
	}while(contador <= 3);
	
}







