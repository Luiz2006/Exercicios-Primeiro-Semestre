/*
Name: Luiz Araujo
Description: programa que declare um vetor de reais e leia as notas dos, 
		considerando que n�o se conhece quantos alunos esta turma tem 
		(menos que 50). O n�mero de aluno ser� informado pelo usu�rio.
*/

#include<stdio.h>
#include<stdlib.h>
//#include<locale.h>

void validarQtd(int *qtdAlunos);
void mostrarNotas(float *notas, int qtdAlunos);

int main(void){
//	setlocale(LC_ALL, "Portuguese");
//	declara��es
	float notas[50];
	int cont, qtdAlunos;
	
//	instru��es	
	printf("INFORME\n");
	printf("Quantidade de alunos: ");
	scanf("%i", &qtdAlunos);
	validarQtd(&qtdAlunos);
	
	for(cont = 0; cont <= (qtdAlunos - 1); cont++){
		do{
			if((notas[cont] < 0) || (notas[cont] > 10)){				
				printf(" Nota invalida!\n");
			}
			printf("%3i%c Nota: ", (cont + 1),166);
			scanf("%f",&notas[cont]);
		}while((notas[cont] < 0) || (notas[cont] > 10));
	}		
	
	printf("PRESSIONE QUALQUER BOT�O PARA CONTINUAR...");
	getche();
	
	mostrarNotas(notas, qtdAlunos);
	
	return 0;
}

void validarQtd(int *qtdAlunos){
	while((*qtdAlunos <= 0) || (*qtdAlunos >= 50)){
		printf("A turma nao comporta mais que 49 alunos.\n");
		
		printf("Quantidade de alunos: ");
		scanf("%i", *qtdAlunos);
	}
}

void mostrarNotas(float *notas, int qtdAlunos){
	int cont;
	system("CLS");
	printf(" LISTA DE NOTAS\n");
	for(cont = 0; cont < qtdAlunos; cont++){
		printf("\n%2i%c Aluno:%5.1f", (cont + 1), 167,notas[cont]);
		
	}
}
