/*
Name: Luiz Araujo
Description: algoritmo que calcula e escreve o somat�rio dos valores armazenados numa vari�vel 
		composta unidimensional, chamada dados, de at� 100 elementos num�ricos a serem lidos.
*/

#include<stdio.h>

#define LIMITE 100 //certo: 100

int main(void){
//	declara��es
	long int dados[LIMITE], somatorio = 0;
	int contador, contador2;
	
//	intru��es
	printf(" 0 PARA FINALIZAR\n\n");
	
	do{
		printf("%2i%c Numero: ", contador, 167);
		scanf("%i", &dados[contador]);
				
		somatorio = somatorio+ dados[contador];
		contador++;
	}while((dados[contador-1] != 0) && (contador <= 10));
	
	printf("\nSomatorio: %i", dados[1] );
	for(contador2 = 2; contador2 < contador; contador2++){
		printf(" + %i", dados[contador2]);
	}
	printf(" = %i", somatorio);
		
	return 0;
}
