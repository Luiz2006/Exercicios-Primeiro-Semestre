#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#define MAX_LETRAS 30
int main(void){
	setlocale(LC_ALL, "Portuguese");	
	char letras[MAX_LETRAS];
	int contador = 0, indice;
	
	printf(" INFORME ATÉ 30 LETRAS");
	printf("\n(de Aa a Zz, só letras)");	
	printf("\n\nOrdem normal:\n");
	do{
		letras[contador] = getche();
		if(((letras[contador] >= 'a')&&(letras[contador] <= 'z'))||((letras[contador] >= 'A')&&(letras[contador] <= 'Z'))){
			contador++;
		}else{
			break;
		}
	}while(contador < MAX_LETRAS);		
//		HORIZONTAL
	printf("\n\nOrdem inversa:\n");
	for(indice = contador - 1; indice >= 0; indice--){
		printf("%c", letras[indice]);	
	}
////		VERTICAL	
//	printf("\n\nOrdem inversa:\n");
//	for(indice = contador - 1; indice >= 0; indice--){
//		printf("\n %2iª Letra: %c", (indice + 1), letras[indice]);
//	}	
	printf("\n\n\nPRESSIONE QUALQUER TECLA PARA ENCERRAR.\n");		
	getche();
	return 0;
}
