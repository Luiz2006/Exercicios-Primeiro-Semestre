#include<stdio.h>
#include<stdlib.h>

#define MAX_ELEMENTOS 10
int main(void){
//	declarações
	int A[MAX_ELEMENTOS] = {0,1,2,3,4,5,6,7,8,9}, B[MAX_ELEMENTOS] = {0,1,2,3,4,5,6,7,8,9};
	int C[MAX_ELEMENTOS][MAX_ELEMENTOS];
	int indice, indice2, escolha[2];
	
//	instruções
	puts("VALORES DE A:");
	for(indice = 0; indice < MAX_ELEMENTOS; indice++){
		printf("%i: ", indice);
		scanf("%i", &A[indice]);
	}	
	puts("\nVALORES DE B:");
	for(indice = 0; indice < MAX_ELEMENTOS; indice++){
		printf("%i: ", indice);
		scanf("%i", &B[indice]);
	}
	system("CLS");
	printf("A[10] = {");
	for(indice = 0; indice < MAX_ELEMENTOS; indice++){
		if(indice < MAX_ELEMENTOS && indice > 0){
			printf(", ");
		}
		printf("%i", A[indice]);
	}
	printf("}");
	printf("\n\n");	
	printf("B[10] = {");
	for(indice = 0; indice < MAX_ELEMENTOS; indice++){
		if(indice < MAX_ELEMENTOS && indice > 0){
			printf(", ");
		}
		printf("%i", B[indice]);
	}
	printf("}");
	printf("\n\n ");
	
	for(indice = 0; indice < MAX_ELEMENTOS; indice++){
		for(indice2 = 0; indice2 < MAX_ELEMENTOS; indice2++){
			C[indice][indice2] = A[indice] + B[indice2];
		}
	}	
	puts("PESQUISAR VALORES DA MATRIZ");
	puts("(somente valores entre 0 e 9)");
	do{
		printf("\nA: ");
		scanf("%i", &escolha[0]);
		if(escolha[0] < 0 || escolha[0] > 9){
			break;
		}
		printf("B: ");
		scanf("%i", &escolha[1]);
		if(escolha[1] < 0 || escolha[1] > 9){
			break;
		}		
		printf("RESULTADO de A%i + B%i: %i + %i= %i.\n\n", escolha[0], escolha[1],A[escolha[0]], B[escolha[1]], C[escolha[0]][escolha[1]]);
	}while((escolha[0] >= 0 && escolha[0] <= 9)&&(escolha[1] >= 0 && escolha[1] <= 9)) ;
	printf("\nGABARITO\n ");
	printf("%4s%4s%4s%4s%4s%4s%4s%4s%4s%4s\n\n", "A", "A", "A", "A", "A", "A", "A", "A", "A", "A");
	for(indice = 0; indice < MAX_ELEMENTOS; indice++){
			printf("B");
		for(indice2 = 0; indice2 < MAX_ELEMENTOS; indice2++){
			printf("%4i", C[indice][indice2]);
			if(indice2 == 9){
				printf("\n\n");
			}
		}
	}
	printf("\n\n\nPRESSIONE QUALQUER TECLA PARA ENCERRAR.\n");
	getche();
	return 0;
}
