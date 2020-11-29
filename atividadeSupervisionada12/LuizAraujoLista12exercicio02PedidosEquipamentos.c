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

void lerValidarEquipamentos(char equipamentos[][30]);
void verificarDuplicado(char equipamentos[][30]);

int main(void){
	int indice;
	char equipamentos[5][30];
	
	puts("LISTA DE PEDIDOS");
	lerValidarEquipamentos(equipamentos);
	verificarDuplicado(equipamentos);
//	for(indice = 0; indice < 5; indice++){
//		printf("%i%c EQUIPAMENTO: %s\n", indice + 1, 167, equipamentos[indice]);		
//	}
//	
	getch();
	return 0;
}

void lerValidarEquipamentos(char equipamentos[][30]){
	int indice;
	for(indice = 0; indice < 5; indice++){
		do{
			printf("%i%c EQUIPAMENTO DE INFORMATICA:\n", indice + 1, 167);
			fflush(stdin);
			gets(equipamentos[indice]);
			if(strlen(equipamentos[indice]) <= 1){
				puts("Preenchimento obrigatorio!");
			}
		}while(strlen(equipamentos[indice]) <= 1);
	}
}
void verificarDuplicado(char equipamentos[][30]){
	int indice, indice2, cont = 0, repetidos[5];
	for(indice = 0; indice < 4; indice++){
		cont = 0;
		for(indice2 = (indice + 1); indice2 < 5; indice2++){
			if(strcmp(equipamentos[indice],equipamentos[indice2]) == 0){
				cont++;
				break;
			}
		}
		if(cont > 0){
			printf("\nO %i%c JA FOI INFORMADO:  - %s", indice + 1,167,  equipamentos[indice]);	
		}
	}
}










