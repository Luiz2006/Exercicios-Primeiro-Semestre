#include<stdio.h>
#include<stdlib.h>

#define MAX_NOME 100

int main(void){
	char nome[MAX_NOME];
	int contador = 0, indice;

	puts("INFORME O SEU NOME COMPLETO:");
	do{
		fflush(stdin);
		nome[contador] = getche();
		if(nome[contador] == '#'){
			break;
		}		
		contador++;
		if(contador == (MAX_NOME - 1)){
			puts("\nTAMANHO MAXIMO EXCEDIDO!");
			break;
		}
	}while(contador < MAX_NOME);
	
		printf("\n\nSEU NOME COMPLETO:\n");
		
	for(indice = 0; indice < contador; indice++){
		printf("%c", nome[indice]);		
	}
	
	printf("\n\n\nPRESSIONE QUALQUER TECLA PARA ENCERRAR.\n");
	getche();
	return 0;
}
