#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_CD 100
float aumento10(float preco);
float aumentoOutro(float preco, float porcentagem);
float validarPorcentagem(float porcentagem);
void validarOpcao(int *opcao);
void mostrarResultado(int quantidadeCD, int indice, float preco[], float novo[]);
int main(void){
//	declarações
	char continuar = 's';
	float precoCD[MAX_CD],precoNovo[MAX_CD], porcentagem = 0, aumento = 0;
	int quantidadeCD = 0, opcaoAumento = 0, contador = 0, indice = 0;

//	instruções
	printf(" CADASTRO DE PRODUTOS");
	printf("\n    SESSAO DE CDs");
	printf("\n(preco 0 para finalizar)\n\n");		
	while(quantidadeCD < MAX_CD){
		printf("PRECO: R$ ");
		scanf("%f", &precoCD[quantidadeCD]);
		while(precoCD[quantidadeCD] < 0){
			printf("Preço incorreto: R$ ");
			scanf("%f", &precoCD[quantidadeCD]);
		}
		if(precoCD[quantidadeCD] == 0){
			break;
		}
		fflush(stdin);
		quantidadeCD++;
	}	
	if(quantidadeCD > 0){
		printf("\nDeseja ajustar os precos? \n(s - para sim])");
		continuar = getche();
		continuar = tolower(continuar);
		while(continuar == 's'){
			system("CLS");			
			printf("  CADASTRO DE PRODUTOS");
			printf("\nAJUSTE DE PRECOS DOS CDs");
			printf("\n\n1 - 10%% de aumento");
			printf("\n2 - Outra porcentagem\n");		
			scanf("%i", &opcaoAumento);		
			validarOpcao(&opcaoAumento);			
			switch(opcaoAumento){
				case 1:	
					system("CLS");					
					printf("  CADASTRO DE PRODUTOS");	
					printf("\nAJUSTE DE PRECOS DOS CDs");
					printf("\n\nOPCAO 1 - 10%% de aumento.\n");						
					//// para não ter que passar todo o vetor inteiro como parâmetro
					for(indice = 0; indice < quantidadeCD; indice++){	
						precoNovo[indice] = aumento10(precoCD[indice]);
					}						
					break;
				case 2:		
					printf("Qual a porcentagem de aumento? ");
					scanf("%f", &porcentagem);
					porcentagem = validarPorcentagem(porcentagem);					
					system("CLS");					
					printf("   CADASTRO DE PRODUTOS");	
					printf("\nAJUSTE DE PRECOS DOS CDs");
					printf("\n\nOPCAO 2 - %.2f%% de aumento.\n", porcentagem);					
					//// para não ter que passar todo o vetor inteiro como parâmetro
					for(indice = 0; indice < quantidadeCD; indice++){
						precoNovo[indice] = aumentoOutro(precoCD[indice], porcentagem);
					}
					break;
				default:
					printf("ERRO NA VALIDACAO validarOpcao!!!!!!!!");
			}						
			mostrarResultado(quantidadeCD, indice, precoCD, precoNovo);				
			printf("\n\nDeseja ajustar os precos novamente?\n\[s - para sim]"); // passar para função
			continuar = getche();
			continuar = tolower(continuar);						
			//para igualar os precos
			for(indice = 0; indice < quantidadeCD; indice++){	
				precoCD[indice] = precoNovo[indice];
			}					
		}
	}else{
		system("CLS");
		printf("  NENHUMA ENTRADA \nPROGRAMA FINALIZADO\n\n\n");
		exit(0);
	}
	printf("\n\n\nPRESSIONE QUALQUER TECLA PARA ENCERRAR.\n");		
	getche();
	return 0;
}
float aumento10(float preco){
	return preco * 1.1;
}
float aumentoOutro(float preco, float porcentagem){	
	float aumento;		
	aumento = (1 + (porcentagem / 100));	
	return preco * aumento;
}	
float validarPorcentagem(float porcentagem){
	while(porcentagem == 0){	
		printf("O aumento não pode ser 0: ");
		scanf("%f", &porcentagem);
	}	
	return porcentagem;	
}
void validarOpcao(int *opcao){
	while(*opcao != 1 && *opcao != 2){	
		printf("\nOpcao invalida!");
		printf("\n1 - 10%% de aumento");
		printf("\n2 - Outra porcentagem\n");		
		scanf("%i", opcao);	
	}
}
void mostrarResultado(int quantidadeCD, int indice, float preco[], float novo[]){
	for(indice = 0; indice < quantidadeCD; indice++){		
		printf("\n%i%c CD", indice + 1, 167);
		printf("\nPreco anterior: R$ %.2f.", preco[indice]);	
		printf("\nPreco atual   : R$ %.2f.", novo[indice]);
	}
}
