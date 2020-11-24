/*
Name: Luiz Araujo
Description: Fazer um algoritmo que:
a) leia uma frase de até 80 caracteres, incluindo os brancos
b) conte quantos caracteres em branco existem na frase
c) conte quantas vezes a letra ‘a’ ou ‘A’ aparece
d) conte quantas vezes ocorre um mesmo par de letras na frase e quais são elas;
e) apresente o que foi calculado nos itens b, c e d
*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define MAX 80

int main(void){
//	declarações
	char frase[MAX], pares[MAX];
	int contador = 0, indice, indice2, qtdBranco = 0, qtdA = 0, contPares = 0;
	int qtdPar[MAX] = {0};
	
//	instruções
	puts("INFORME UMA FRASE:");
	puts(" (# para encerrar)");
	do{
		scanf("%c", &frase[contador]);
		
		if(frase[contador] == '#'){
			break;
		}
		if(contador == (MAX - 1)){
			
			puts("\n\nObs.:a capacidade maxima foi atingida, \npor isso a frase foi cortada.");	
		}
		contador++;
	}while(contador < MAX);
			printf("\n%i letras: ", contador);
			for(indice = 0; indice < contador; indice++){
				printf("%c", frase[indice]);
			}
	for(indice = 0; indice < contador; indice++){
		if(frase[indice] == ' '){
			qtdBranco++;
		}
		if(frase[indice] == 'A' || frase[indice] == 'a'){
			qtdA++;
		}		
	}	

	puts("\n\nANALISE DA FRASE");
	printf("\nCaracter em branco: %i", qtdBranco);
	printf("\nLetras 'a' ou 'A' : %i", qtdA);
	
	
	for(indice = 0; indice < (contador - 1); indice++){
		for(indice2 = (indice + 1); indice2 < contador; indice2++){
			if((frase[indice] >= 'a' && frase[indice] <= 'z')||(frase[indice] >= 'A' && frase[indice] <= 'Z')){			
				if(frase[indice] == frase[indice2]){
					qtdPar[contPares] += 1;
					pares[contPares] = frase[indice];
					frase[indice2] = '-';	//para não se repetirem as comparações dos pares
				}
			}
		}		
		contPares++;	
	}
	
	printf("\nPares de letras   :");
	for(indice = 0; indice < contPares; indice++){
		if((pares[indice] >= 'a' && pares[indice] <= 'z')||(pares[indice] >= 'A' && pares[indice] <= 'Z')){	//só mostra o elemento com pares
			if(qtdPar[indice] != 0){				
				printf("\n%c com %c: %i", pares[indice], pares[indice], qtdPar[indice]);
			}
		}
	}
	
	getch();
	return 0;
}
