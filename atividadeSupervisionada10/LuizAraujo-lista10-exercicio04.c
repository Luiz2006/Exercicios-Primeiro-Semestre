#include<stdio.h>
float potencia(float x, int n);

int main(){
	float x, resultado;
	int n;
	
	printf("Informe o valor de x: ");
	scanf("%f", &x);
	printf("Informe o valor de n: ");
	scanf("%i", &n);	
	resultado = potencia(x, n);	
	printf(" = %.2f", resultado);	
	
	printf("\n\n\nPRESSIONE QUALQUER TECLA PARA ENCERRAR.\n");		
	getche();		
	return 0;
}
float potencia(float x, int n){
	int contador;
	float resultado = x;
	
	printf("%.2f ", x);
	for(contador = 1; contador < n; contador++){
		printf("x %.2f", x);
		resultado *= x;
	}
	return resultado;
}
