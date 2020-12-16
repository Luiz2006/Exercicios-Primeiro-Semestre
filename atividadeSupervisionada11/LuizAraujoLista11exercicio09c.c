#include<stdio.h>
#include<stdlib.h>
//#include <time.h> //para testar automaticamente
#define MAX_IDADE 100

int leValidaIdade(int qtd); 
void apresentarMedia(int *idades, int qtd);
void identificarMaisVelha(int *idades, int qtd);
//float entradaAleatoria(); //para testar automaticamente

int main(void){	
//	declarações
	int quantidade = 0, idades[MAX_IDADE];
//	instruções
	puts("INFORME ALGUMAS IDADES");
	puts("  (0 para finalizar)\n");	
//	srand(time(NULL));			//para testar automaticamente
//	float r = rand(); 			//para testar automaticamente	
	do{	
		idades[quantidade] = leValidaIdade(quantidade);	
		if(quantidade >= 1 && idades[quantidade] == 0){
			break;
		}
		quantidade++;
	}while(quantidade < MAX_IDADE);		
	apresentarMedia(idades, quantidade);	
	identificarMaisVelha(idades, quantidade);	
	printf("\n\n");
	printf("\n\n\nPRESSIONE QUALQUER TECLA PARA ENCERRAR.\n");		
	getche();		
	return 0;
}
int leValidaIdade(int qtd){
	int idade;
	printf("Idade: ");
	scanf("%i", &idade);	//comentar para testar automaticamente
////	if(qtd % 2 == 0){				//semi automaticamente	
////		scanf("%i", &idade);		//semi automaticamente
////	}else{							//semi automaticamente
//		idade = entradaAleatoria();	//para testar automaticamente
//		printf("%i\n", idade);		//para testar automaticamente
////	}								//semi automaticamente
	while(idade < 0){
		printf("Entrada invalida:");
		scanf("%i", &idade);
	}		
	while(idade > 130){
		printf("\nEntrada invalida ou e o Matusalem?");
		printf("\nInforme uma idade valida:");
		scanf("%i", &idade);
	}
	return idade;
}
void apresentarMedia(int *idades, int qtd){
	int indice;
	float media;	
	
	for(indice = 0; indice < qtd; indice++){
		media += idades[indice];		
	}	
	media /= qtd;
	printf("\nMEDIA DAS IDADES DAS %i PESSOAS: %.2f anos.", qtd, media);
}
void identificarMaisVelha(int *idades, int qtd){
	int indice, indice2 = 0, velha = 0, posicao[MAX_IDADE];
// 	descobrir a mais velha
	for(indice = 0; indice < qtd; indice++){
		if(velha < idades[indice]){
			velha = idades[indice];	
		}	
	}
//	pegar posicoes da  mais velha
	for(indice = 0; indice < qtd; indice++){
		if(idades[indice] == velha){
			posicao[indice2] = indice;		
			indice2++;	
		}
	}
	if(velha == 1){
		printf("\nA MAIS VELHA TEM: 1 ano.");
	}else{
		if(indice2 == 0){
			printf("\nA MAIS VELHA TEM: %i anos.", velha);
		}else{
			printf("\nAS MAIS VELHAS TEM: %i anos.", velha);
		}
	}
	indice = 0;
	if(indice2 == 1){	
		printf("\nTAL IDADE APARECE NA POSICAO DO VETOR:");	
	}else{
		printf("\nTAL IDADE APARECE NAS POSICOES DO VETOR:");
	}
	do{
		if(indice > 0){
			printf(",");	
		}
		printf(" %i", posicao[indice]);	
		indice++;		
	}while(indice < indice2);
	printf(".");	
}
//para testar automaticamente
//float entradaAleatoria(){
//	return (rand() % 100);
//}
