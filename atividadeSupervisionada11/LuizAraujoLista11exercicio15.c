/*
Name: Luiz Araujo
Description: Alterar o algoritmo de ordenação de caracteres para pesquisar um caractere específico.
*/

#include<stdio.h>
#include<stdlib.h>

#define MAX_FRASE 800

int pesquisarCaracter(char texto[], int pesquisa[], int contador, char *caracter);
int lerValidarTexto(char texto[], int contador);
void mostrarResultado(char caracter, int contadorPesquisa, int pesquisa[], char texto[], int contador);

int main(void){
	char texto[MAX_FRASE] = {0}, caracter;
	int indice, contador = 0, contadorPesquisa = 0, pesquisa[MAX_FRASE] = {0};
	
//	instruções

	puts("BUSCA DE CARACTER");
	puts("\nInforme um texto");
	puts(" # - encerrar\n\n");

	contador = lerValidarTexto(texto, contador);
	contadorPesquisa = pesquisarCaracter(texto, pesquisa, contador, &caracter);	

	getch();
	return 0;
}

int lerValidarTexto(char texto[], int contador){
	do{
		scanf("%c", &texto[contador]);	
		
		if(texto[contador] == '#'){
			break;
		}	
		contador++;
	}while(contador < MAX_FRASE);
	return contador;
}

int pesquisarCaracter(char texto[], int pesquisa[], int contador, char *caracter){
	int indice, contadorPesquisa;

	while(*caracter != '#'){
		contadorPesquisa = 0;
		
		for(indice = 0; indice < contador; indice++){
			pesquisa[indice] = 0;
		}
		fflush(stdin);
		if(*caracter == '#'){
			break;
		}
		printf("Pesquisar: ");
		scanf("%c", caracter);		
		for(indice = 0; indice < contador; indice++){
			if((texto[indice] == toupper(*caracter))||(texto[indice] == tolower(*caracter))){
				pesquisa[contadorPesquisa] = indice;
				contadorPesquisa++;
			}
		}		
		mostrarResultado(*caracter, contadorPesquisa, pesquisa, texto, contador);
	}
	
	if(*caracter == '@'){
		fflush(stdin);
		puts("BUSCA DE CARACTER");
		puts("\nInforme um texto");
		puts(" # - encerrar\n\n");
		contador = lerValidarTexto(texto, contador);
	}
	system("CLS");
	puts("OBRIGADO E VOLTE SEMPRE!");
	return contadorPesquisa;
}

void mostrarResultado(char caracter, int contadorPesquisa, int pesquisa[], char texto[], int contador){		
	int indice, cont = 2;
	
	system("CLS");	
	puts("BUSCA DE CARACTER");
//	puts(" @ - novo texto");
	puts(" # - encerrar\n\n");
	
	if(contador == 1){
		puts("Texto: 1 caracter");
	}else{
		printf("Texto: %i caracteres\n", contador);
	}
	for(indice = 0; indice < contador; indice++){		
		printf("%c", texto[indice]);
	}
	
	puts("\n\nRESULTADO DA PESQUISA");
	printf(" %c: %i", caracter, contadorPesquisa);
	printf("\nNas posicoes:\n");
	for(indice = 0; indice < contadorPesquisa; indice++){
		printf("%3i", pesquisa[indice]);
		if(indice < (contadorPesquisa - 1)){
			printf(", ");
		}
		if(indice >= (contadorPesquisa - 1)){
			printf(".");
		}
		if(cont % 10 == 1){
			printf("\n");
		} 
		cont++;
	}	//fim for
			printf("\n\n");
}

