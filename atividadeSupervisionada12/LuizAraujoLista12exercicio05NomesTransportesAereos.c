/*
Name: 
Copyright: MIT License
Author: Luiz Araujo: luizcarlos_bsb2006@hotmail.com
Date: 30/11/20 16:47
Description: A identifica��o dos nomes de passageiros nas companhias de transporte a�reo s�o descritas obedecendo uma padroniza��o, 
onde se deve primeiro escrever o �ltimo sobrenome e em seguida o primeiro nome, separando ambos por uma barra �/�. 
Por exemplo: Edson Arantes do Nascimento teria o seu nome escrito na passagem como: Nascimento/Edson. 
Fa�a um programa que leia um nome e apresente-o na formata��o dos transportes a�reos.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
	char nome[100] = {" "};
	int indice = 0, tamanho = 0, contadorEspacos = 0, posicaoUltimoEspaco = 0, controleEspacos = 0;
	
	puts("INFORME O NOME COMPLETO:");
	fflush(stdin);
	gets(nome);
	tamanho = strlen(nome);
		
	for(indice = 0; indice < tamanho; indice++){
		if(nome[indice] == ' '){
			contadorEspacos++;
		}
	}
	
	for(indice = 0; indice < tamanho; indice++){
		if(nome[indice] == ' '){
			posicaoUltimoEspaco = indice;
		}
	}

	printf("\n\nNome na formatacao dos transportes aereos:\n");
	for(indice = (posicaoUltimoEspaco + 1); indice < tamanho; indice++){
		printf("%c", nome[indice]);
	}
	printf("/");
	
	for(indice = 0; indice < (posicaoUltimoEspaco); indice++){
		if(nome[indice] == ' '){
			break;
		}
		printf("%c", nome[indice]);
	}
//	printf(".");
	
	printf("\n\n\n\n\nPRESSIONE QUALQUER TECLA PARA ENCERRAR.\n");
	getch();
	return 0;
}








