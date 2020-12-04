/*
Name: Alocacao Dinamica 00
Copyright: MIT License
Author: Luiz Araujo - luizcarlos_bsb2006@hotmail.com
Date: 04/12/20 08:12
Description: Intro
-> malloc
-> calloc
-> realloc
-> free
=> sizeof
*/

#include<stdio.h>
#include<stdlib.h>


int main(void){
	int x;
	double y;
	int num[100];
	float num1[100];
	double num2[100];
	int num3[100][100];
	
	char nome[100];
	char nome2[] = "Luiz";
	
	struct estrutura{
		int a;
		int b;
		int c;
	};
	struct estrutura structure;
	printf("%li", sizeof(structure));
	
	printf("\n\n\nPRESSIONE QUALQUER TECLA PARA ENCERRAR.\n");
	getch();
	return 0;
}
