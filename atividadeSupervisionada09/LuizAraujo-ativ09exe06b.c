//Elabore um programa que identifique o número de algarismoss de um valor
#include<stdio.h>
main(){
	int valor, x, contador;
	
	printf("Informe um valor: ");
	scanf("%i", &valor);
	
	while(valor < 0){		
		printf("Informe um inteiro positivo: ");
		scanf("%i", &valor);
 }
	while(valor > 999999999){		
		printf("Informe um inteiro menor: ");
		scanf("%i", &valor);
	}	
	
	
	for(x = 1; x < valor; x + 10){
		
		contador++;
	}
	
	
	printf("\nO valor %i possui %i algarismo!", valor, contador);
	
	/*
	if(valor < 10){
		printf("\nO valor %i possui 1 algarismo!", valor);
	}else{
		if(valor < 100){
			printf("\nO valor %i possui 2 algarismos!", valor);
		}else{
			if(valor < 1000){
				printf("\nO valor %i possui 3 algarismos!", valor);
			}else{
				if(valor < 10000){
					printf("\nO valor %i possui 4 algarismos!", valor);
				}else{
					if(valor < 100000){
						printf("\nO valor %i possui 5 algarismos!", valor);
					}else{
						if(valor < 1000000){
							printf("\nO valor %i possui 6 algarismos!", valor);
						}else{
							if(valor < 10000000){
								printf("\nO valor %i possui 7 algarismos!", valor);
							}else{
								if(valor < 100000000){
									printf("\nO valor %i possui 8 algarismos!", valor);
								}else{
									if(valor < 1000000000){
										printf("\nO valor %i possui 9 algarismos!", valor);
									}else{
										if(valor < 10000000000){
											printf("\nO valor %i possui 10 algarismos!", valor);
										}else{
											if(valor < 100000000000){
												printf("\nO valor %i possui 11 algarismos!", valor);
											}											
										}										
									}									
								}								
							}							
						}						
					}					
				}				
			}			
		}		
	}*/
	printf("\n");	
}
