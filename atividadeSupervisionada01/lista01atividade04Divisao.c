/*
Name: lista01atividade04Divisao
Copyright: MIT License
Author: Luiz Araujo - luizcarlos_bsb2006@hotmail.com
Date:03/12/20 17:40
Description: algoritmo que a partir da leitura de dois n�meros 
fornece o resto e o quociente da divis�o do primeiro pelo segundo n�mero.
*/
#include<stdio.h>
#include<stdlib.h>

int main(void){
//	declara��es
	int numeros[2], quociente, resto;

//	instru��es
	puts("FORNECA DOIS NUMEROS:");
	scanf("%d", &numeros[0]);
	scanf("%d", &numeros[1]);
	
	resto = numeros[0] % numeros[1];
	quociente = (int)(numeros[0] / numeros[1]);
	
	printf("\nQUOCIENTE: %d", quociente);
	printf("\nRESTO    : %d", resto);
	
	
	printf("\n\n\nPRESSIONE QUALQUER TECLA PARA ENCERRAR.\n");
	getch();
	return 0;
}
