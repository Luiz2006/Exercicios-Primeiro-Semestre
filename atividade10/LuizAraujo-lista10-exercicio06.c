/*
Name: Luiz Araujo
Description: elabore um programa que solicite uma letra do alfabeto ao usu�rio e apresente, a partir desta letra informada, 
todas as demais letras do alfabeto at� o seu final. A apresenta��o destas letras dever� ser feita por uma outra fun��o.
*/

#include<stdio.h>
#include<stdlib.h>

int main(void){
//	declara��es
	char letra;	
	
//	instru��es

	printf("Informe uma letra do alfabeto: ");
	scanf("%c", &letra);

	if((letra >= 'a') &&(letra <= 'z')){
		while(letra <= 'z'){
			printf("[%c] - ", letra);
			letra++;
		}
	}
	
	if((letra >= 'A') && (letra <= 'Z')){
		while(letra <= 'Z'){
			printf("[%c] - ", letra);
			letra++;
		}
	}
}






