/*
Name: 
Copyright: MIT License
Author: Luiz Araujo - luizcarlos_bsb2006@hotmail.com
Date: 04/12/20 12:30
Description: algoritmo que lê o nome e 
o sexo de uma pessoa e apresente como saída uma das 
seguintes mensagens: “Ilmo. Sr.”, para o sexo masculino 
ou “Ilma. Sra.” para o sexo feminino, acrescentando o 
nome em seguida. Observe o exemplo de um resultado:
			Ilma Sra. Ana Rita
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct dados{
	char nome[30];
	char sexo;
}pessoa;
int main(void){	
	pessoa pessoa1;
	
	lerValidarNome();
	
	
	
	
	return 0;
}









