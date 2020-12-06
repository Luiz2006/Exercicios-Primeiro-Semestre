/*
Name: Manipulação de aquivos - ler
Copyright: MIT License
Author: Luiz Araujo - luizcarlos_bsb2006@hotmail.com
Date: 06/12/20 11:50
Description: manipular arquivos em c 02 - ler sem fscanf
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

int main(void){
	setlocale(LC_ALL, "Portuguese");
	int x, y, z, indice;
	char lista[100][100];
//	char lista[][100];

	x = y = z = indice = 0;
	FILE *file;
	
	if(!(file = fopen("string.txt", "r"))){
		printf("\nERRO NA LEITURA!\n");
		sleep(5);
		exit(0);
	}else{
		while(fgets(lista[indice], 100, file) != NULL){
			printf("%3d - %s", indice, lista[indice]);
			indice++;
		}
	}
	
//	printf("\n\n\n%s", lista[2]);
//	printf("\n\n\n%s", lista[20]);
//	printf("\n\n\n%s", lista[25]);
//	printf("\n\n\n%s", lista[30]);
	
	fclose(file);
	
	
	printf("\n\n\nPRESSIONE QUALQUER TECLA PARA ENCERRAR.\n");
	getch();
	return 0;
}









