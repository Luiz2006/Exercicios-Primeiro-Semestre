/*
Name: CalculoDaArea
Copyright: MIT License
Author: Luiz Araujo: luizcarlos_bsb2006@hotmail.com
Date: 28/11/20 15:12
Description: calcula a área de um círculo cujo raio.
*/

#include<stdio.h>
#include<stdlib.h>

#define PI 3.14

double calcularArea(double raio);
void mensagemResultado(double area);

int main(void){
	double raio, area;
	char continuar;
	do{
		system("CLS");
		puts("CALCULAR AREA DO CIRCULO");
		puts("\nInforme o raio (0 encerra): ");
		scanf("%lf", &raio);
		if(raio == 0){
			break;
		}
		area = calcularArea(raio);
		mensagemResultado(area);
		puts("\n\nNovo calculo? (s - para sim)");
		continuar = getche();
		continuar = tolower(continuar);
	}while(continuar == 's');
	puts("\n\n");
	system("PAUSE");
	return 0;
}

double calcularArea(double raio){
	return raio * raio * PI;
}
void mensagemResultado(double area){
	printf("AREA: %f", area);
}













