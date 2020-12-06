/*
Name: Manipulação de aquivos - ler
Copyright: MIT License
Author: Luiz Araujo - luizcarlos_bsb2006@hotmail.com
Date: 06/12/20 10:57
Description: manipular arquivos em c 01 - ler
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
	int x, y, z;
	x = y = z = 0;
	FILE *file;
	
	if(!(file = fopen("numero.txt", "r"))){
		printf("\nERRO NA LEITURA!\n");
	}else{
		printf("\n%d %d %d", x, y, z);
		
//		scanf("%i %i %i", &x, &y, &z);//scanf normal
		fscanf(file, "%d %d %d", &x, &y, &z);//escaneia dados no arquivo .txt
		
		printf("\n%d %d %d", x, y, z);
	}
	
	fclose(file);
	
	
	printf("\n\n\nPRESSIONE QUALQUER TECLA PARA ENCERRAR.\n");
	getch();
	return 0;
}








