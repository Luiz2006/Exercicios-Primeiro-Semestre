/*
Name: Luiz Araujo
Description: elabore um programa que solicite uma letra do alfabeto ao usuário e apresente, a partir desta letra informada, 
todas as demais letras do alfabeto até o seu final. A apresentação destas letras deverá ser feita por uma outra função.
*/

#include<stdio.h>
#include<stdlib.h>

int main(void){
//	declarações
	char letra;	
	
//	instruções

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






