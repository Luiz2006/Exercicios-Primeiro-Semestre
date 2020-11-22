/*
Name: Luiz Araujo
Description: Elabore duas funções,
além da função principal (main) que
calcule duas operações aritméticas consecutivas em três valores e duas operações lidas na função principal.
Na outra função verifique se o resultado das operações produzirá um número maior, menor ou igual a zero (0).
*/

#include<stdio.h>
//#include<stdlib.h>
//#include<locale.h>

int main(void){
//	setlocale(LC_ALL, "Portuguese");

	//int valor[3];
	char operador1, operador2;

	//printf("Informe três valores: \n");
//	scanf("%i%i%i", &valor[0], &valor[1], &valor[2]);
	printf("Informe um operador:\n");
	scanf("%c", &operador1);
	fflush(stdin);
	printf("Informe outro operador:\n");
	scanf("%c", &operador2);
    printf("%c e %c", operador1, operador2);

}
