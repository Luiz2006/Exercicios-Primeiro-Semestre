#include<stdio.h>
#include<locale.h>
main(){
	setlocale(LC_ALL, "Portuguese");
	float nascimentos, meses, qtdMortes = 0, qtdMortesMasc = 0, qtdMortes24 = 0, porcentagemMortes, porcentagemMortesMasc, porcentagemMortes24;
	char continuar, sexo;
	int contador = 0;
	
	printf("�NDICE DE MORTALIDADE INFANTIL\n\n");	
	printf("Quantidade de nascimentos: ");
	scanf("%f", &nascimentos);
	
	printf("\nDados sobre as crian�as falecidas\n");	
		do{	
			
			printf("\n%2i� Crian�a", contador + 1);
			printf("\n[f - para feminino | m - masculino | para terminar aperte 'v'] ");
			printf("\nSexo [f/m]: ");
			sexo = getche();
			sexo = tolower(sexo);
			
			while((sexo != 'f') && (sexo != 'm') && (sexo != 'v')){
				printf("\nEntrada inv�lida! Informe novamente.");
				printf("\nSexo [f/m/v]: ");
				sexo = getche();
				sexo = tolower(sexo);
			}
			if(sexo == 'v'){
				break;
			}else{
				printf("\nMeses de vida: ");
				scanf("%f", &meses);				
				while(meses < 0){
					printf("\nEntrada inv�lida! Informe novamente.");			
					printf("\nMeses de vida: ");
					scanf("%f", &meses);
				}				
				qtdMortes++;				
				if(sexo == 'm'){
					qtdMortesMasc++;
				}				
				if(meses <= 24){
					qtdMortes24++;
				}	
				printf("\n");
			}			
			contador++;
		}while(sexo != 'v' && contador < nascimentos);	
	
	printf("\n\n");
   
   	printf("%.2f %% das crian�as morreram no per�odo;\n", ((qtdMortes * 100) / nascimentos));
	printf("%.2f %% das crian�as masculinas morreram;\n", ((qtdMortesMasc * 100) / nascimentos)); //fiquei na d�vida se era a porcentagem dentre os nascidos ou as mortes
	printf("%.2f %% das crian�as viveram 24 meses ou menos.\n", ((qtdMortes24 * 100) / nascimentos));

	printf("\n\n\nPRESSIONE QUALQUER TECLA PARA ENCERRAR.\n");		
	getche();		

}
