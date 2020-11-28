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

int lerValidarHora();
struct horario conversorHora(struct horario h);
void imprime(struct horario h);

int main(void){	
	struct horario horas;
	
	horas.hora = lerValidarHora();
	horas = conversorHora(horas);
	imprime(horas);
	
	printf("\n\n\nPRESSIONE QUALQUER TECLA PARA ENCERRAR.\n");
	getch();
	return 0;
}

int lerValidarHora(){
	int hora;
	do{		
		printf("Informe a quantidade de horas: ");
		scanf("%i", &hora);	
		if(hora <= 0){
			puts("Nao pode ser menor ou igual a 0");
		}
	}while(hora <= 0);
	return hora;
}

struct horario conversorHora(struct horario h){	
	h.minuto = h.hora * 60;
	h.segundo = h.minuto * 60;	
	return h;
}

void imprime(struct horario h){
	h.minuto = h.hora * 60;
	h.segundo = h.minuto * 60;
	printf("EM HORA    -> %i", h.hora);
	printf("\nEM MINUTOS -> %i", h.minuto);
	printf("\nEM SEGUNDOS-> %i", h.segundo);
}

