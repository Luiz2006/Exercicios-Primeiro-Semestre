/*
Name: lista02atividade01Multa
Copyright: MIT License
Author: Luiz Araujo - luizcarlos_bsb2006@hotmail.com
Date: 03/12/20 21:34
Description: algoritmo que a partir da leitura da velocidade e placa do carro, 
avise ao motorista somente se ele será multado, quando estiver trafegando no Eixo Rodoviário (limite de 80 km/h).
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
	int velocidade;
	char placa[8];
	
	puts("INFORME A PLACA: ");
	fflush(stdin);
	gets(placa);
	puts("VELOCIDADE: ");
	fflush(stdin);
	scanf("%d", &velocidade);
	
	system("CLS");
	if(velocidade > 80){
		printf("MULTA POR TRAFEGAR ACIMA DA VELOCIDADE PERMITIDA(80km/h)");
		printf("\nVEICULO	: %s", placa);
		printf("\nVELOCIDADE: %d", velocidade);
	}
	
	printf("\n\n\nPRESSIONE QUALQUER TECLA PARA ENCERRAR.\n");
	getch();
	return 0;
}
