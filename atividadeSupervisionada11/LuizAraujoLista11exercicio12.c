/*
Name: Luiz Araujo
Description: lê um número indeterminado (máximo de 50) de matrículas funcionais 
dos empregados e o número de meses de trabalhados. Mostrea os três empregados 
mais recentes. Não existem dois empregados admitidos no mesmo mês e a matrícula 
igual a zero ‘0’ encerra a leitura.
*/

#include<stdio.h>
#include<stdlib.h>

#define MAX_EMPREGADOS 50
#define NOVOS 3

void lerValidarMatricula(int contador, int matricula[]);
void lerValidarMeses(int contador, int meses[]);
void mostrarNovos(int contador, int matricula[], int meses[]);

int main(void){
//	declarações
	int matricula[MAX_EMPREGADOS] = {0}, meses[MAX_EMPREGADOS] = {0};	
	int contador = 0, indice = 0;
	
//	instruções
	puts("OS TRES EMPREGADOS MAIS RECENTES");
	puts("    (matricula 0 encerra)");
	
	puts("\nINFORME");
	do{
		lerValidarMatricula(contador, matricula);
		if(matricula[contador] == 0){
			break;
		}
		lerValidarMeses(contador, meses);
		
		contador++;
	}while(contador < MAX_EMPREGADOS);
	
	system("CLS");			
	puts("OS TRES EMPREGADOS MAIS RECENTES");
	
	mostrarNovos(contador, matricula, meses);

	return 0;
}

void lerValidarMatricula(int contador, int matricula[]){
	int indice = 0;
	
	printf("MATRICULA: ");
	scanf("%i", &matricula[contador]);
	
	while(matricula[contador] < 0){
		printf("A matricula deve ser um inteiro positivo: ");
		printf("\nMATRICULA: ");
		scanf("%i", &matricula[contador]);
	}
	if(contador == 0){
		while(matricula[contador] == 0){
			printf("Dever haver pelo menos uma matricula: ");
			printf("\nMATRICULA: ");
			scanf("%i", &matricula[contador]);
		}
	}else{
		do{
			while(matricula[indice] == matricula[contador]){
				printf("Matricula ja cadastrada!");
				printf("\nMATRICULA: ");
				scanf("%i", &matricula[contador]);
			}
			indice++;
		}while(indice < contador);
	}	
}
	
void lerValidarMeses(int contador, int meses[]){
	int indice = 0;
	
	printf("MESES DE TRABALHO: ");
	scanf("%i", &meses[contador]);
	
	while(meses[contador] <= 0){
		printf("Entrada invalida!\n");
		printf("MESES DE TRABALHO: ");
		scanf("%i", &meses[contador]);
	}
	
	if(contador > 0){
		while(indice < contador){
			if(meses[indice] == meses[contador]){
				printf("Nao existem dois empregados \nadmitidos no mesmo mes.\n");
				printf("MESES DE TRABALHO: ");
				scanf("%i", &meses[contador]);
			}
			indice++;
		}
	}
}	
	
void mostrarNovos(int contador, int matricula[], int meses[]){
	int indice, indice2 = 0, auxiliar = 0, cont = 0;	
	
	for(indice = 0; indice < (contador - 1); indice++){
		for(indice2 = (indice + 1); indice2 < contador; indice2++){
			if(meses[indice] > meses[indice2]){
				auxiliar = meses[indice];
				meses[indice] = meses[indice2];
				meses[indice2] = auxiliar;
				
				auxiliar = matricula[indice];
				matricula[indice] = matricula[indice2];
				matricula[indice2] = auxiliar;
			}
		}
	}

	for(indice = 0; indice < NOVOS; indice++){
		
		printf("\n%2i%c LUGAR:", (indice + 1), 167);
		printf("\nMatricula: %i", matricula[indice]);
		if(meses[indice] == 1){
			printf("\nMes      : %i\n", meses[indice]);
		}else{
			printf("\nMeses    : %i\n", meses[indice]);
		}
	}
		printf("\n\n\n\n");
}
