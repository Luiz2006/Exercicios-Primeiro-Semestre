#include<stdio.h>
#define MAX 80
int main(void){
	int elementos[MAX], posicoes[MAX];	int contador = 0, contadorRepetidos, repetidos, novo;
//	zerar elementos (estava ficando armazenado depois de fechar)
	while(contador < MAX){
		elementos[contador] = 0;
		contador++;
	}
	contador = 0;	
	printf("INFORME NUMEROS INTEIROS\n");
	printf("  (-1 para finalizar)\n");	
	while(contador < MAX){	
			printf("%2i%c Numero: ", (contador + 1), 166);
			scanf("%i", &elementos[contador]);
		if(elementos[contador] != -1){
			contador++;
		}else{
			
			contador = MAX;
		}
	}
	printf("\nInforme um numero para comparacao: ");
	scanf("%i", &novo);		
	for(contadorRepetidos = 0; contadorRepetidos <= contador; contadorRepetidos++){
		if(elementos[contadorRepetidos] == novo){
			posicoes[contadorRepetidos] = 1;
			repetidos++;
		}else{
			posicoes[contadorRepetidos] = 0;
		}		
	}		
	system("CLS");
	printf("\nQUANTIDADE NUMEROS IGUAIS A %i: %i", novo, repetidos);
	if(repetidos > 0){
		printf("\nLOCAL: ");
		for(contadorRepetidos = 0; contadorRepetidos < MAX; contadorRepetidos++){
			if(posicoes[contadorRepetidos] == 1){				
				printf("\n%2i%c POSICAO", contadorRepetidos + 1, 166);	
			}
		}
	}else{
		printf("\nNAO HA CORRESPONDENCIAS");
	}	
	printf("\n\n\nPRESSIONE QUALQUER TECLA PARA ENCERRAR.\n");		
	getche();
	return 0;
}
