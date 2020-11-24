/*
Name: Luiz Araujo
Description: Elabore um algoritmo que leia um conjunto de valores inteiros correspondentes a até 80 notas, variando de 0 a
10, dos alunos de uma turma (vários alunos). Calcule a frequência de cada nota e apresente uma tabela contendo os
valores das notas e suas respectivas frequências.
*/

#include<stdio.h>
#include<stdlib.h>

#define MAX_NOTAS 80

int lerValidarNotas(int contador);
void apresentarTabelaResultado(int frequencia[]);
void calcularFrequencia(int notas[], int frequencia[11], int contador);

int main(void){
//	declarações
	int notas[MAX_NOTAS] = {0}, frequencia[11] = {0};
	int contador = 0;
	

//	instruções
	puts("  FREQUENCIA DE NOTAS");
	puts("(nota negativa encerra)");
	do{
				
		notas[contador] = lerValidarNotas(contador);
//		notas[contador] = rand()%10;
		if(notas[contador] < 0){
			break;
		}
		
		contador++;
	}while(contador < MAX_NOTAS);	
	
	calcularFrequencia(notas, frequencia, contador);	
	apresentarTabelaResultado(frequencia);	
	
	getch();
	return 0;
}
int lerValidarNotas(int contador){
	int nota;
	
	printf("NOTA: ");
	scanf("%i", &nota);
	
	while(nota > 10){
		printf("Nota invalida:\n");
		printf("NOTA: ");
		scanf("%i", &nota);
	}	
	return nota;
}

void calcularFrequencia(int notas[], int frequencia[11], int contador){
	int indice, indice2;
	for(indice = 0; indice < contador; indice++){
		for(indice2 = 0; indice2 <= 10; indice2++){
			if(notas[indice] == indice2){
				frequencia[indice2] += 1; 
			}			
		}		
	}	
}

void apresentarTabelaResultado(int frequencia[]){
	int indice;
	
	system("CLS");

	printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
	printf("\n%c  FREQUENCIA   %c", 186, 186);
	printf("\n%c   DE NOTAS    %c", 186, 186);
	printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c ", 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
	for(indice = 0; indice <= 10; indice++){
		printf("\n%c NOTA %-2i:  %-3i %c", 186, indice, frequencia[indice], 186);
	}	
	printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c ", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
}
