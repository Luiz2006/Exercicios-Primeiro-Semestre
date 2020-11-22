#include<stdio.h>
#include<locale.h>
main(){
	setlocale(LC_ALL, "Portuguese");
	float contador, nascimentos, meses, qtdMortes, qtdMortesMasc, qtdMortes24, porcentagemMortes, porcentagemMortesMasc, porcentagemMortes24;
	char continuar, sexo;
	
	qtdMortes = 0;
	qtdMortesMasc = 0;
	qtdMortes24 = 0;
	
	printf("�NDICE DE MORTALIDADE INFANTIL\n\n");
	
	printf("Quantidade de nascimentos: ");
	scanf("%f", &nascimentos);
	
	printf("\nDados sobre as crian�as falecidas\n");
	
		do{		
			contador++;
			printf("\n%.0f� Crian�a", contador);
			printf("\n[f - para feminino | m - masculino | para terminar aperte enter] ");
			printf("\nSexo [f/m]: ");
			sexo = getche();
			sexo = tolower(sexo);
			
			while((sexo != 'f') && (sexo != 'm') && (sexo != '\r')){
				printf("\nEntrada inv�lida! Informe novamente.");
				printf("\nSexo [f/m]: ");
				sexo = getche();
				sexo = tolower(sexo);
			}
				
			if(sexo != '\r'){
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
			
		}while(sexo != '\r');
	
	
	
	printf("\n\n");
	porcentagemMortes = (nascimentos * (qtdMortes/100))*100;
	porcentagemMortesMasc = (nascimentos * (qtdMortesMasc/100)*100.0); 
	porcentagemMortes24 = (nascimentos * (qtdMortes24/100))*100.0;
   
   	printf("%.2f %% das crian�as morreram no per�odo.\n", porcentagemMortes);
	printf("%.2f %% das crian�as masculinas morreram.\n", porcentagemMortesMasc);
	printf("%.2f %% das crian�as que viveram at� 24 meses.\n", porcentagemMortes24);
}
