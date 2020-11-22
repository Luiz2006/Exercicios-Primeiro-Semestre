/*
Name: Luiz Araujo
Description: algoritmo/programa que lê a matricula e o salário dos funcionários 
		   e informa os dados lidos, o maior e o menor salário dos funcionários.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_FUNC 3

float calcularMaiorSalario(float maiorSalario, float salario);
float calcularMenorSalario(float menorSalario, float salario);
void validarMatricula(int *matricula, int contadorFuncionario);
float validarSalario(float salario);

int main(void){
	int contadorFuncionario = 0, contador;
	int matricula[MAX_FUNC];
	float salario[MAX_FUNC], maiorSalario, menorSalario;
	
	printf("   SALARIO DOS FUNCIONARIOS\n");
	printf("(matricula negativa para finalizar)\n");
	
	while(matricula[contadorFuncionario] >= 0){
		if(contadorFuncionario >= MAX_FUNC){
			matricula[contadorFuncionario] = 0;
		}else{
			printf("\n%i%c FUNCIONARIO ", (contadorFuncionario + 1), 167);
			printf("\nMATRICULA: ");
			scanf("%i", &matricula[contadorFuncionario]);
			validarMatricula(&matricula, contadorFuncionario);
					
			if(matricula[contadorFuncionario] >= 0){			
				printf("SALARIO: ");
				scanf("%f", &salario[contadorFuncionario]);	
				salario[contadorFuncionario] = validarSalario(salario[contadorFuncionario]);		
			}
		
			contadorFuncionario++;		
		}
	}	//fim while
	
	system("CLS");	
	printf("%-30s \n", "LISTA DE FUNCIONARIOS");	
	printf("\n");
	printf("%-15s%-18s\n", "MATRICULA", "SALARIO");
	for(contador = 0; contador < contadorFuncionario; contador++){ 
		if(contador == 0){
			maiorSalario = salario[0];
			menorSalario = salario[0];
		}
		printf("%-14i R$ %-15.2f\n", matricula[contador], salario[contador]);	
						
		maiorSalario = calcularMaiorSalario(maiorSalario, salario[contador]);
		menorSalario = calcularMenorSalario(menorSalario, salario[contador]);			
		
	}	//fim for
	
	printf("\n");
	printf("MAIOR SALARIO: R$ %-12.2f \n",maiorSalario);	
	printf("MENOR SALARIO: R$ %-12.2f \n",menorSalario);	
		
	return 0;
}	//fim main

void validarMatricula(int *matricula, int contadorFuncionario){
	int contador;
	for(contador = (contadorFuncionario - 1); contador >= 0; contador--){
		while(matricula[contador] == matricula[contadorFuncionario]){
			if(contador!=contadorFuncionario){				
				printf("MATRICULA JA CADASTRADA: ");
				scanf("%i", &matricula[contadorFuncionario]);	
			}		
		}			
	}
}
float validarSalario(float salario){
	while(salario <= 0){
		printf("O salário não pode ser 0:");
		scanf("%f", &salario);
	}
	return salario;
}
float calcularMaiorSalario(float maiorSalario, float salario){	
	if(maiorSalario < salario){
		 maiorSalario = salario;
	}	
	return maiorSalario;
}	
float calcularMenorSalario(float menorSalario, float salario){
	if(menorSalario > salario){
		 menorSalario = salario;
	}	
	return menorSalario;
}



