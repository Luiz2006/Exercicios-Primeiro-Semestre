#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#define MAX_ALUNOS 30
void mostrarNotas(float *notas);
int main(void){
	setlocale(LC_ALL, "Portuguese");
//	declarações
	float notas[MAX_ALUNOS];
	int cont, contErro = 0;	
//	instruções	
	printf("INFORME AS NOTAS DOS ALUNOS\n");
	for(cont = 0; cont < MAX_ALUNOS; cont++){
		do{
			printf("%2iª Nota: ", (cont + 1));
			scanf("%f",&notas[cont]);
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
		}while((notas[cont] < 0) || (notas[cont] > 10));
	}		
	printf("\n\nPRESSIONE QUALQUER BOTÃO PARA CONTINUAR...");
	getche();	
	mostrarNotas(notas);	
	printf("\n\nPRESSIONE QUALQUER BOTÃO PARA FINALIZAR.");
	getche();
	return 0;
}
void mostrarNotas(float *notas){
	int cont;	
	system("CLS");
	printf("\tLISTA DE NOTAS\n");
	for(cont = 0; cont < MAX_ALUNOS; cont++){
		printf("%2iª Nota:%5.1f\t\t", (cont + 1),notas[cont]);
		if((cont + 1) % 2 == 0){
			printf("\n");
		}
	}
}
