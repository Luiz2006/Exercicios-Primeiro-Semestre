/*
Name: Manipulação de aquivos - Copiar conteúudo de um arquivo para outro
Copyright: MIT License
Author: Luiz Araujo - luizcarlos_bsb2006@hotmail.com
Date: 06/12/20 12:49
Description: manipular arquivos em c 04 - Copiar conteúdos
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

void copiarConteudo(FILE *file1, FILE *file2);

int main(void){
	setlocale(LC_ALL, "Portuguese");

	
	FILE *file1 = fopen("G:\\GitHub\\Exercicios-Primeiro-Semestre\\atividadesVariadas\\string.txt", "r");
	if(file1 == NULL){
		printf("\nERRO NA LEITURA!\n");
		sleep(5);
		exit(0);
	}
	FILE *file2 = fopen("G:\\GitHub\\Exercicios-Primeiro-Semestre\\atividadesVariadas\\petiscos2.txt", "w");
	copiarConteudo(file1, file2);
	
	fclose(file1);
	fclose(file2);	
	
	printf("\n\n\nPRESSIONE QUALQUER TECLA PARA ENCERRAR.\n");
	getch();
	return 0;
}

void copiarConteudo(FILE *file1, FILE *file2){
	char leitor[100];
	while(fgets(leitor, 100, file1) != NULL){
		fputs(leitor, file2);
	}	
}








