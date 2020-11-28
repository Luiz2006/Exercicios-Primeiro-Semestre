/*
Name: Luiz Araujo
Copyright: MIT License
Author: luizcarlos_bsb2006@hotmail.com
Date: 28/11/20 09:24
Description: Introdução cast
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
	int x = 16;
	int y = 3;
	
//	float resultado = x / y;
	float resultado = (float)x / y;
	
	printf("%f\n", resultado);
	
	printf("\n\n\n");
	getch();
	return 0;
}


