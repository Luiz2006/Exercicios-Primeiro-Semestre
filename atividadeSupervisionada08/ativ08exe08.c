//Faça um programa que leia três valores numéricos e os mostre em ordem crescente.
#include<stdio.h>
#include<locale.h>
main (){
	setlocale(LC_ALL, "Portuguese");
	float val1, val2, val3;
	
	printf("Informe o primeiro número: ");
	scanf("%f", &val1);	
	printf("Informe o primeiro valor: ");
	scanf("%f", &val2);	
	printf("Informe o primeiro valor: ");
	scanf("%f", &val3);
	
	printf("Valores na ordem crescente: ");
	if(val1 < val2 && val1 < val3){
		printf("%f", val1);
		if(val2 < val3){
			printf(", %f e %f.", val2, val3);			
		}else{			
			printf(", %f e %f.", val3, val2);
		}
	}	
	
	if(val2 < val1 && val2 < val3){
		printf("%f", val2);
		if(val1 < val3){
			printf(", %f %f.", val1, val3);			
		}else{			
			printf(", %f e %f.", val3, val1);
		}
	}	
	
	if(val3 < val1 && val3 < val2){
		printf("%f", val3);
		if(val1 < val2){
			printf(", %f e %f.", val1, val2);			
		}else{			
			printf(", %f e %f.", val2, val1);
		}
	} 
}
