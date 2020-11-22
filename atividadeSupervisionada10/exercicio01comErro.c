#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

float calculaMedia(float *nota);
//void validarNota(float *nota);
int main(){
	setlocale(LC_ALL, "Portuguese");
	
//	declarações
	char continuar;
	
//	instruções
	do{		
		float nota[3], media;	
		char nome[25];
		
		printf("CÁLCULAR MÉDIA DAS NOTAS");
		printf("\nNome: ");
		gets(nome);
		
		printf("Prova 1: ");
		scanf("%f", &nota[0]);
//		validarNota(&nota[0]);
		printf("Prova 2: ");
		scanf("%f", &nota[1]);
//		validarNota(&nota[1]);
		printf("Prova 3: ");
		scanf("%f", &nota[2]);
//		validarNota(&nota[2]);
		
		media = calculaMedia(nota);
		
		printf("\nAluno: %s.", nome);
		printf("\nMédia: %f.", media);	
		
		printf("\nDeseja continuar [s - para sim]? ");
		continuar = getche();
		continuar = tolower(continuar);
		printf("\n\n");
	}while(continuar == 's');
	
	return 0;
}

float calculaMedia(float *nota){
	float media;
	
	media = ((nota[0] + nota[1] + nota[2]) / 3);
	
	return media;
}
/**
void validarNota(float *nota){
	while((nota < 0)||(nota > 10)){
		printf("\nInforme uma nota entre 0 e 10!");
		printf("\nProva 1: ");
		scanf("%f", *nota);
	}
}

*/














