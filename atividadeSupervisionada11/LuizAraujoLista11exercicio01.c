#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#define MAX_ALUNOS 30
void mostrarNotas(float *notas);
int main(void){
	setlocale(LC_ALL, "Portuguese");
//	declara��es
	float notas[MAX_ALUNOS];
	int cont, contErro = 0;	
//	instru��es	
	printf("INFORME AS NOTAS DOS ALUNOS\n");
	for(cont = 0; cont < MAX_ALUNOS; cont++){
		do{
			printf("%2i� Nota: ", (cont + 1));
			scanf("%f",&notas[cont]);
			while((notas[cont] < 0) || (notas[cont] > 10)){	
				fflush(stdin);
				if(contErro > 1){
					printf("Informe algo entre 0 e 10.\n");
				}else{
					printf("Nota inv�lida!\n");
				}					
				printf("%2i� Nota: ", (cont + 1));
				scanf("%f",&notas[cont]);
				contErro++;
			}
		}while((notas[cont] < 0) || (notas[cont] > 10));
	}		
	printf("\n\nPRESSIONE QUALQUER BOT�O PARA CONTINUAR...");
	getche();	
	mostrarNotas(notas);	
	printf("\n\nPRESSIONE QUALQUER BOT�O PARA FINALIZAR.");
	getche();
	return 0;
}
void mostrarNotas(float *notas){
	int cont;	
	system("CLS");
	printf("\tLISTA DE NOTAS\n");
	for(cont = 0; cont < MAX_ALUNOS; cont++){
		printf("%2i� Nota:%5.1f\t\t", (cont + 1),notas[cont]);
		if((cont + 1) % 2 == 0){
			printf("\n");
		}
	}
}
