/*
Name: 
Copyright: MIT License
Author: Luiz Araujo: luizcarlos_bsb2006@hotmail.com
Date: 28/11/20 15:39
Description: L� o nome completo de 2 pessoas e apresenta o 
primeiro nome somente em letras mai�sculas e na linha seguinte, 
com uma tabula��o, o segundo nome em letras min�sculas, 
solicitando outros nomes caso o usu�rio deseje. 
Somente devem ser usadas fun��es do padr�o ANSI da linguagem C.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void lerValidarNome(char nome[2][30]);
void capitular(char nome[2][30]);

int main(void){
	char nome[2][30], continuar;
	do{	
		lerValidarNome(nome);
		capitular(nome);
		
		printf("\n\n\nNovamente? (s - para continuar)");
		continuar = getche(continuar);
		continuar = tolower(continuar);
	}while(continuar == 's');	
	
	getch();
	return 0;
}

void lerValidarNome(char nome[2][30]){
	system("CLS");
	puts("INFORME");
	printf("NOME COMPLETO 1%c PESSOA:\n", 166);
	fflush(stdin);
	gets(nome[0]);
	printf("NOME COMPLETO 2%c PESSOA:\n", 166);
	fflush(stdin);
	gets(nome[1]);
}

void capitular(char nome[2][30]){
	strupr(nome[0]);
	printf("\n%s", nome[0]);
	strlwr(nome[1]);
	printf("\n\t%s", nome[1]);	
}




