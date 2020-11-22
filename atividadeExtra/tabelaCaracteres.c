/*
Name: Luiz Araujo
Copyright: MIT License
Author: luizcarlos_bsb2006@hotmail.com
Date: 19/11/20 12:31
Description: apresentar a diferença entre incremento de letras e os caracteres ASC.
*/
#include<stdio.h>
#define LIMITE 257

int main (void){
	int contador;
	char caracter = 'A';
	for(contador = 1; contador <= LIMITE; contador++){			
		if((contador % 5) == 0){
			printf("%3i: %3c\n", contador, caracter);	
		}else{	
			printf("%3i: %3c\t", contador, caracter);		
			
		}
		caracter++;
	}
	
	printf("\n\n");
	printf("\n\n");
//	mostra o caracter na tabela de cima
//	printf("%4i: %-5c-%-5c\n", 166, (caracter*166), 166);
	

	for(contador = 1; contador <= LIMITE; contador++){			
		if((contador % 5) == 0){
			printf("%3i: %3c\n", contador, contador);	
		}else{	
			printf("%3i: %3c\t", contador, contador);		
			
		}
		caracter++;
	}
	printf("\n\n");
	system("Pause");
	return 0;
}

