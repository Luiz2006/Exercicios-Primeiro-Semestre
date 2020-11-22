#include<stdio.h>
main(){
	int valor, controle, fatorial = 1, numero;
	
for (fatorial=1; numero>1 ; numero = numero-1){
		fatorial = fatorial*numero; 
	}
		printf ("O valor calculado para esse fatorial: \n %i", fatorial );
	return 0;
}

