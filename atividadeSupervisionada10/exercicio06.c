/*
Name: Luiz Araujo
Copyright: MIT License
Author: luizcarlos_bsb2006@hotmail.com
Date: 
Description: elabore um programa que solicite uma letra do alfabeto ao usuário e apresente, a partir desta letra informada, 
todas as demais letras do alfabeto até o seu final. A apresentação destas letras deverá ser feita por uma outra função.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
//	declarações
	char alfabeto[26][1]= {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
	char letra[2];	
	int contador, posicao = 0;
	
	
//	instruções

	printf("Informe uma letra do alfabeto: ");
	scanf("%s", letra);

	for(contador = 0; contador <= 25; contador++){
		if(strncmp(alfabeto[contador], letra, 1) == 0){
			posicao = contador + 1;
		}
	}	
	printf("\nLetra: %s", letra);
	printf("\nRestante: %s", alfabeto[posicao]);
	
}

void apresentacao()
