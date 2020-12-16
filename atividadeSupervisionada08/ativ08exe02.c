//Desenvolva um programa em C que leia três valores numéricos e apresente o maior valor informado no meio de uma janela limpa.
#include<stdio.h>
#include<locale.h>
main (){
	setlocale(LC_ALL, "Portuguese");
	
	float val1, val2, val3;
	
	printf("Informe o primeiro valor: ");
	scanf("%f", &val1);	
	printf("Informe o primeiro valor: ");
	scanf("%f", &val2);	
	printf("Informe o primeiro valor: ");
	scanf("%f", &val3);
	
	system("cls");
	if(val1 > val2 && val1 > val3){
		printf("O maior valor é %.2f", val1);
	}else{		
		if(val2 > val1 && val2 > val3){
			printf("O maior valor é %.2f", val2);
		}else{		
			if(val3 >= val1 && val3 >= val2){
				printf("O maior valor é %.2f", val3);
		}
	}
	
}
