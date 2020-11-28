/*
Name: Luiz Araujo
Copyright: MIT License
Author: luizcarlos_bsb2006@hotmail.com
Date: 28/11/20 10:43
Description: Construa um algoritmo que leia um número inteiro de horas e 
	mostre ao usuário o correspondente em minutos e segundos destas horas.
*/
#include<stdio.h>
#include<stdlib.h>

struct horario{
	int hora;
	int minuto;
	int segundo;
};

struct horario horas;
struct horario conversorHora(struct horario h);

int main(void){	
	printf("Informe um inteiro maior que 0: ");
	scanf("%i", &horas.hora);
	
	horas = conversorHora(horas);
	
	printf("EM HORA   -> %i", horas.hora);
	printf("\nEM MINUTOS-> %i", horas.minuto);
	printf("\nEM SEGUNDO-> %i", horas.segundo);
	
	return 0;
}

struct horario conversorHora(struct horario h){	
	h.minuto = horas.hora * 60;
	h.segundo = h.minuto * 60;
	
	return h;
}

