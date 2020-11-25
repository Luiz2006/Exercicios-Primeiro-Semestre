#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

#define MAX_INVESTIGADOS 30 //certo 150

int leValidaId(int idInvestiga[], int investigados);
float leValidaValor();
void classificaCPI(char classificacao[], float valoresInvestiga[], int investigados);
void apresentacaoCPI(char classe[], int idInvestiga[], float valoresInvestiga[], int contadorInvestigados);

int main(void){
	setlocale(LC_ALL, "Portuguese");
//	declarações
	int idInvestiga[MAX_INVESTIGADOS] = {0};
	float valoresInvestiga[MAX_INVESTIGADOS] = {0};
	char classificacao[MAX_INVESTIGADOS];
	int contadorInvestigados = 0;
	
//	instruções
	puts("CADASTRO DE INFORMAÇÕES PARA AUXÍLIO DAS CPIs");
	printf("            POLICIA FEDERAL\n");
	
	printf("\n(identificação 0 encerra)\nINFORME:\n");
	
	do{
		
		idInvestiga[contadorInvestigados] = leValidaId(idInvestiga, contadorInvestigados);
//		idInvestiga[contadorInvestigados] = rand() % 10000;
//		printf("\n\n\nID: %d\n\n\n", idInvestiga[contadorInvestigados]);
		if((idInvestiga[contadorInvestigados] == 0) && contadorInvestigados > 1){
			break;
		}		
		
		valoresInvestiga[contadorInvestigados] = leValidaValor();
//		printf("\n\nValor: R$ %.2f", valoresInvestiga[contadorInvestigados]);
		
		contadorInvestigados++;
	}while(contadorInvestigados < MAX_INVESTIGADOS);

	classificaCPI(classificacao, valoresInvestiga, contadorInvestigados);
	apresentacaoCPI(classificacao, idInvestiga, valoresInvestiga, contadorInvestigados);
	
	getche();
	return 0;
}

int leValidaId(int idInvestiga[], int investigados){
	int i, cont = 0, indice;
	printf("\n%i%cINVESTIGADO ", investigados + 1, 167);
	printf("\nIdentificação do investigado: ");
	scanf("%d", &i);
	
	while(i <= 1000 && i > 0 || i < 0){
		if(cont > 1){
			printf("\nIdentificação inválida!\nInforme um numero inteiro maior que 1000: ");
		}else{
			printf("\nIdentificação inválida: ");
		}		
		scanf("%d", &i);		
		cont++;
	} 
	
	
	for(indice = 0; indice < investigados; indice++){
		while(i == idInvestiga[indice]){
			printf("\nIdentificação já cadastrada: ");
			scanf("%d", &i);
			
			while(i <= 1000 && i > 0 || i < 0){
				if(cont > 1){
					printf("\nIdentificação inválida!\nInforme um numero inteiro maior que 1000: ");
				}else{
					printf("\nIdentificação inválida: ");
				}		
				scanf("%d", &i);		
				cont++;
			} 
		}
	}
	
	cont = 0;
	while((investigados <= 1) && (i == 0)){		
		if(cont > 1){
			printf("\nSerão investigadas no mínimo 2 (duas) pessoas: ");
		}else{
			printf("\nIdentificação inválida: ");
		}
		scanf("%d", &i);		
		cont++;
	}
	return i;
}

float leValidaValor(){
	float val;
	int cont = 0;
	
	printf("Valor recebido pelo investigado: R$ ");
	scanf("%f", &val);
	
	cont = 0;
	while(val <= -1){		
		if(cont < 1){
			printf("Valor nao pode ser negativo: R$ ");
		}else{
			printf("\nValor recebido não pode ser negativo: R$ ");
		}		
		scanf("%f", &val);		
		cont++;
	}
	return val;
}

void classificaCPI(char classificacao[], float valoresInvestiga[], int investigados){
	int indice, indice2;
	
	for(indice = 0; indice < investigados; indice++){
		if(valoresInvestiga[indice] <= 10000){
			classificacao[indice] = 'i';
		}
		if((valoresInvestiga[indice] > 10000) && (valoresInvestiga[indice] <= 50000)){
			classificacao[indice] = 'v';		
		}
		if(valoresInvestiga[indice] > 50000){
			classificacao[indice] = 's';
		}
	}
}


void apresentacaoCPI(char classificacao[], int idInvestiga[], float valoresInvestiga[], int contadorInvestigados){
	int indice, contIniciante = 0, contSemVergonha = 0, contSafado = 0;
	float total = 0, valorPesquisa;
	do{
		system("CLS");
		puts("CADASTRO DE INFORMAÇÕES PARA AUXÍLIO DAS CPIs");
		printf("            POLICIA FEDERAL\n");
		printf("\nIDENTIFICAÇÃO  VALOR (R$)  CLASSIFICAÇÃO");
		for(indice = 0; indice < contadorInvestigados; indice++){
			printf("\n %-12i %10.2f", idInvestiga[indice], valoresInvestiga[indice]); 
			if(classificacao[indice] == 'i'){
				printf("    %-14s", "iniciante");
				contIniciante++;
			}
			if(classificacao[indice] == 'v'){
				printf("    %-14s", "sem vergonha");
				contSemVergonha++;
			}
			if(classificacao[indice] == 's'){
				printf("    %-14s", "safado");
				contSafado++;
			}
			total = total + valoresInvestiga[indice];
		}
		printf("\nResumo:");	
		printf("\n  %02i = Iniciante", contIniciante);
		printf("\n  %02i = Sem vergonha", contSemVergonha);
		printf("\n  %02i = Resumo", contSafado);
		printf("\nTotal de valores recebidos: R$ %.2f\n", total);
		
		printf("\n(valor menor ou igual a 0 encerra)");	
		printf("\nPesquisar Valor: R$ ");
		scanf("%f", &valorPesquisa);
		if(valorPesquisa <= 0){
			break;
		}
		printf("\nIDENTIFICAÇÃO  VALOR (R$)  CLASSIFICAÇÃO");
		for(indice = 0; indice < contadorInvestigados; indice++){
			if(valoresInvestiga[indice] >= valorPesquisa){
				printf("\n %-12i %10.2f", idInvestiga[indice], valoresInvestiga[indice]); 
				if(classificacao[indice] == 'i'){
					printf("    %-14s", "iniciante");
					contIniciante++;
				}
				if(classificacao[indice] == 'v'){
					printf("    %-14s", "sem vergonha");
					contSemVergonha++;
				}
				if(classificacao[indice] == 's'){
					printf("    %-14s", "safado");
					contSafado++;
				}				
			}
		}
		system("PAUSE");
	}while(valorPesquisa > 0);
}












