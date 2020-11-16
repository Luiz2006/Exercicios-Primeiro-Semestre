/*
	Name: Luiz Araujo
	Copyright: MIT License
	Author: luizcarlos_bsb2006@hotmail.com
	Date: 15/11/20 10:27
	Description: construir um algoritmo que leia um número inteiro de horas e 
		mostre ao usuário o correspondente em minutos e segundos destas horas.
*/

#include<stdio.h>
#include<stdlib.h>

int main() {	
	//declarações
	int horas;
	
	//instruções
    printf("TRANSFORMAR HORAS EM MINUTOS E SEGUNDOS");
	
	do{	
	    printf("\nHoras: ");
	    scanf("%i", &horas);	
		if(horas < 1){
			printf("Insira um valor inteiro acima de 0!\n");
		}
	}while(horas < 1);	
	
	if(horas == 1){
		printf("\n%i hora: %i minutos.", horas, (horas * 60));
		printf("\n%i hora: %i segundos.", horas, (horas * 3600));
	}else{
		printf("\n%i horas: %i minutos.", horas, (horas * 60));
		printf("\n%i horas: %i segundos.", horas, (horas * 3600));
	}
	
    return 0;
}
