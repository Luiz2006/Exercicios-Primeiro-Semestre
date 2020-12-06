/*
Name: Manipulação de aquivos - criar
Copyright: MIT License
Author: Luiz Araujo - luizcarlos_bsb2006@hotmail.com
Date: 06/12/20 10:57
Description: manipular arquivos em c 00criar
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
	FILE *file;
	
//	file = fopen("G:\\GitHub\\Exercicios-Primeiro-Semestre\\arquivos\\teste.txt", "w");//faz com que o file/ponteiro aponte para um aquivo//parâmetros 2 strings: ("endeço+nome do arquivo", "o que fara com o arquivo");
	if(!(file = fopen("string.txt", "a"))){
	//faz com que o file/ponteiro aponte para um aquivo//parâmetros 2 strings: ("endeço+nome do arquivo", "o que fara com o arquivo");
	//o "a" acrescenta ao final do arquivo txt
	//"r" só lê
	//"w" subscreve o que estava lá		
		printf("ERRO AO ABRIR O ARQUIVO!\n");	
	}else{
		fprintf(file, "Pao com mortadela\n");
		printf("Aquivo alterado com sucesso!\n");
	}
	
	fclose(file);
	








	
	printf("\n\n\nPRESSIONE QUALQUER TECLA PARA ENCERRAR.\n");
	getch();
	return 0;
}








