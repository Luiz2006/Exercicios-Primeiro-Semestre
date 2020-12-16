#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

float calculaMedia(float n1, float n2, float n3);
float validaNota(float nota);
float validaNota(float nota);

main(){
	setlocale(LC_ALL,"Portuguese");
	
	//declarações
	float nota1, nota2, nota3, media;
	char continuar = 's';
	int aluno = 1;
	
	//instruções
	do{
		printf("MÉDIA DO ALUNO %iº", aluno);
		
		printf("\nNOTA 1: ");
		scanf("%f", &nota1);
		validaNota(nota1);
		printf("NOTA 2: ");
		scanf("%f", &nota2);
		validaNota(nota2);
		printf("NOTA 3: ");
		scanf("%f", &nota3);
		validaNota(nota3);
		
		media = calculaMedia(nota1, nota2, nota3);
		
		printf("MÉDIA: %.1f. \n", media);
		
		aluno++;
		
		printf("Novo cálculo? [s - para sim] ");
		continuar = getche();
		printf("\n\n");
	}while(continuar == 's');	
}

float calculaMedia(float n1, float n2, float n3){
	float m;
	m = ((n1 + n2 + n3)/3);
	return m;
}

float validaNota(float nota){
	while((nota > 10) || (nota < 0)){
		printf("\nNOTA INVÁLIDA! ");
		printf("\nInforme novamente: ");
		scanf("%f", &nota);	
	}
	return nota;
}


