#include<stdio.h>
#include<locale.h>
int main(){
    setlocale(LC_ALL, "Portuguese");
    
    int op, cadeira = 0, mesaPc = 0, mesaImp = 0, estLiv = 0, estCd = 0;
    char continuar;

	do{
	    printf("Qual o m�vel solicitado? ");
	    scanf("%i", &op);
	    
	    switch(op){
	        case 1: printf("Cadeira selecionada.");
	                ++cadeira;
	                break;
	        case 2: printf("Mesa de computador.");
	                ++mesaPc;
	                break;
	        case 3: printf("Estante de livros selecionada.");
	                ++estLiv;
	                break;
	        case 4: printf("Mesa de impressora selecionada.");
	                ++mesaImp;                    
	                break;
	        case 5: printf("Estante de CD selecionada.");
	                ++estCd;
	                break;
	        default: printf("M�vel ainda n�o est� dispon�vel.");
	    }
    	
    	printf("\n\nNovo m�vel? ");
    	continuar = getche();    	
    	system("CLS");
	}while(continuar == 's' || continuar == 'S');

	printf("SELE��ES\n");
	printf("Cadeira: %i.\n", cadeira);
	printf("Mesa de computador: %i.\n", mesaPc);
	printf("Estante de livros: %i.\n", mesaImp);
	printf("Mesa de impressora: %i.\n", estLiv);
	printf("Estante de CD: %i.\n", estCd);
    
    return 0;
}
