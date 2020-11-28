#include<stdio.h>
#include<locale.h>
int main(void){
	setlocale(LC_ALL, "Portuguese");
	
	int valor, indice;
	
	printf("Informe um valor: ");
	scanf("%i", &valor);
	
	if(valor > 2000){
		system("CLS");
		printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t  Valor: %i.\n", valor);
		printf("\t\t\t\t\tO limite de cálculo foi excedido.\n\n\n\n\n\n\n\n\n\n\n");
	}else{
		for(indice = valor; indice <= 2000; indice++){
			if(indice % 2 == 0){
				printf("%4i\t", indice);
			}
			if((indice + 1) % 20 == 0){
				printf("\n");
			}
		}
	}
	printf("\n\n\nPRESSIONE QUALQUER TECLA PARA ENCERRAR.");
	getche();
	return 0;	
}
