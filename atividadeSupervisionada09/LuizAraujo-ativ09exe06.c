#include<stdio.h>
int main(void){
	int valor, contador = 0, controle = 1;
	
	printf("Informe um valor: ");
	printf("(maximo: 1.000.000.000)\n");
	scanf("%i", &valor);
	
	while(valor - controle >= 0){
		contador++;			
		controle = controle * 10;
	}
	if(contador <= 1){
		printf("\nQuantidade de algarismo: %i", contador);
	}else{
		printf("\nQuantidade de algarismos: %i", contador);
	}
	
////vou deixar o histórico de como eu cheguei nessa solução kkkk'
////2ª solução
//	controle = 1000000000;
//	while(controle > 0){
//		if(valor - controle >= 0){
//			contador++;
//		}		
//		controle = controle / 10;
//	}
	
////1ª solução
//	while(valor < 0){		
//		printf("Informe um inteiro positivo: ");
//		scanf("%i", &valor);
//	}
//	while(valor > 999999999){		
//		printf("Informe um inteiro menor: ");
//		scanf("%i", &valor);
//	}	
//	
//	if(valor < 10){
//		printf("\nO valor %i possui 1 algarismo!", valor);
//	}else{
//		if(valor < 100){
//			printf("\nO valor %i possui 2 algarismos!", valor);
//		}else{
//			if(valor < 1000){
//				printf("\nO valor %i possui 3 algarismos!", valor);
//			}else{
//				if(valor < 10000){
//					printf("\nO valor %i possui 4 algarismos!", valor);
//				}else{
//					if(valor < 100000){
//						printf("\nO valor %i possui 5 algarismos!", valor);
//					}else{
//						if(valor < 1000000){
//							printf("\nO valor %i possui 6 algarismos!", valor);
//						}else{
//							if(valor < 10000000){
//								printf("\nO valor %i possui 7 algarismos!", valor);
//							}else{
//								if(valor < 100000000){
//									printf("\nO valor %i possui 8 algarismos!", valor);
//								}else{
//									if(valor < 1000000000){
//										printf("\nO valor %i possui 9 algarismos!", valor);
//									}else{
//										if(valor < 10000000000){
//											printf("\nO valor %i possui 10 algarismos!", valor);
//										}else{
//											if(valor < 100000000000){
//												printf("\nO valor %i possui 11 algarismos!", valor);
//											}											
//										}										
//									}									
//								}								
//							}							
//						}						
//					}					
//				}				
//			}			
//		}		
//	}
	printf("\n\n\nPRESSIONE QUALQUER TECLA PARA ENCERRAR.\n");		
	getche();		
	
	return 0;
}
