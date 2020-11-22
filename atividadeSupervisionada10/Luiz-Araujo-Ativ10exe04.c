#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

float calcularPotencia(float x, int n);

main(){
	setlocale(LC_ALL,"Portuguese");
	
	//declarações
	float x, resultado = 1;
	int n;	
	
	//instruções
	printf("Informe um valor real: ");
	scanf("%f", &x);
	printf("Informe um valor inteiro: ");
	scanf("%i", &n);
	
	resultado = calcularPotencia(x, n);
	
	
	printf("\nO valor %.2f elevado a %i é igual a %.2f.", x, n, resultado);
	return 0;
}

float calcularPotencia(float x, int n){	
	int contador;
	float res = 1;
	for(contador = 1; contador <= n; contador++){
		res = res * x;
	}
	return res;
}
