/*
Name: Luiz Araujo
Description: Escrever um programa que declare um vetor de reais e leia as notas de 30 alunos.
*/

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

#define MAX_ALUNOS 30

void mostrarNotas(float *notas);

int main(void){
	setlocale(LC_ALL, "Portuguese");
//	declarações
	float notas[MAX_ALUNOS];
	int cont;
//	instruções	
	printf("INFORME AS NOTAS DOS ALUNOS\n");
	
	for(cont = 0; cont < MAX_ALUNOS; cont++){
		do{
			if((notas[cont] < 0) || (notas[cont] > 10)){				
				printf("Nota inválida!\n");
			}
			printf("%3iª Nota: ", (cont + 1));
			scanf("%f",&notas[cont]);
		}while((notas[cont] < 0) || (notas[cont] > 10));
	}	
	
	printf("PRESSIONE QUALQUER BOTÃO PARA CONTINUAR...");
	getche();
	
	mostrarNotas(notas);
	
	return 0;
}

void mostrarNotas(float *notas){
	int cont;
	system("CLS");
	printf(" LISTA DE NOTAS\n");
	for(cont = 0; cont < MAX_ALUNOS; cont++){
		printf("\n%2iº Aluno:%5.1f", (cont + 1),notas[cont]);
		
	}
}
