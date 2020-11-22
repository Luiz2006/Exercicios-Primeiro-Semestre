/*
Name: Luiz Araujo
Description: algoritmo que ler até 30 letras e as escreve na ordem inversa (ou contrária) da que foram lidas.
*/

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

#define MAX_LETRAS 30
int main(void){
	setlocale(LC_ALL, "Portuguese");
	
	char letras[MAX_LETRAS];
	int contador = 0,contador2 = 0;
	
	printf("INFORME ATÉ 30 LETRAS\n");
	printf(" (ENTER para parar)");
	
////		VERTICAL
/*	printf("\n\nOrdem normal:\n");
	do{
		printf("\n %3iª Letra: ", contador + 1);		
		letras[contador] = getche();
		if(((letras[contador] >= 'a')&&(letras[contador] <= 'z'))||((letras[contador] >= 'A')&&(letras[contador] <= 'Z'))){
			contador++;
			contador2++;
		}else{
			contador = MAX_LETRAS;
		}
		
	}while((contador < MAX_LETRAS) && (letras[contador] != '\n'));
	printf("\n\nOrdem inversa:\n");
	for(contador = (contador2 - 1); contador >= 0; contador--){
		printf("\n %3iª Letra: %c", (contador + 1), letras[contador]);
	}
*/
////		HORIZONTAL
	printf("\n\nOrdem normal:\n");
	do{
		
				
		letras[contador] = getche();
		if(((letras[contador] >= 'a')&&(letras[contador] <= 'z'))||((letras[contador] >= 'A')&&(letras[contador] <= 'Z'))){
			contador++;
			contador2++;
		}else{
			contador = MAX_LETRAS;
		}
		
	}while((contador < MAX_LETRAS) && (letras[contador] != '\n'));	
	
	printf("\n\nOrdem inversa:\n");
	for(contador = contador2; contador >= 0; contador--){
		printf("%c", letras[contador]);	
	}
	
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	system("PAUSE");
	return 0;
}
