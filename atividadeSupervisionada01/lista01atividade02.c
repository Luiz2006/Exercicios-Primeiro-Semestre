/*
Name: CalculoDaArea
Copyright: MIT License
Author: Luiz Araujo: luizcarlos_bsb2006@hotmail.com
Date: 28/11/20 15:12
Description: calcula a área de um círculo cujo raio é fornecido pelo usuário (use área= 3.14 x raio2)
*/

#include<stdio.h>
#include<stdlib.h>

#define PI 3.14

int main(void){
	double raio, area;
	
	do{
		system("CLS");
		puts("CALCULAR AREA DO CIRCULO");
		puts("informe o raio (0 encerra): ");
		scanf("%lf", &raio);
		if(raio != 0){
			area = calcularArea(raio);
		}
	}while(raio != 0);
	
	
	
	
	
	
	
	getch();
	return 0;
}
