#include<stdio.h>
#define LIMITE 100
int main(void){
//	declarações
	long int dados[LIMITE], somatorio = 0;
	int contador = 0, contador2;	
//	intruções
	printf("INFORME NUMEROS PARA SOMATORIO");
	printf("\n     (0 para finalizar)\n\n");	
	do{
		printf("%2i%c Numero: ", contador + 1, 167);
		scanf("%i", &dados[contador]);
		if(contador > 1 && dados[contador] == 0){
			break;
		}
		while(contador <= 1 && dados[contador] == 0){
			printf("Deve haver pelo menos dois numeros!\n");
			printf("%2i%c Numero: ", contador + 1, 167);
			scanf("%i", &dados[contador]);
		}
		somatorio += dados[contador];
		contador++;
	}while(contador < LIMITE);	
	printf("\nSomatorio: ");
	for(contador2 = 0; contador2 < contador; contador2++){
		if(contador2 > 0 && contador2 < contador){
			printf(" + ");
		}		
		printf("%i", dados[contador2]);
	}
	printf(" = %i", somatorio);	
	printf("\n\n\nPRESSIONE QUALQUER TECLA PARA ENCERRAR.\n");		
	getche();		
	return 0;
}
