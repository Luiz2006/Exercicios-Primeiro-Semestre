/*
Name: 
Copyright: MIT License
Author: Luiz Araujo - luizcarlos_bsb2006@hotmail.com
Date: 09/12/20 21:12
Description: 
*/
#include<stdio.h>
#include<stdlib.h>

int main(void){
	FILE *f1, *f2;
	
	f1 = fopen("minusculo.txt", "r");
	f2 = fopen("maiusculo.txt", "w");
	if(f1 == NULL || f2 == NULL){
		int cont = 5;
		while(cont > 0){
			system("CLS");
			if(f1 == NULL){
				printf("Erro ao abrir o arquivo \"minusculo.txt\".");
			}
			if(f2 == NULL){
				printf("\nErro ao abrir o arquivo \"maiusculo.txt\".");
			}
			printf("\nENCERRANDO EM: ");
			printf("%i", cont);
			sleep(1);
			cont--;
			if(cont == 0){
				system("CLS");
				if(f1 == NULL){
					printf("Erro ao abrir o arquivo \"minusculo.txt\".");
				}
				if(f2 == NULL){
					printf("\nErro ao abrir o arquivo \"maiusculo.txt\".");
				}
				printf("\nENCERRANDO EM: ");
//				printf("FIM");
				printf("KABOOOOM");
			}
		}		
		exit(1);
	}
	
	char c = fgetc(f1);
	while(c != EOF){
		fputc(toupper(c), f2);
		c = fgetc(f1);
	}
	
	fclose(f1);
	fclose(f2);
	
	
	
	printf("\n\n\nPRESSIONE QUALQUER TECLA PARA ENCERRAR.\n");
	getch();
	return 0;
}





