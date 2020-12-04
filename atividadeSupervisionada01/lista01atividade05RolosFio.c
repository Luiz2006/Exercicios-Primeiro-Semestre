/*
Name: lista01atividade05RolosFio
Copyright: MIT License
Author: Luiz Araujo - luizcarlos_bsb2006@hotmail.com
Date: 03/12/20 17:44
Description: algoritmo para auxiliar um construtor a descobrir a 
quantidade de rolos e a quantidade de metros avulsos de fios que ele precisa 
adquirir. Sabe-se que o construtor tem a quantidade total de fios em metros a 
serem utilizados na instalação elétrica da obra e que cada rolo de fio tem 50 metros.
*/

#include<stdio.h>
#include<stdlib.h>

int main(void){
	int fios, rolos;
	float avulsos = 0;
	
	do{
		printf("QUANTIDADE TOTAL DE FIOS: ");
		scanf("%d", &fios);
		if(fios <= 0){
			puts("Quantidade invalida!");
		}
	}while(fios <= 0);	
	
	if(fios >= 50){
		rolos = fios / 50;
		avulsos = fios % 50;
		
		printf("\n\nSERA NECESSARIO");
		if(rolos == 1){
			printf("\nROLO DE FIO: %i", rolos);
		}else if(rolos >= 2){
			printf("\nROLO DE FIO: %i", rolos);
		}		
		if(avulsos >= 1){
			printf("\nFIO AVULSO : %.2fm", avulsos);
		}
	}else{
		printf("\nFIO AVULSO: %im", fios);
	}
	
	printf("\n\n\nPRESSIONE QUALQUER TECLA PARA ENCERRAR.\n");
	getch();
	return 0;
}
