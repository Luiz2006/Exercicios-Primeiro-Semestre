/*
Name: LuizAraujoLista12exercicio07FraseAosCandidatos
Copyright: MIT License
Author: Luiz Araujo: luizcarlos_bsb2006@hotmail.com
Date: 03/12/20 16:28
Description: programa que armazena uma frase a ser transmitida aos 
candidatos da pr�xima elei��o com at� 50 caracteres. Ap�s o armazenamento da frase, 
solicite o primeiro nome do candidato e transforme-o todo em mai�sculo, concatenando-o 
com a frase, al�m de dois pontos. O resultado dever� ser apresentado a partir da linha 5. 
Ap�s a apresenta��o o programa dever� ser encerrado imediatamente ap�s 10 segundos 
(ver fun��o sleep).
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.c>

int main(void){
	char frase[50],candidato[30], mensagem[85];
	
//	instru��es
	puts("INFORME UMA FRASE A SER TRANSMITIDA AOS CANDIDATOS:");
	fflush(stdin);
	gets(frase);
	
	puts("INFORME DO CANDIDATO:");
	fflush(stdin);
	gets(candidato);
	strupr(candidato);
	
	system("CLS");
	gotoxy(40, 5);
	strcpy(mensagem, candidato);
	strcat(mensagem, ": ");
	strcat(mensagem, frase);
	
	puts(mensagem);
	sleep(10);	
	
//	gotoxy(1, 22);
	return 0;
}



