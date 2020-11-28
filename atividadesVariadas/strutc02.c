/*
Name: Luiz Araujo
Copyright: MIT License
Author: luizcarlos_bsb2006@hotmail.com
Date: 28/11/20 08:35
Description: Introdu��o struct - manipulando estruturas
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
//	defini��o da estrutura
	struct horario{
		int horas;
		int minutos;
		int segundos;
		double testes;
		char letras;
	};
	
//	declara��o da estrutura
	struct horario agora;
	
//	inicializa��o dos membros/vari�veis da estrutura
	agora.horas = 15;
	agora.minutos = 17;
	agora.segundos = 30;
		
	struct horario depois;	
	depois.horas = agora.horas + 5;
	depois.minutos = agora.minutos;
	depois.segundos = 59;	
	depois.testes = 50.55 / 123;
	depois.letras = 'a';
	
	printf("%i:%i:%i", agora.horas, agora.minutos, agora.segundos);
	printf("\n%i:%i:%i", depois.horas, depois.minutos, depois.segundos);
	printf("\n%f", depois.testes);
	printf("\n%c", depois.letras);
	
	printf("\n\n\n");
	getch();
	return 0;
}


