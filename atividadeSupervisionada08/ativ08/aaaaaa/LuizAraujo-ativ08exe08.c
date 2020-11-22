#include<stdio.h>

int main (){
	float val1, val2, val3;
	
	printf("Informe o 1º valor: ");
	scanf("%f", &val1);
	printf("Informe o 2º valor: ");
	scanf("%f", &val2);
	printf("Informe o 3º valor: ");
	scanf("%f", &val3);
	
	if((val1 < val2) && (val1 < val3)){
		if(val2 < val3){
			printf("Ordem crescente: %f -> %f -> %f.", val1, val2, val3);
		}else{			
			printf("Ordem crescente: %f -> %f -> %f.", val1, val3, val2);
		}
	}
	
	if((val2 < val1) && (val2 < val3)){
		if(val1 < val3){
			printf("Ordem crescente: %f -> %f -> %f.", val2, val1, val3);
		}else{			
			printf("Ordem crescente: %f -> %f -> %f.", val2, val3, val1);
		}
	}
	
	
	if((val3 < val2) && (val3 < val1)){
		if(val1 < val2){
			printf("Ordem crescente: %f -> %f -> %f.", val3, val1, val2);
		}else{			
			printf("Ordem crescente: %f -> %f -> %f.", val3, val2, val1);
		}
	}
	
}
