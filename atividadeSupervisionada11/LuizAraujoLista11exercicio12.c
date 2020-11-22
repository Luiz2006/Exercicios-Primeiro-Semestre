/*
Name: Luiz Araujo
Description: Uma grande empresa deseja saber quais os três empregados mais recentes. Fazer um algoritmo para ler um
número indeterminado de informações (máximo de 50) contendo a matrícula funcional do empregado e o número
de meses de trabalho deste empregado. 
Mostre os três empregados mais recentes. 
Não existem dois empregados admitidos no mesmo mês e a matrícula igual a zero ‘0’ encerra a leitura. Observe o exemplo abaixo:
*/

#include<stdio.h>
#include<stdlib.h>

#define MAX_EMPREGADOS 50

//void leValidaEmpregado(int matricula, int qtdEmpregado);
int main(void){
//	declarações
	int matricula[MAX_EMPREGADOS], meses[MAX_EMPREGADOS];
	int qtdEmpregados = 0;

//	instrução
	puts("QUAL O EMPREGADOR MAIS RECENTE?");

	do{
		matricula[qtdEmpregados] = leValidaMatricula(qtdEmpregados, matricula);
		meses[qtdEmpregados] = leValidaMeses();
		
		qtdEmpregados++;
	}while();
	
	return 0;
}




int leValidaMatricula(int qtdEmpregados, float *matricula){
	do{
		
		int mat;
		printf("\nMATRICULA: ");
		scanf("%i", &mat);
		
		while(matricula < 0){
			printf("A MATRICULA NAO PODE SER NEGATIVA: ");
			scanf("%i", &mat);
		}	
		
		if(qtdEmpregados > 0){	
			for(qtdEmpregados -= 1; qtdEmpregados >= 0; qtdEmpregados--){
				if(mat == matricula[cont]){
					printf("MATRICULA JA CADASTRADA: ");
					scanf("%i", &mat);
				}
				
			}
		}
		return mat;
	
	}
}

int leValidaMeses(){
	
	
	
	
	
	
	
	
	
	
