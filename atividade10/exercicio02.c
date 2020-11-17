/*
Name: Luiz Araujo
Copyright: MIT License
Date: 16/11/20 08:16
Description: programa que aciona uma função que apresenta as opções de menu com as seguintes concessionárias de veículos: FIAT, CHEVROLET e FORD. 
		Dá opções dentre os carros disponíveis. Identifica qual a opção escolhida e apresenta as respectivas opções dos carros disponíveis, 
		A concessionária escolhida deve acionar outra função que apresenta somente os veículos disponíveis da marca especificada. 
		Para cada concessionária deve existir uma função específica com os carros disponíveis. 
		Após identificar o carro escolhido pelo usuário, apresenta no centro de uma janela limpa uma mensagem de agradecimento, o nome do carro escolhido e o nome do cliente.
*/

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<ctype.h>

void apresentaMenuConcessionaria(char marcas[3][10]);
char apresentaFiat(char marcas[10], char fiat[3][10]);
char apresentaChevrolet(char marcas[10], char fiat[3][10]);
char apresentaFord(char marcas[10], char fiat[3][10]);

int main(void){
//	setlocale(LC_ALL, "Portuguese");
	fflush(stdin);
//	declarações
	char marcas[3][10] = {"FIAT", "CHEVROLET", "FORD"};
	char fiat[3][10] = {"Argo", "Punto", "Palio"};
	char chevrolet[3][10] = {"Prisma", "S10", "Onix"};
	char ford[3][10] = {"Fusion", "Ranger", "Ka"};
	char nome[30];
	char sexo;
	int escolha[2];
	
//	instruções

	printf("Ola, por gentileza, informe seu nome: ");
	scanf("%s", nome);
	printf("Sexo[f / m]: ");
	getche("%c", &sexo);
	
	apresentaMenuConcessionaria(marcas);
	
	printf("Escolha uma marca para verificar os carros disponiveis: ");
	scanf("%i", &escolha[0]);
	
	printf("\n");
	switch(escolha[0]){
		case 1:	
			apresentaFiat(marcas[0], fiat);
			
			printf("Qual carro deseja? ");
			scanf("%i", &escolha[1]);

			break;
		case 2: 				
			apresentaChevrolet(marcas[1], chevrolet);
			
			printf("Qual carro deseja? ");
			scanf("%i", &escolha[1]);						
			break;
		case 3: 		
			apresentaFord(marcas[2], ford);	
			
			printf("Qual carro deseja? ");
			scanf("%i", &escolha[1]);				
			break;
		default:
			break;
			
	}
	
	
	system("CLS");
	if((sexo == 'f')||(sexo == 'F')){	
		if(escolha[0] == 1){
			switch(escolha[1]){
				case 1:
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tObrigado por escolher o FIAT Argo, sra. %s.", nome);
					break;
				case 2:
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tObrigado por escolher o FIAT Punto, sra. %s.", nome);
					break;
				case 3:
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tObrigado por escolher o FIAT Palio, sra. %s.", nome);
					break;
			}
		}else{			
			if(escolha[0] == 2){
				switch(escolha[1]){
					case 1:
						printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tObrigado por escolher o CHEVROLET Prisma, sra. %s.", nome);
						break;
					case 2:
						printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tObrigado por escolher o CHEVROLET S10, sra. %s.", nome);
						break;
					case 3:
						printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tObrigado por escolher o CHEVROLET Onix, sra. %s.", nome);
						break;
				}
			}else{
						
				if(escolha[0] == 3){
					switch(escolha[1]){
						case 1:
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tObrigado por escolher o FORD Ka, sra. %s.", nome);
							break;
						case 2:
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tObrigado por escolher o CHEVROLET Ranger, sra. %s.", nome);
							break;
						case 3:
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tObrigado por escolher o CHEVROLET Fusion, sra. %s.", nome);
							break;
					}
				}
			}
		}				
	}else{
		if(escolha[0] == 1){
			switch(escolha[1]){
				case 1:
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tObrigado por escolher o FIAT Argo, sr. %s.\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n", nome);
					break;
				case 2:
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tObrigado por escolher o FIAT Punto, sr. %s.\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n", nome);
					break;
				case 3:
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tObrigado por escolher o FIAT Palio, sr. %s.\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n", nome);
					break;
			}
		}else{			
			if(escolha[0] == 2){
				switch(escolha[1]){
					case 1:
						printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tObrigado por escolher o CHEVROLET Prisma, sr. %s.\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n", nome);
						break;
					case 2:
						printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tObrigado por escolher o CHEVROLET S10, sr. %s.\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n", nome);
						break;
					case 3:
						printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tObrigado por escolher o CHEVROLET Onix, sr. %s.\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n", nome);
						break;
				}
			}else{
						
				if(escolha[0] == 3){
					switch(escolha[1]){
						case 1:
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tObrigado por escolher o FORD Ka, sr. %s.\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n", nome);
							break;
						case 2:
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tObrigado por escolher o CHEVROLET Ranger, sr. %s.\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n", nome);
							break;
						case 3:
							printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tObrigado por escolher o CHEVROLET Fusion, sr. %s.\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n", nome);
							break;
					}
				}
			}
		}	
	}
}

void apresentaMenuConcessionaria(char marcas[3][10]){
	printf("\nCONCESSIONARIA\n");
	printf("1 - %-10s\n", marcas[0]);
	printf("2 - %-10s\n", marcas[1]);
	printf("3 - %-10s\n", marcas[2]);
}

char apresentaFiat(char marcas[10], char fiat[3][10]){
	int escolher;
	printf("  %-10s\n", marcas);
	
	printf("1 - %-10s\n", fiat[0]);
	printf("2 - %-10s\n", fiat[1]);
	printf("3 - %-10s\n", fiat[2]);	
	
}

char apresentaChevrolet(char marcas[10], char chevrolet[3][10]){
	int escolher;
	printf("  %-10s\n", marcas);
	
	printf("1 - %-10s\n", chevrolet[0]);
	printf("2 - %-10s\n", chevrolet[1]);
	printf("3 - %-10s\n", chevrolet[2]);	
	
}

char apresentaFord(char marcas[10], char ford[3][10]){
	int escolher;
	printf("  %-10s\n", marcas);
	
	printf("1 - %-10s\n", ford[0]);
	printf("2 - %-10s\n", ford[1]);
	printf("3 - %-10s\n", ford[2]);	
	
}
