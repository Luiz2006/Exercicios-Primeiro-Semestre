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

//	for(indice = 0; indice < MAX_FUNCIONARIOS; indice++){
//		// zerar vetores
//		codigos[MAX_FUNCIONARIOS] = 0;
//		funcionarioMenorSalario[MAX_FUNCIONARIOS] = 0;
//		funcionarioMaiorSalario[MAX_FUNCIONARIOS] = 0;
//		salarios[MAX_FUNCIONARIOS] = 0;
//	}



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

//	encontrar o maior
	maiorSalario = salarios[0];
	int indiceMaior = 0;
	for(indice = (contador - 1); indice >= 0; indice--){ //passei quase 2h pra pensar nessa soluçõa kkkk' antes de decrementar o loop, ficava  contando com o primeiro elemento...
		if(salarios[indice] >= maiorSalario){
			maiorSalario = salarios[indice];
			funcionarioMaiorSalario[indiceMaior] = codigos[indice];			
			indiceMaior++;
		}
	}

	menorSalario = salarios[0];
	int indiceMenor = 0;
	for(indice = 0; indice < contador; indice++){
		if(salarios[indice] <= menorSalario){
			menorSalario = salarios[indice];
			funcionarioMenorSalario[indiceMenor] = codigos[indice];			
			indiceMenor++;
		}
	}
	
	
		
	
	
//	maior e menor salário deverão ser apresentados por um procedimento na principal
	printf("\n\nMAIOR SALARIO");
	if(indiceMaior == 1){
		printf("\nCODIGO: %i",funcionarioMaiorSalario[0]);
	}else{	
		printf("\nCODIGOS:");
		for(indice = 0; indice < indiceMaior; indice++){
			if(indice > 0 && indice < indiceMaior - 1){
				printf(",");
			}
			if(indice == indiceMaior - 1){
				printf("e");
			}
			printf(" %i",funcionarioMaiorSalario[indice]);
		}
	}	
	printf(".\nSALARIO: %.2f", maiorSalario);
	
	
	
	
	printf("\n\nMENOR SALARIO");
	if(indiceMenor == 1){
		printf("\nCODIGO: %i",funcionarioMenorSalario[0]);
	}else{	
		printf("\nCODIGOS:");
		for(indice = 0; indice < indiceMenor; indice++){
			if(indice > 0 && indice < indiceMenor - 1){
				printf(",");
			}
			if(indice == indiceMenor - 1){
				printf(" e");
			}
			printf(" %i",funcionarioMenorSalario[indice]);
		}
	}	
	printf(".\nSALARIO: %.2f", menorSalario);
	
	
	
	
//	A média salarial deverá ser apresentada por um procedimento acionado pela função que calcula a média.
	printf("\n\nMEDIA SALARIAL: %.2f.", mediaSalario);

	
//	for(indice = 0; indice < contador; indice++){
//		
//		printf("FUNC: %i\n", codigos[indice]);
//		printf("SAL: R$ %.2f\n", salarios[indice]);
//	}
	
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







//	função para calcular a média salarial
	for(indice = 0; indice < contador; indice++){
		mediaSalario += salarios[indice];
		mostraMedia(mediaSalario);
	}
	mediaSalario /= contador;





