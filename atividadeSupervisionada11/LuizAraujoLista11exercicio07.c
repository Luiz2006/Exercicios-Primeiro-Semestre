/*
Name: Luiz Araujo
Description: algoritmo que cadastra os pre�os de at� 100 CDs em uma loja. Possibilita 
	a execu��o de aumento dos pre�os cadastrados, sendo de 10% ou um percentual 
	informado pelo vendedor, para todos os CDs. Por fim, apresenta o percentual 
	de aumento e, para cada CD, o valor sem aumento e o valor com aumento.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_CD 100	// trocar para testes // certo: 100

////PROTOTIPAGENS
float aumento10(float preco);
float aumentoOutro(float preco, float porcentagem);
float validarPorcentagem(float porcentagem);
void validarOpcao(int *opcao);
void mostrarResultado(int indice, char nome[100], float preco, float novo);

int main(void){
//	declara��es
	char continuar = 's', nomeCD[MAX_CD][100];
	float precoCD[MAX_CD],precoNovo[MAX_CD], porcentagem = 0, aumento = 0;
	int quantidadeCD = 0, opcaoAumento = 0, contador = 0, indice = 0;

//	instru��es

	printf(" CADASTRO DE PRODUTOS");
	printf("\n    SESSAO DE CDs");
	printf("\n(titulo vazio ou preco 0 para finalizar)\n\n");
		
	while(quantidadeCD < MAX_CD){
		printf("TITULO DO %i%c CD: ", quantidadeCD + 1, 167);
//		scanf("%s", &nomeCD[quantidadeCD][0]);	//caso gets d� xabu(valores discrepantes)
		gets(nomeCD[quantidadeCD]);		
		
		if(strlen(nomeCD[quantidadeCD]) == 0){
			break;
		}
		
//		aquiiiiii, eu tento validar isso
//		ia fazer uma valida��o para nomes repetidos, mas meu PC n�o processa,
//		pensei em limitar as compara��es, mas perderia o prop�sito.
//		validarNome(

		do{
			
			if((quantidadeCD == 1)&&(strcmp(nomeCD[quantidadeCD], nomeCD[0]) == 0)){	
				fflush(stdin);			
				printf("TITULO JA CADASTRADO: ");
				gets(nomeCD[quantidadeCD]);	
								
				if(strlen(nomeCD[quantidadeCD]) == 0){
					break;
				}	
			}else{
				for(contador = 0; contador < quantidadeCD; contador++){
					fflush(stdin);
					if(strcmp(nomeCD[quantidadeCD], nomeCD[contador]) == 0){								
						printf("TITULO JA CADASTRADO: ");
						gets(nomeCD[quantidadeCD]);		
						if(strlen(nomeCD[quantidadeCD]) == 0){
							break;
						}
					}
				}
			}
					
		}while();	
		
		printf("PRECO: R$ ", quantidadeCD + 1, 167);
		scanf("%f", &precoCD[quantidadeCD]);
		if(precoCD[quantidadeCD] <= 0){
			break;
		}
		
		fflush(stdin);
		quantidadeCD++;
	}
	
	if(quantidadeCD > 0){ // caso seja vazio
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
					
					//// para n�o ter que passar todo o vetor inteiro como par�metro
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
					
					//// para n�o ter que passar todo o vetor inteiro como par�metro
					for(indice = 0; indice < quantidadeCD; indice++){
						precoNovo[indice] = aumentoOutro(precoCD[indice], porcentagem);
					}
					break;
				default:
					printf("ERRO NA VALIDACAO validarOpcao!!!!!!!!");
			}
			
			for(indice = 0; indice < quantidadeCD; indice++){
				mostrarResultado(indice, nomeCD[indice], precoCD[indice], precoNovo[indice]);
			}			
			
			printf("\n\nDeseja ajustar os precos novamente?\n\[s - para sim]"); // passar para fun��o
			continuar = getche();
			continuar = tolower(continuar);
						
			//para igualar os precos
			for(indice = 0; indice < quantidadeCD; indice++){	
				precoCD[indice] = precoNovo[indice];
			}	
				
		}	//fim while

	}else{
		system("CLS");
		printf("  NENHUMA ENTRADA \nPROGRAMA FINALIZADO\n\n\n");
		exit(0);
	}
//	printf("\n\nPRESSIONE QUALQUER TECLA PARA FINALIZAR... "); // para n�o fechar a tela
//	getch();
	return 0;
}
//// AUMENTOS
float aumento10(float preco){
	return preco * 1.1;
}
float aumentoOutro(float preco, float porcentagem){	
	float aumento;		
	aumento = (1 + (porcentagem / 100));	
	return preco * aumento;
}	

//// VALIDA��ES
float validarPorcentagem(float porcentagem){
	while(porcentagem == 0){	
		printf("O aumento n�o pode ser 0: ");
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
void mostrarResultado(int indice, char nome[100], float preco, float novo){
	printf("\n%i%c CD - %s", indice + 1, 167, nome);
	printf("\nPreco anterior: R$ %.2f.", preco);	
	printf("\nPreco atual   : R$ %.2f.", novo);
}
//char validarNome();
