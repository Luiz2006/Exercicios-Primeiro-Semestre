/*
Name: Luiz Araujo
Description: Uma grande empresa deseja saber quais os tr�s empregados mais recentes. Fazer um algoritmo para ler um
n�mero indeterminado de informa��es (m�ximo de 50) contendo a matr�cula funcional do empregado e o n�mero
de meses de trabalho deste empregado. 
Mostre os tr�s empregados mais recentes. 
N�o existem dois empregados admitidos no mesmo m�s e a matr�cula igual a zero �0� encerra a leitura. Observe o exemplo abaixo:
*/

#include<stdio.h>
#include<stdlib.h>

#define MAX_EMPREGADOS 50

//void leValidaEmpregado(int matricula, int qtdEmpregado);
int main(void){
//	declara��es
	int matricula[MAX_EMPREGADOS], meses[MAX_EMPREGADOS];
	int qtdEmpregados = 0;

//	instru��o
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
	
	
	
	
	
	
	
	
	
	
