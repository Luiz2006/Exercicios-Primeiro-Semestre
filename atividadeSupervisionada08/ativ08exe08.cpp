//Faça um programa que leia três valores numéricos e os mostre em ordem crescente.
#include<stdio.h>
main (){
	int val1, val2, val3;
	
	printf("Informe o primeiro valor: ");
	scanf("%i", &val1);	
	printf("Informe o primeiro valor: ");
	scanf("%i", &val2);	
	printf("Informe o primeiro valor: ");
	scanf("%i", &val3);
	
	printf("Valores na ordem crescente: ");
	if(val1 < val2 && val1 < val3){
		printf("%i", val1);
		if(val2 < val3){
			printf(", %i e %i", val2, val3);			
		}else{			
			printf(", %i e %i", val3, val2);
		}
	}	
	
	if(val2 < val1 && val2 < val3){
		printf("%i", val2);
		if(val1 < val3){
			printf(", %i e %i", val1, val3);			
		}else{			
			printf(", %i e %i", val3, val1);
		}
	}	
	
	if(val3 < val1 && val3 < val2){
		printf("%i", val3);
		if(val1 < val2){
			printf(", %i e %i", val1, val2);			
		}else{			
			printf(", %i e %i", val2, val1);
		}
	} 
	
}
