/*
Name: Luiz Araujo
Copyright: MIT License
Author: luizcarlos_bsb2006@hotmail.com
Date: 28/11/20 08:35
Description: Introdução struct
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
	//definição da estrutura
	struct horario{
		int horas;
		int minutos;
		int segundos;
	};
	
	//declaração da estrutura
	struct horario agora;
	
	inicialização
	agora.horas = 15;
	agora.minutos = 17;
	agora.segundos = 30;
		
	printf("%i:%i:%i", agora.horas, agora.minutos, agora.segundos);
	
	getch();
	return 0;
}


