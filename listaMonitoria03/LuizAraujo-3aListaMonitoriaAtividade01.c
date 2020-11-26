#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void lerValidarNomeCidade(char nomeCidade[]);
void visitaEstabelecimentos(int *qtdEstabelecimentos, int qtdFocos[][2]);
void resultadoAnalise(char nomeCidade[], int qtdEstabelecimentos, int qtdFocos[][2]);

int main(void){
//	declarações
	char nomeCidade[30];
	int qtdEstabelecimentos, qtdFocos[100][2];
	
//	instruções
	puts("    SECRETARIA DE SAUDE DO DF");
	puts("Investigacao sobre focos da Dengue");
	
	lerValidarNomeCidade(nomeCidade);
	visitaEstabelecimentos(&qtdEstabelecimentos, qtdFocos);
	resultadoAnalise(nomeCidade, qtdEstabelecimentos, qtdFocos);

	getch();
	return 0;
}

void lerValidarNomeCidade(char nomeCidade[]){	
	puts("Cidade onde foi realizada a investigacao:");
	gets(nomeCidade);
	while(strcmp(nomeCidade, " ") == 0){
		puts("Entrada obrigatoria: ");
		gets(nomeCidade);
	}
}

void visitaEstabelecimentos(int *qtdEstabelecimentos, int qtdFocos[][2]){
	int indice;
	
	puts("\nQuantidade de estabelecimentos visitados:");
	scanf("%i", qtdEstabelecimentos);		
	while(*qtdEstabelecimentos < 5 || *qtdEstabelecimentos > 100){
		puts("A quantidade de estabelecimentos visitados para tal investigacao nao pode ser menor que 5 e nem maior que 100.");		
		puts("Quantidade de estabelecimentos visitados:");
		scanf("%i", qtdEstabelecimentos);
	}
	
	for(indice = 0; indice < *qtdEstabelecimentos; indice++){		
		printf("\n\n%i%c - Estabelecimento\n", indice + 1, 167);		
		puts("Quantidade de focos encontrados: ");
		scanf("%i", &qtdFocos[indice][0]);
		while(qtdFocos[indice][0] < 0){
			puts("Somente valores a partir de zero.");
			puts("\nQuantidade de focos encontrados: ");
			scanf("%i", &qtdFocos[indice][0]);
		}

		puts("\nNumero de pessoas que viviam no local: ");
		scanf("%i", &qtdFocos[indice][1]);
		while(qtdFocos[indice][1] <= 0){
				puts("O número de pessoas deve ser maior que zero.");
				puts("Numero de pessoas que viviam no local: ");
				scanf("%i", &qtdFocos[indice][1]);
		}
	}	
}

void resultadoAnalise(char nomeCidade[], int qtdEstabelecimentos, int qtdFocos[][2]){
	int indice, totalPessoas = 0, estabelecimentosMaiores = 0;
	float mediaPessoas = 0;
	
	system("CLS");
	puts("    SECRETARIA DE SAUDE DO DF");
	puts("Investigacao sobre focos da Dengue");	
	printf("\nCIDADE: %s\n", nomeCidade);
	
	for(indice = 0; indice < qtdEstabelecimentos; indice++){
		totalPessoas = totalPessoas + qtdFocos[indice][1];
	}
	mediaPessoas = totalPessoas/qtdEstabelecimentos;

	printf("\n -> Foram vistados %i estabelecimentos, onde viviam %i pessoas.\n", qtdEstabelecimentos, totalPessoas);
	
	for(indice = 0; indice < qtdEstabelecimentos; indice++){
		printf("\n -> Estabelecimento : %3i\n\tQuantidade de pessoas: %3i | Numero de focos: %3i\n", (indice + 1), qtdFocos[indice][1], qtdFocos[indice][0]);
		if(qtdFocos[indice][1] > mediaPessoas){
			estabelecimentosMaiores++;
		}
	}
	printf("\n\n -> A media da quantidade de pessoas que vivem nestes estabelecimentos investigados: %.2f.", mediaPessoas);
	printf("\n -> A quantidade de estabelecimentos que tem a quantidade MAIOR de pessoas vivendo que este valor medio: %i.\n", estabelecimentosMaiores);
}
















