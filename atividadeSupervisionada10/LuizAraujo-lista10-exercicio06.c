#include<stdio.h>
#include<stdlib.h>
void apresentarLetras(char letra);
int main(void){
//	declarações
	char letra;	
	
//	instruções
	printf("Informe uma letra do alfabeto: ");
	scanf("%c", &letra);
	apresentarLetras(letra);
}
void apresentarLetras(char letra){	
	if((letra >= 'a') &&(letra <= 'z')){
		while(letra <= 'z'){
			printf("[%c] - ", letra);
			letra++;
		}
	}	
	if((letra >= 'A') && (letra <= 'Z')){
		while(letra <= 'Z'){
			printf("[%c] - ", letra);
			letra++;
		}
	}	
}





