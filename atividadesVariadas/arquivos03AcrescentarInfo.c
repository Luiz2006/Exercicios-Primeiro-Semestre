/*
Name: Manipulação de aquivos - Anexar info no arquivo .txt
Copyright: MIT License
Author: Luiz Araujo - luizcarlos_bsb2006@hotmail.com
Date: 06/12/20 12:31
Description: manipular arquivos em c 03 - Anexar info no arquivo .txt
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

int main(void){
	setlocale(LC_ALL, "Portuguese");
	int x, y, z, indice;
	char lista[100][100];

	x = y = z = indice = 0;
	FILE *file;
	
	
	//acrescentar no arquivo
	file = fopen("string.txt", "a");
	if(file == NULL){
		printf("\nERRO NA LEITURA!\n");
		sleep(5);
		exit(0);
	}else{
		fprintf(file, "PRIMEIRA LINHA\n");//insere uma linha
	
		char frase[] = "SEGUNDA LINHA\n";
		fputs(frase, file);//insere vertor de caracteres//server nos "a" e "w" tbm
	
		char caractere = '3'; 
		fputc(caractere, file);//insere caractere
	}
	
	
	
	
	
	
	//ler arquivo
	
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
	
	printf("\n\n\n%s", lista[2]);
	printf("\n\n\n%s", lista[20]);
	printf("\n\n\n%s", lista[25]);
	printf("\n\n\n%s", lista[30]);
	
	fclose(file);
	
	
	printf("\n\n\nPRESSIONE QUALQUER TECLA PARA ENCERRAR.\n");
	getch();
	return 0;
}









