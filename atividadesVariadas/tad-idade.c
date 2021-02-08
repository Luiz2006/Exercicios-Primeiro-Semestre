/*
Name: TAD - Idade
Copyright: MIT License
Author: Luiz Araujo - luizcarlos_bsb2006@hotmail.com
Date: 08/02/21 16:17
Description: Calcular a idade
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "tad-data.h"

int main(){
	setlocale(LC_ALL, "portuguese");
	struct rgData dt, hj;
	
	printf("Informe a sua data de nascimento (dd/mm/aaaa): \n");
	scanf("%d/%d/%d", &dt.dia, &dt.mes, &dt.ano);
	
	hj = dataHoje();
	
	printf("\nHoje é dia %.2d/%.2d/%d.\n", hj.dia, hj.mes, hj.ano);
	printf("Sua idade é: %d anos.", calculaIdade(dt));
	printf("\n\nAno dt: %d\n\n", dt.ano);
	
	return 0;
}




