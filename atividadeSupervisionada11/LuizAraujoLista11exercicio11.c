#include<stdio.h>
#include<stdlib.h>

#define MAX_FUNCIONARIOS 10

float lerValidarSalario();
int lerValidarCodigo(int cod[], int cont);
void apresentarMedia(float mediaSalario);
float calcularMedia(int contador, float mediaSalario, float salarios[]);
float encontrarMaiorSalario(int contador, float salarios[], int codigos[], int funcionarioMaiorSalario[], int *indiceMaior);
float encontrarMenorSalario(int contador, float salarios[], int codigos[], int funcionarioMenorSalario[], int *indiceMenor);
void apresentarMaiorMenor(int indiceMaior, int funcionarioMaiorSalario[], float maiorSalario, int indiceMenor, int funcionarioMenorSalario[], float menorSalario);

int main (void){
//	declarações
	float menorSalario, maiorSalario, mediaSalario;
	int contador = 0, indice = 0, indiceMaior = 0, indiceMenor = 0, igual = 0;
	float salarios[MAX_FUNCIONARIOS] = {0};
	int codigos[MAX_FUNCIONARIOS] = {0}, funcionarioMenorSalario[MAX_FUNCIONARIOS] = {0}, funcionarioMaiorSalario[MAX_FUNCIONARIOS] = {0};
//	instruções
	puts(" BALANCO SALARIAL DOS FUNCIONARIOS");
	puts("(codigo 0 ou negativo para encerrar)\n");
	do{
		codigos[contador] = lerValidarCodigo(codigos, contador);
			if(codigos[contador] <= 0){
				break;
			}
		salarios[contador] = lerValidarSalario();		
		contador++;
	}while(contador < MAX_FUNCIONARIOS);
	
	system("CLS");
	puts("BALANCO SALARIAL DOS FUNCIONARIOS\n");

	for(indice = 0; indice < contador; indice++){
		if(salarios[0] == salarios[indice]){
			igual++;
		}		
	}
	if(igual == contador){
		printf("\nTODOS OS SALARIOS SAO IGUAIS");
	}else{
		maiorSalario = encontrarMaiorSalario(contador, salarios, codigos, funcionarioMaiorSalario, &indiceMaior);
		menorSalario = encontrarMenorSalario(contador, salarios, codigos, funcionarioMenorSalario, &indiceMenor);
		apresentarMaiorMenor(indiceMaior, funcionarioMaiorSalario, maiorSalario, indiceMenor, funcionarioMenorSalario, menorSalario);
	}
	mediaSalario = calcularMedia(contador, mediaSalario, salarios);
	
	printf("\n\n\nPRESSIONE QUALQUER TECLA PARA ENCERRAR.\n");
	printf("\n\n\nPRESSIONE QUALQUER TECLA PARA ENCERRAR.\n");
	getche();
	return 0;
}

int lerValidarCodigo(int cod[], int cont){
	int ind = 0;
	
	printf("CODIGO: ");
	scanf("%i", &cod[cont]);
	
	if(cont <= 1){
		while(cod[cont] <= 0){
			puts("MINIMO DE DOIS CADASTROS!");
			printf("INFORME UM CODIGO VALIDO:");
			scanf("%i", &cod[cont]);
		}
	}
	
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

float lerValidarSalario(){
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
	//demorei 2 dias só pra fazer essas duas funções, sempre dava um erro e eu passava horas tentando solucionar...
float encontrarMaiorSalario(int contador, float salarios[], int codigos[], int funcionarioMaiorSalario[], int *indiceMaior){
	int	indice, auxiliar = 0;
	
	float maiorSalario = salarios[0];
	for(indice = (contador - 1); indice >= 0; indice--){
		//descobre o maior e no próximo loop conta quantos são iguais, porque sempre dava erro
		if(maiorSalario <= salarios[indice]){
			maiorSalario = salarios[indice];
		}
	}	
	for(indice = 0; indice < contador; indice++){
		if(maiorSalario <= salarios[indice]){
			maiorSalario = salarios[indice];
			funcionarioMaiorSalario[auxiliar] = codigos[indice];		
			auxiliar++; // fiz essa var local, pois o vetor/ponteiro referenciado não estava incrementando
		}
	}
	*indiceMaior = auxiliar;
	return maiorSalario;
}

float encontrarMenorSalario(int contador, float salarios[], int codigos[], int funcionarioMenorSalario[], int *indiceMenor){
	int	indice, auxiliar = 0;
	
	float menorSalario = salarios[0];
	for(indice = (contador - 1); indice >= 0; indice--){
		if(menorSalario >= salarios[indice]){
			menorSalario = salarios[indice];
		}
	}
	for(indice = 0; indice < contador; indice++){
		if(menorSalario >= salarios[indice]){
			menorSalario = salarios[indice];
			funcionarioMenorSalario[auxiliar] = codigos[indice];		
			auxiliar++;
		}
	}
	*indiceMenor = auxiliar;
	return menorSalario;
}	

float calcularMedia(int contador, float mediaSalario, float salarios[]){
	int indice;
	for(indice = 0; indice < contador; indice++){
		mediaSalario += salarios[indice];
	}
	mediaSalario /= contador;
	apresentarMedia(mediaSalario);
	return mediaSalario;
}

void apresentarMedia(float mediaSalario){
	printf("\n\nMEDIA SALARIAL: R$ %.2f.", mediaSalario);
}

void apresentarMaiorMenor(int indiceMaior, int funcionarioMaiorSalario[], float maiorSalario, int indiceMenor, int funcionarioMenorSalario[], float menorSalario){
	int indice;
	
	printf("\nMAIOR SALARIO");
	if(indiceMaior == 1){
		printf("\nCODIGO: %i", funcionarioMaiorSalario[0]);
	}
	if(indiceMaior > 1){	
		printf("\nCODIGOS:");
		for(indice = 0; indice < indiceMaior; indice++){
			if(indice > 0 && indice < indiceMaior - 1){
				printf(",");
			}
			if(indice == indiceMaior - 1){
				printf(" e");
			}
			printf(" %i",funcionarioMaiorSalario[indice]);
		}
	}	
	printf("\nSALARIO: R$ %.2f", maiorSalario);

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
	printf("\nSALARIO: R$ %.2f", menorSalario);
}

