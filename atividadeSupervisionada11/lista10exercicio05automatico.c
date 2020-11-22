/*
Name: Luiz Araujo
Description: programa que efetua os cálculos relacionados a avaliação final de uma disciplina, 
		onde o cálculo da média deverá ser realizado por uma função denominada MEDIA.
*/

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include <time.h> //para testar automaticamente



float MEDIA(float A1, float A2, float A3, float AS);
float calcularFrequencia(float aulas, float faltas);
void validarNota(float *nota);
void validarFrequencia(float *aula, float total);
void mensagemResultado(float media, float A1, float A2, float A3, float frequencia);
float notaAleatoria(); //para testar automaticamente

int main(void){	
	setlocale(LC_ALL, "Portuguese");
	
	printf("\t\tLISTA 10 EXERCÍCIO 05\n");
	printf("\n5. Desenvolva um programa que efetue os cálculos relacionados a avaliação \nfinal desta disciplina neste ano e semestre, onde o cálculo da média \ndeverá ser realizado por uma função denominada MEDIA.");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	system("PAUSE");
	
	system("CLS");

srand(time(NULL)); //para testar automaticamente
float r = rand(); //para testar automaticamente

//declarações
	float media, avaliacao1, avaliacao2, avaliacao3, atividades, frequencia, aulas, faltas;
//instruções
	printf("AVALIAÇÃO ALGORITMOS DE PROGRAMAÇÃO");
	printf("\n\tSEMESTRE/ANO: 2/2020");

	printf("\n\n\n\tINFORME AS NOTAS (com vírgulas)");

	printf("\n1ª Atividade Avaliativa   : ");
//	scanf("%f", &avaliacao1);	 //comentar para testar automaticamente
//	validarNota(&avaliacao1);	 //comentar para testar automaticamente
	avaliacao1 = notaAleatoria(); printf("%.1f\n", avaliacao1);//para testar automaticamente
	printf("2ª Atividade Avaliativa   : ");
//	scanf("%f", &avaliacao2);	 //comentar para testar automaticamente
//	validarNota(&avaliacao2);	 //comentar para testar automaticamente
	avaliacao2 = notaAleatoria(); printf("%.1f\n", avaliacao2);//para testar automaticamente
	printf("3ª Atividade Avaliativa   : ");
//	scanf("%f", &avaliacao3);	 //comentar para testar automaticamente
//	validarNota(&avaliacao3);	 //comentar para testar automaticamente
	avaliacao3 = notaAleatoria(); printf("%.1f\n", avaliacao3);//para testar automaticamente

	printf("Atividades Supervisionadas: ");
//	scanf("%f", &atividades);	 //comentar para testar automaticamente
//	validarNota(&atividades);	 //comentar para testar automaticamente
	atividades = notaAleatoria(); printf("%.1f\n", atividades);//para testar automaticamente


//averiguar frequência 
	printf("\n\n\tFREQUÊNCIA ");	
	printf("\nQuantidade de aulas: ");
//	scanf("%f", &aulas);				 //comentar para testar automaticamente
//	validarFrequencia(&aulas, faltas);	 //comentar para testar automaticamente
	aulas = 10; printf("%.0f\n", aulas);//para testar automaticamente

	printf("Quantidade de faltas: ");
//	scanf("%f", &faltas);				//comentar para testar automaticamente
//	validarFrequencia(&faltas, aulas);	//comentar para testar automaticamente
	faltas = notaAleatoria(); printf("%.0f\n", faltas);//para testar automaticamente


	media = MEDIA(avaliacao1, avaliacao2, avaliacao3, atividades);
	frequencia = calcularFrequencia(aulas, faltas);

//resultado
	printf("\n\n\tRESULTADO ");	
	printf("\nMÉDIA FINAL   : %.2f.", media);
	printf("\nAPROVEITAMENTO: %.2f%%.", ((media*1000)/100));
	printf("\nFREQUÊNCIA: %.2f %%.", frequencia);
	mensagemResultado(media, avaliacao1, avaliacao2, avaliacao3, frequencia);

	return 0;
}

float MEDIA(float A1, float A2, float A3, float AS){
	float media;
	media = ((A1*0.20) + (A2*0.20) + (A3*0.30) + (AS*0.30));
	return media;
}

void validarNota(float *nota){
	while((*nota < 0)||(*nota > 10)){
		printf("Nota inválida, informe novamente: ");
		scanf("%f", *&nota);
	}
}

void validarFrequencia(float *aula, float total){ 	
	while((*aula < 0)||(*aula > 99)){
		printf("Entrada inválida, informe novamente: ");
		scanf("%f", aula);
	}

	if(!total){							//se total for != 0 quer dizer que foi chamada na parte de faltas
		while(*aula <= 0){
			printf("Entrada inválida, informe novamente: ");
			scanf("%f", aula);
		}
	}else{	
			
		while((*aula < 0) || (*aula > total)) { //última parte da cond é para as faltas nãp ultrapassar as aulas
			printf("Entrada inválida, informe novamente: ");
			scanf("%f", aula);
		}
	}
}

float calcularFrequencia(float aulas, float faltas){	
	float freq;
	if(faltas == 0){
		freq = 100;
	}else{
		if(faltas == aulas){
			freq = 0;
		}else{{
				freq = ((faltas * 100) / aulas);	
			}	
		}
	}
	return freq;
}

void mensagemResultado(float media, float A1, float A2, float A3, float freq){	
	if((freq < 75)){ //padrão: < 75
		if((media < 7)){ //padrão: < 7
			printf("\n\nREPROVADO PELA NOTA E POR FALTA, QUE PENA!");
		}else{
			printf("\n\nREPROVADO POR FALTA, QUE PENA!");			
		}		
	}else{
		if(media >= 7){ //padrão: < 7
			if(media >= 9){
				printf("\n\nAPROVADO COM LOUVOR, PARABÉNS!");
			}else{
				printf("\n\nAPROVADO, PARABÉNS!");
			}
		}else{
			printf("\n\nREPROVADO POR NOTA, QUE PENA!");
		}
		if(media < 7){ //padrão: < 7		
			printf("\n\nObs.:Haverá uma avaliação de recuperação/substituição (AR) que será utilizada para substituir a nota da: ");
			if(A1 < 7){ //padrão: < 7
				printf("\n 1ª AVALIAÇÃO");
			}
			if(A2 < 7){ //padrão: < 7
				printf("\n 2ª AVALIAÇÃO");
			}
			if(A3 < 7){ //padrão: < 7
				printf("\n 3ª AVALIAÇÃO");
			}			
			printf("\n\nATENÇÃO: As notas de atividades supervisionadas (AS) não poderão ser substituídas pela avaliação de recuperação.");			
		}	
	}
}

// para testar automaticamente
float notaAleatoria(){
	return (rand() % 9);
}
