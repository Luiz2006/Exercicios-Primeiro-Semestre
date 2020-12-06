/*
Name: Manipulação de aquivos
Copyright: MIT License
Author: Luiz Araujo - luizcarlos_bsb2006@hotmail.com
Date: 06/12/20 08:38
Description: manipular arquivos em c 01
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(void){
	FILE *arq;
	char buffer[50];
	int i;
	
	printf("Escrita: \n\n");
	
	if(!(arq = fopen("G:\\GitHub\\Exercicios-Primeiro-Semestre\\arquivos\\arq1.txt", "w"))){
			printf("Erro! \n");
	}else{
		sprintf(buffer, "Numeros de 1 a 10\n");//por a string na var buffer
		fputs(buffer, arq);//por a var buffer no arquivos (fará um titulo)
		for(i = 1; i <= 10; i++){
			fprintf(arq, "%d \n", i);//poe numeros de 1 a 10 no arquivo
		}
		printf("Sucesso! \n\n");
	}
	fclose(arq);
	
	printf("Leitura: \n\n");
	
	char *titulo[40];
	int numeros[10];
	
	if(!(arq = fopen("G:\\GitHub\\Exercicios-Primeiro-Semestre\\arquivos\\arq1.txt", "r"))){
		printf("Erro na leitura!\n");
	}else{
		fgets(titulo, 40, arq);
		printf("Titulo: %s", titulo);
		for(i = 0; i < 10; i++){
			fscanf(arq, "%d", &numeros[i]);
			printf("%d \n", numeros[i]);
		}
	}
	fclose(arq);
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	printf("\n\n\nPRESSIONE QUALQUER TECLA PARA ENCERRAR.\n");
	getch();
	return 0;
}




