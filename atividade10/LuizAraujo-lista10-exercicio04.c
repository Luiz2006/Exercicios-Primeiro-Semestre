/*
Name: Luiz Araujo
Date: 16/11/20 22:40
Description: calcula, por meio de uma função, o valor de x (real) elevado a n(inteiro) usando apenas a operação de multiplicação.
*/

#include<locale.h>
void potencia(float x, int n);

int main(){
	setlocale(LC_ALL, "Portuguese");
	float x;
	int n;
	
	printf("Informe o valor de x: ");
	scanf("%f", &x);
	printf("Informe o valor de n: ");
	scanf("%i", &n);
	
	potencia(x, n);	
	return 0;
}

void potencia(float x, int n){
	int contador;
	float resultado = x;
	printf("%.2f ", x);
	for(contador = 1; contador < n; contador++){
		printf("x %.2f", x);
		resultado *= x;
	}
	printf(" = %.2f.", resultado);
}
