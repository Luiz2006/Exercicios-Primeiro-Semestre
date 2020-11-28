/*
Name: Luiz Araujo
Copyright: MIT License
Author: luizcarlos_bsb2006@hotmail.com
Date: 28/11/20 09:36
Description: Introdução Struct - struct global passada como parâmetro
					para uma função que retorna struct
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//struct horario: retorno da função, uma estruttura do tipo horario
//teste: nome da funçãoo
//(struct horario x): está passando uma outra estrutura como parâmetro/argumento
struct horario teste(struct horario x);


struct horario{
	int horas;
	int minutos;
	int segundos;
};
	
int main(void){
	
	struct horario agora;
	agora.horas = 10;
	agora.minutos = 42;
	agora.segundos = 58;
	
	struct horario proxima;
	proxima = teste(agora);
	
	printf("\n\n\n");
	printf("%i:%i:%i\n", agora.horas, agora.minutos, agora.segundos);
	printf("%i:%i:%i\n", proxima.horas, proxima.minutos, proxima.segundos);
	
	printf("\n\n\n");
	getch();
	return 0;
}

struct horario teste(struct horario x){
	printf("%i:%i:%i\n", x.horas, x.minutos, x.segundos);
	
	x.horas = 1;
	x.minutos = 2;
	x.segundos = 3;
	printf("%i:%i:%i\n", x.horas, x.minutos, x.segundos);
	
	return x;
}


