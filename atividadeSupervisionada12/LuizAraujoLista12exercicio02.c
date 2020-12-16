/*
Name: 
Copyright: MIT License
Author: Luiz Araujo: luizcarlos_bsb2006@hotmail.com
Date: 28/11/20 16:54
Description: solicita o nome de cinco equipamentos de informática. 
Compara os cinco nomes fornecidos para verificar se existe algum 
solicitado em duplicidade e 
informe o usuário somente o nome duplicado.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
	char equipamentos[5][30];
	
	puts("LISTA DE PEDIDOS")
	lerValidarEquipamentos(equipamentos);
	
	getch();
	return 0;
}

void lerValidarEquipamentos(char equipamentos[][30]){
	int indice;
	for(indice = 0; indice < 5; indice++){
		printf("%i%c EQUIPAMENTO DE INFORMATICA:\n", indice + 1, 167);
		fflush(stdin);
		gets(nome[indice]);
		
	}
		puts
	
}




