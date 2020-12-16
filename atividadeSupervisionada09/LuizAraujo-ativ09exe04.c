#include<stdio.h>
#include<locale.h>
main(){
	setlocale(LC_ALL, "Portuguese");
	float nascimentos, meses, qtdMortes = 0, qtdMortesMasc = 0, qtdMortes24 = 0, porcentagemMortes, porcentagemMortesMasc, porcentagemMortes24;
	char continuar, sexo;
	int contador = 0;
	
	printf("ÍNDICE DE MORTALIDADE INFANTIL\n\n");	
	printf("Quantidade de nascimentos: ");
	scanf("%f", &nascimentos);
	
	printf("\nDados sobre as crianças falecidas\n");	
		do{	
			
			printf("\n%2iª Criança", contador + 1);
			printf("\n[f - para feminino | m - masculino | para terminar aperte 'v'] ");
			printf("\nSexo [f/m]: ");
			sexo = getche();
			sexo = tolower(sexo);
			
			while((sexo != 'f') && (sexo != 'm') && (sexo != 'v')){
				printf("\nEntrada inválida! Informe novamente.");
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
					printf("\nEntrada inválida! Informe novamente.");			
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
   
   	printf("%.2f %% das crianças morreram no período;\n", ((qtdMortes * 100) / nascimentos));
	printf("%.2f %% das crianças masculinas morreram;\n", ((qtdMortesMasc * 100) / nascimentos)); //fiquei na dúvida se era a porcentagem dentre os nascidos ou as mortes
	printf("%.2f %% das crianças viveram 24 meses ou menos.\n", ((qtdMortes24 * 100) / nascimentos));

	printf("\n\n\nPRESSIONE QUALQUER TECLA PARA ENCERRAR.\n");		
	getche();		

}
