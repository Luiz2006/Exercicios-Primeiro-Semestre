#include<stdio.h>
int main(void){
	int valor, controle = 2, fatorial = 1;
	
	printf("INFORME UM NUMERO:");
	scanf("%i", &valor);
	
	printf("\n%i!: 1 ", valor);
	while(controle <= valor){
		fatorial *= controle; 
		printf("x %i ", controle);
		controle++;
	}
	printf("= %i", fatorial);
	
	printf("\n\n\nPRESSIONE QUALQUER TECLA PARA ENCERRAR.\n");
	getche();
	return 0;
}

