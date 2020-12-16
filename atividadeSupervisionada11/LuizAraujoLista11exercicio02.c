#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
int validarQtd(int qtdAlunos);
void mostrarNotas(float *notas, int qtdAlunos);
int main(void){
	setlocale(LC_ALL, "Portuguese");
//	declarações
	int cont, qtdAlunos, contErro = 0;		
//	instruções	
	printf("INFORME\n");
	printf("Quantidade de alunos: ");
	scanf("%i", &qtdAlunos);
	qtdAlunos = validarQtd(qtdAlunos);	
	float notas[qtdAlunos];
	for(cont = 0; cont < qtdAlunos; cont++){
		printf("%2iª Nota: ", (cont + 1));
		scanf("%f", &notas[cont]);
		while((notas[cont] < 0) || (notas[cont] > 10)){
			fflush(stdin);
			if(contErro > 1){
					printf("Informe algo entre 0 e 10.\n");
			}else{
				printf("Nota inválida!\n");
			}	
			printf("%2iª Nota: ", (cont + 1));
			scanf("%f",&notas[cont]);
			contErro++;
		}
	}			
	printf("\n\nPRESSIONE QUALQUER BOTÃO PARA CONTINUAR...");
	getche();	
	mostrarNotas(notas, qtdAlunos);	
	printf("\n\nPRESSIONE QUALQUER BOTÃO PARA FINALIZAR.");
	getche();
	return 0;
}

int validarQtd(int qtdAlunos){
	while((qtdAlunos <= 0) || (qtdAlunos >= 50)){
		if(qtdAlunos <= 0){
			printf("Deve haver pelo menos um aluno.\n");
		}
		if(qtdAlunos >= 50){
			printf("A turma não comporta mais que 49 alunos.\n");
		}
		printf("Quantidade de alunos: ");
		scanf("%i", qtdAlunos);
	}
	return qtdAlunos;
}
void mostrarNotas(float notas[], int qtdAlunos){
	int cont;
	system("CLS");
	printf("\tLISTA DE NOTAS\n");
	for(cont = 0; cont < qtdAlunos; cont++){
		printf("%2iª Nota:%5.2f\t\t", (cont + 1),notas[cont]);
		if((cont + 1) % 2 == 0){
			printf("\n");
		}		
	}
}
