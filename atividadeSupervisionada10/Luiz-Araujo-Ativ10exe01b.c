#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

float calculaMedia(float n1, float n2, float n3){
	float m;
	m = ((n1 + n2 + n3)/3);
	
	return m;
}

main(){
	setlocale(LC_ALL,"Portuguese");
	float nota1, nota2, nota3, media;
	int aluno = 1;
	char continuar = 's';
	
	do{
		printf("CÁLCULO DA MÉDIA DE NOTAS ALUNO %i", aluno);
		printf("\nNOTA PROVA 1: ");
		scanf("%f", &nota1);
		printf("NOTA PROVA 2: ");
		scanf("%f", &nota2);
		printf("NOTA PROVA 3: ");
		scanf("%f", &nota3);
		
		media = calculaMedia(nota1, nota2, nota3);			
		
		printf("MÉDIA ALUNO %i: %.2f.\n", aluno, media);
		
		aluno++;
		
		printf("Novo cálculo? [s - para sim] ");
		continuar = getche();
		printf("\n\n");
	}while((continuar == 's')||(continuar == 'S'));
	
	return 0;
}




