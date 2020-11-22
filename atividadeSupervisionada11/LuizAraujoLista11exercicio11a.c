/*
Name: Luiz Araujo
Description: Elabore um algoritmo que armazene o código funcional inteiro e respectivo salário real de todos os funcionários de uma empresa. 
Após a leitura de todos os dados apresente o maior e o menor salário entre todos funcionários da
empresa, usando um subprograma para encontrar o maior e outro para encontrar o menor. 

Por fim, acione uma outra função para calcular a média salarial paga por esta empresa. 
O maior e menor salário deverão ser apresentados por um procedimento acionado pelo algoritmo principal. 
A média salarial deverá ser apresentada por um procedimento acionado pela função que calcula a média.
*/

#include<stdio.h>
#include<stdlib.h>

#define MAX_FUNCIONARIOS 100

int leValidaCodigo(int *cod, int cont);
float leValidaSalario();

int main (void){
//	declarações
	int codigos[MAX_FUNCIONARIOS], contador = 0, indice = 0, funcionarioMenorSalario[MAX_FUNCIONARIOS], funcionarioMaiorSalario[MAX_FUNCIONARIOS];
	float salarios[MAX_FUNCIONARIOS], menorSalario, maiorSalario, mediaSalario;

//	zerar vetores
	for(indice = 0; indice < contador; indice++){
		funcionarioMenorSalario[indice] = 0;
		funcionarioMaiorSalario[indice] = 0;
		codigos[indice] = 0;
		salarios[indice] = 0;
	}


//	instruções
	puts("BALANCO SALARIAL DOS FUNCIONARIOS");
	puts(" (codigo negativo para encerrar)");
	do{

		codigos[contador] = leValidaCodigo(codigos, contador);
		if(codigos[contador] < 0){
			break;
		}
		salarios[contador] = leValidaSalario();
		
		contador++;
	}while(contador < MAX_FUNCIONARIOS);
	
	system("CLS");
	puts("BALANCO SALARIAL DOS FUNCIONARIOS");
	puts(" (codigo negativo para encerrar)");


	menorSalario = salarios[0];
	int indiceMenor = 0;
	for(indice = 0; indice < contador; indice++){
		if(salarios[indice] <= menorSalario){
			menorSalario = salarios[indice];
			funcionarioMenorSalario[indiceMenor] = codigos[indice];			
			indiceMenor++;
		}
	}
	
//	encontrar o maior
	maiorSalario = salarios[0];
	int indiceMaior = 0;
	for(indice = 0; indice < contador; indice++){
		if(salarios[indice] <= maiorSalario){
			maiorSalario = salarios[indice];
			funcionarioMaiorSalario[indiceMaior] = codigos[indice];			
			indiceMaior++;
		}
	}
	
//	função para calcular a média salarial
	for(indice = 0; indice < contador; indice++){
		mediaSalario += salarios[indice];
//		mostraMedia(mediaSalario);
	}
	mediaSalario /= contador;
		
	
	for(indice = 0; indice < contador; indice++){
		//mostrarrrrrrrrrrrrr
		printf("FUNC: %i\n", codigos[indice]);
		printf("SAL: R$ %.2f\n", salarios[indice]);
		printf("indiceMaior: R$ %i\n", indiceMaior);
		printf("indiceMenor: R$ %i\n", indiceMenor);
	}
	
//	maior e menor salário deverão ser apresentados por um procedimento na principal
	printf("\n\nMAIOR SALARIO");
		if(indiceMaior > 1){
			printf("\nCODIGOS: ");
		}else{
			printf("\nCODIGO: ");
		}
		if(indiceMaior == 1){
			printf(" %i",funcionarioMaiorSalario[0]);
		}else{
			for(indice = 0; indice < indiceMaior; indice++){	
				if(indice > 0 && indiceMaior > 1 && (indice != (indiceMaior - 1))){
					printf(",");
				}			
				if(indice == (indiceMaior - 1) && indiceMaior > 1){
					printf(" e");
				}			
				printf(" %i",funcionarioMaiorSalario[indice]);
			}
		}
	printf("\nSALARIO: %.2f", maiorSalario);
	
	
	
	
	
	
	
	
	
	
	printf("\n\nMENOR SALARIO");
		if(indiceMenor > 1){
			printf("\nCODIGOS: ");
		}else{
			printf("\nCODIGO: ");
		}
		if(indiceMenor == 1){
			printf(" %i",funcionarioMenorSalario[0]);
		}else{
			for(indice = 0; indice < indiceMenor; indice++){	
				if(indice > 0 && indiceMenor > 1 && (indice != (indiceMenor - 1))){
					printf(",");
				}			
				if(indice == (indiceMenor - 1) && indiceMenor > 1){
					printf(" e");
				}			
				printf(" %i",funcionarioMenorSalario[indice]);
			}
		}
	printf("\nSALARIO: %.2f", menorSalario);
	
	
	
	
//	A média salarial deverá ser apresentada por um procedimento acionado pela função que calcula a média.
	printf("\n\nMEDIA SALARIAL: %.2f.", mediaSalario);

	
	
	return 0;
}

int leValidaCodigo(int *cod, int cont){
	int ind = 0;
	
	printf("CODIGO: ");
	scanf("%i", &cod[cont]);
	
	if(cont > 0){
		do{
			while(cod[cont] == cod[ind]){
				puts("FUNCIONARIO JA CADASTRADO!");
				printf("INFORME UM NOVO CODIGO:");
				scanf("%i", &cod[cont]);
			}
			ind++;
		}while(cont > 0 && ind < cont);
	}	
	return cod[cont];
}

float leValidaSalario(){
	float salario;
	
	printf("SALARIO: R$ ");
	scanf("%f", &salario);
	
	while(salario <= 0){
		puts("SALARIO INVALIDO!");
		printf("INFORME UM SALARIO VALIDO: R$ ");
		scanf("%f", &salario);
	}	
	return salario;
}



