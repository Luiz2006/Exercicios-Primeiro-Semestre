/*
Name: lista02atividade03Triangulo
Copyright: MIT License
Author: Luiz Araujo - luizcarlos_bsb2006@hotmail.com
Date: 04/12/20 10:59
Description: Dado três valores, verificar se eles podem 
constituir os lados de um triângulo (triângulo é uma figura 
geométrica onde cada lado é menor do que a soma dos outros 
dois lados).
*/

#include<stdio.h>
#include<string.h>

void analisarValores(float val[], char msg[]);

int main(void){
	float valores[3];
	char mensagem[18];
	puts("INFORME TRES VALORES: ");
	scanf("%f%f%f", &valores[0], &valores[1], &valores[2]);
	
	analisarValores(valores, mensagem);
	
	puts(mensagem);
	return 0;
}

void analisarValores(float val[], char msg[]){
	int flag = 0;
	
	if(val[0] < (val[1] + val[2])){	
		flag++;
	}
	if(val[1] < (val[0] + val[2])){	
		flag++;
	}
	if(val[2] < (val[0] + val[1])){	
		flag++;
	}
	
	if(flag == 3){
		strcpy(msg, "Os valores informados podem constituir os lados de um triangulo");
	}else{
		strcpy(msg, "Os valores informados NAO podem constituir os lados de um triângulo");
	}
}
