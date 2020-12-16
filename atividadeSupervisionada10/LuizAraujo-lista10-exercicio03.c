#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

float calcularOperacoes(int valor[], char operador[]);
void menorMaiorIgual(float res);
char lerValidarOperador();

int main(void){
	setlocale(LC_ALL, "Portuguese");
	int valor[3];
	char operador[2];
	float resultado;

	printf("Informe três valores: \n");
	scanf("%i%i%i", &valor[0], &valor[1], &valor[2]);
	
	printf("Informe um operador:\n");
	operador[0] = lerValidarOperador(); 
	printf("Informe outro operador:\n");
	operador[1] = lerValidarOperador(); 
	
	resultado = calcularOperacoes(valor, operador);
    printf("\n\n%i %c %i %c %i= %.2f", valor[0], operador[0], valor[1], operador[1], valor[2], resultado);
    menorMaiorIgual(resultado);
    
    printf("\n\n\nPRESSIONE QUALQUER TECLA PARA ENCERRAR.\n");		
	getche();
}

char lerValidarOperador(){	
	char op;
	
	fflush(stdin);
	scanf("%c", &op);	
	while((op != '+')&&(op != '-')&&(op != '*')&&(op != '/')){		
		printf("Informe algo como +, -, * ou / :");
		fflush(stdin);
		scanf("%c", &op);
	}
	return op;
}

float calcularOperacoes(int valor[], char operador[]){
	float res;
	switch(operador[0]){
		case '+':
				res = valor[0] + valor[1];
				break;
		case '-':
				res = valor[0] - valor[1];
				break;
		case '*':
				res = valor[0] * valor[1];
				break;
		case '/':
				res = valor[0] / valor[1];
				break;
	}
	switch(operador[1]){
		case '+':
				res += valor[2];
				break;
		case '-':
				res -= valor[2];
				break;
		case '*':
				res *= valor[2];
				break;
		case '/':
				res /= valor[2];
				break;
	}
	return res;
}

void menorMaiorIgual(float res){
	if(res < 0){
		printf("\n\nO valor é menor que zero(0).");
	}else if(res == 0){
		printf("\n\nO valor é igual a zero(0).");
	}else{
		printf("\n\nO valor é maior que zero(0).");
	}
}













