//Name: Luiz Araujo
//Date: 15/11/20 18:31
//Description: calcula a média das notas das provas para cada estudante de uma turma em determinada disciplina. Lendo os valores na função 
//		principal e acionando uma outra função (calculaMedia) que realizará o cálculo da média aritmética para cada estudante informado. 
//		Apresente no programa principal a média alcançada por cada estudante. Lembre-se que não é permitido o uso de variáveis globais.

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

float calculaMedia(float *nota, int qtdProvas);
int validarQtdProvas(int qtdProvas);
int validarQtdAlunos(int qtdAlunos);
	
int main(){
	setlocale(LC_ALL, "Portuguese");
	
//	declarações
	char continuar;
	int qtdAlunos = 1, qtdProvas = 1, contadorAluno = 1;
	
//	instruções
	printf("CÁLCULAR MÉDIA DAS NOTAS");
	printf("\nQuantidade de alunos: ");
	scanf("%i", &qtdAlunos);
	qtdProvas = validarQtdAlunos(qtdAlunos);
	
	printf("Quantidade de provas: ");
	scanf("%i", &qtdProvas);
	qtdProvas = validarQtdProvas(qtdProvas);
	
	system("CLS");
	printf("CÁLCULAR MÉDIA DAS NOTAS");	
	printf("\n%i alunos fizeram %i provas, cada.\n", qtdAlunos, qtdProvas);
	
	char nome[qtdAlunos][60];
	float media[qtdAlunos];
	do{
		float nota[qtdProvas];	
		int contador;	
		
		printf("Nome: ");
		scanf("%s", nome[contadorAluno]);		
		
		for(contador = 1; contador <= qtdProvas; contador++){
			int indice = contador - 1;
			do{
				printf("%iª Prova: ", (contador));
				scanf("%f", &nota[indice]);
				if((nota[indice] < 0)||(nota[indice] > 10)){
					printf("A nota dever ser entre 0 e 10!\n");
				}										
			}while((nota[indice] < 0)||(nota[indice] > 10));
		}
		
//	Para visualizar as notas
//	for(contador = 1; contador <= qtdProvas; contador++){
//		int indice = contador - 1;
//		printf("\nNota prova %i: %.2f.", (contador), nota[indice]);
//	}
		
		media[contadorAluno] = calculaMedia(nota, qtdProvas);
		
		printf("\n%iº Aluno: %s.", contadorAluno, nome[contadorAluno]);
		printf("\nMédia: %.2f.", media[contadorAluno]);	
		
		contadorAluno++;		
		
		if(contadorAluno <= qtdAlunos){
			printf("\nDeseja continuar [s - para sim]? ");
			continuar = getche();
			continuar = tolower(continuar);
		}		
		
		printf("\n\n");
		fflush (stdin);			

	}while((continuar == 's') && (contadorAluno <= qtdAlunos));
	
	system("CLS");
	printf("\tMÉDIA DA TURMA\n");
	
	int cont1;
	for(cont1 = 1; cont1 < contadorAluno; cont1++) {	
		printf("%iº ALUNO: %5.2f - %s\n", cont1, media[cont1], nome[cont1]);	
	}
	return 0;
}

float calculaMedia(float *nota, int qtdProvas){
	float media = 0;
	int contador;
	
	for(contador = 0; contador <= (qtdProvas - 1); contador++)	
		media = (media + nota[contador]);
	
	return (media / qtdProvas);
}

int validarQtdProvas(int qtdProvas){	
	while(qtdProvas <= 0){
		printf("\nQuantidade de provas dever ser maior que 0: ");
		scanf("%i", &qtdProvas);		
	}
	return qtdProvas;
}

int validarQtdAlunos(int qtdAlunos){	
	while(qtdAlunos <= 0){
		printf("\nQuantidade de provas dever ser maior que 0: ");
		scanf("%i", &qtdAlunos);		
	}
	return qtdAlunos;
}




