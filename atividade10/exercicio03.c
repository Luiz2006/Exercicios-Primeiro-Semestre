/*
Name: Luiz Araujo
Description: Elabore duas fun��es, 
al�m da fun��o principal (main) que 
calcule duas opera��es aritm�ticas consecutivas em tr�s valores e duas opera��es lidas na fun��o principal. 
Na outra fun��o verifique se o resultado das opera��es produzir� um n�mero maior, menor ou igual a zero (0).
*/

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int main(void){
	setlocale(LC_ALL, "Portuguese");
	fflush(stdin);
	int valor[3];
	char operador1;

	printf("Informe tr�s valores: \n");
	scanf("%i%i%i", &valor[0], &valor[1], &valor[2]);
	printf("Informe dois operadores:\n");
	scanf("%c", &operador1);
//	scanf("%c", operador2);
	
	
	
	
}
