/*
Name: Alocacao Dinamica 02 Free
Copyright: MIT License
Author: Luiz Araujo - luizcarlos_bsb2006@hotmail.com
Date: 
Description: 02 Free
-> malloc	= aloca, reserva, separa espa�o na mem;
-> calloc	=
-> realloc	=
-> free		= devolve, desaloca o espa�o da mem. antes do progrma terminar(sempre que termina, desaloca auto);
	obs.: Sempre desalocar quando n�o estiver usando as vari�veis
-> sizeof	= operar, retorna tamanho de
*/

#include<stdio.h>
#include<stdlib.h>

int main(void){
	int *p = (int *) malloc(sizeof(int));
	
	*p = 1000;
	
	free(p);
	
	printf("%i", *p);
	
//	free(p);
	
	
//	int *m = (int *) malloc(sizeof(int));
	
	
	printf("\n\n\nPRESSIONE QUALQUER TECLA PARA ENCERRAR.\n");
	getch();
	return 0;
}
