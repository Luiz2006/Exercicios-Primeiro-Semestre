/*
Name: Luiz Araujo
Copyright: MIT License
Author: luizcarlos_bsb2006@hotmail.com
Date: 28/11/20 10:09
Description: Introdução Struct - Inicializando Estruturas
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
	
int main(void){
	struct horario{
		int horas;
		int minutos;
		int segundos;
//	};//já pode declarar um var do tipo struct horário por ex...
	}agora, teste = {}, depois = {10}, proxima = {30, 40, 50};
//	struct horario agora;//aí não precisa declarar dessaforma
	
	agora.horas = 1;
	agora.minutos = 2;
	agora.segundos = 3;
		
	struct horario nunca = {40, 50};
	struct horario sempre = {.segundos = 10, .horas= 24};
	
	printf("agora  : %i:%i:%i\n", agora.horas, agora.minutos, agora.segundos);
	printf("teste  : %i:%i:%i\n", teste.horas, teste.minutos, teste.segundos);
	printf("depois : %i:%i:%i\n", depois.horas, depois.minutos, depois.segundos);
	printf("proxima: %i:%i:%i\n", proxima.horas, proxima.minutos, proxima.segundos);	
	printf("nunca: %i:%i:%i\n", nunca.horas, nunca.minutos, nunca.segundos);		
	printf("sempre: %i:%i:%i\n", sempre.horas, sempre.minutos, sempre.segundos);	
	
	printf("\n\n\n");
	getch();
	return 0;
}


