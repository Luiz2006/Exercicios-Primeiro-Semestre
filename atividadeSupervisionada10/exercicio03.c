/*
Name: Luiz Araujo
Description: Elabore duas fun��es,
al�m da fun��o principal (main) que
calcule duas opera��es aritm�ticas consecutivas em tr�s valores e duas opera��es lidas na fun��o principal.
Na outra fun��o verifique se o resultado das opera��es produzir� um n�mero maior, menor ou igual a zero (0).
*/

#include<stdio.h>
//#include<stdlib.h>
//#include<locale.h>

int main(void){
//	setlocale(LC_ALL, "Portuguese");

	//int valor[3];
	char operador1, operador2;

	//printf("Informe tr�s valores: \n");
//	scanf("%i%i%i", &valor[0], &valor[1], &valor[2]);
	printf("Informe um operador:\n");
	scanf("%c", &operador1);
	fflush(stdin);
	printf("Informe outro operador:\n");
	scanf("%c", &operador2);
    printf("%c e %c", operador1, operador2);

}
