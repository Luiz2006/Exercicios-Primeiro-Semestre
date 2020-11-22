#include<stdio.h>
#include<locale.h>
main(){
	setlocale(LC_ALL, "Portuguese");
	
	int valor;
	
	printf("Informe um valor: ");
	scanf("%i", &valor);
	
	if(valor > 2000){
		system("CLS");
		printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t  Valor: %i.\n", valor);
		printf("\t\t\t\t\tO limite de cálculo foi excedido.\n\n\n\n\n\n\n\n\n\n\n");
	}else{	
		//pensei em  duas formas diferentes 
		/*
		if(valor % 2 != 0){
			valor += 1;
		}
		for(valor; valor <= 2000; valor+=2){
			printf("%i - ", valor);
		}
		*/
		
		for(valor; valor <= 2000; valor++){
			if(valor % 2 == 0){
			printf("%i - ", valor);
			}
		}	
	}	
}
