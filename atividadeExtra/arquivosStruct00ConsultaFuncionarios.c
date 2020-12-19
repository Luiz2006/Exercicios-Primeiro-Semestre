/*
Name: Consultar Funcionários
Copyright: MIT License
Author: Luiz Araujo - luizcarlos_bsb2006@hotmail.com
Date: 06/12/20 13:38
Description: Manipulação de Arquivos - consulta de funcionarios de um arquivo, utilizando struct.
*/

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<locale.h>

#define MAX_FUNC 100//se mais que 30.000 alterar de unsigned short para unsigned int

struct dados_pessoais{
	unsigned short codigo;	//2bytes
	char nome[31];			//31bytes
	unsigned short idade;	//2bytes
	char sexo;				//1bytes
	char cargo[21];			//21bytes
	float salario;			//4bytes
};

void menuConsulta();
void listarFuncionarios(char tipo);
void pesquisarFuncionarios(char tipo[]);
unsigned short int lerArquivo(struct dados_pessoais funcionario[]);

int main(void){
	setlocale(LC_COLLATE, "Portuguese");
	setlocale(LC_MONETARY, "Portuguese");
	setlocale(LC_NUMERIC, "Portuguese");
	setlocale(LC_TIME, "Portuguese");

	menuConsulta();
	
	printf("\n\n\nPRESSIONE QUALQUER TECLA PARA ENCERRAR.\n");
	getch();
	return 0;
}

unsigned short int lerArquivo(struct dados_pessoais funcionario[]){
	unsigned short int contador_entradas;
	
	FILE *arq;
	arq = fopen("dados_funcionarios.bin", "rb");
	if(arq == NULL){
		puts("\a\a\a\nSEM FUNCIONARIOS CADASTRADOS, VERIFIQUE OS DADOS SALVOS E TENTE NOVAMENTE!");
		sleep(3);
		exit(1);
	}
	contador_entradas = fread(funcionario, sizeof(struct dados_pessoais), MAX_FUNC, arq);
	fclose(arq);	
	return contador_entradas;
}

void menuConsulta(){
	unsigned short int contador_erros = 0, contador_entradas;
	struct dados_pessoais funcionario[MAX_FUNC];
	char opcao;
	
	do{
		contador_entradas = lerArquivo(funcionario);
		system("CLS");
		puts("MENU DE CONSULTA FUNCIONARIOS");
		puts("1 - LISTAR TODOS");
		puts("2 - PESQUISAR POR CODIGO");
		puts("3 - PESQUISAR POR NOME");
		puts("4 - PESQUISAR POR IDADE");
		puts("5 - PESQUISAR POR SEXO");
		puts("6 - PESQUISAR POR CARGO");
		puts("7 - PESQUISAR POR SALARIO");
		puts("0 - SAIR");
		printf("TIPO DE CONSULTA: ");
		fflush(stdin);
		opcao = getche();

		contador_erros = 0;
		while((opcao > '7')||(isdigit(opcao) == 0)){
			contador_erros++;
			if(contador_erros > 2){		
				printf("\n\nINFORME UM NUMERO DE 0 a 7.");		
				printf("\nTIPO DE CONSULTA: ");
			}else{
				printf("\nOPCAO INVALIDA!");
			}		 
			fflush(stdin);
			opcao = getche();
		}
		switch(opcao){
			case '1':
				listarFuncionarios('h');
				break;	
			case '2':
				pesquisarFuncionarios("CODIGO");
				break;
			case '3':
				pesquisarFuncionarios("NOME");
				break;
			case '4':
				pesquisarFuncionarios("IDADE");
				break;
			case '5':
				pesquisarFuncionarios("SEXO");
				break;
			case '6':
				pesquisarFuncionarios("CARGO");
				break;
			case '7':
				pesquisarFuncionarios("SALARIO");
				break;		
		}
		if(opcao != '0'){			
			printf("\nPRESSIONE QUALQUER TECLA PARA CONTINUAR.\n");
			getch();
		}
	}while(opcao != '0');
}

void listarFuncionarios(char tipo){	
	struct dados_pessoais funcionario[MAX_FUNC];
	unsigned short int indice, contador_entradas;
	
	contador_entradas = lerArquivo(funcionario);	
	system("CLS");
	printf("QUANTIDADE DE FUNCIONARIOS: %i\n", contador_entradas);
	if((tipo == 'v') || (tipo == 'V')){
//		LISTA VERTICALIZADA
		for(indice = 0; indice < contador_entradas; indice++){//mostra nome de todos os func
			printf("\nCodigo : %03u ", funcionario[indice].codigo);
			printf("\nNome   : %s",funcionario[indice].nome);
			printf("\nIdade  : %d",funcionario[indice].idade);
			if(funcionario[indice].sexo == 'f'){
				printf("\nSexo   : feminino");
			}else if(funcionario[indice].sexo == 'm'){
				printf("\nSexo   : masculino");
			}else{
				printf("\nSexo   : indefinido");
			}
			printf("\nCargo  : %s",funcionario[indice].cargo);
			printf("\nSALARIO: R$ %10.2f",funcionario[indice].salario);
			printf("\n");
		}
	}else{
//		LISTA HORIZONTAL
		printf("COD %-30s%-6s%-6s%-20s%-10s\n","NOME","IDADE","SEXO","CARGO","SALARIO(R$)");
		for(indice = 0; indice < contador_entradas; indice++){//mostra nome de todos os func	
			printf("%03u ", funcionario[indice].codigo);
			printf("%-30s",funcionario[indice].nome);
			printf("%-6d",funcionario[indice].idade);
			if(funcionario[indice].sexo == 'f'){
				printf("%-6s%","FEM");
			}else if(funcionario[indice].sexo == 'm'){
				printf("%-6s%","MASC");
			}else{
				printf("%-6s%","INDEF");
			}
			printf("%-20s",funcionario[indice].cargo);
			printf("%10.2f",funcionario[indice].salario);
			printf("\n");
		}
	}
}

void pesquisarFuncionarios(char tipo[10]){
	struct dados_pessoais funcionario_temp[MAX_FUNC], funcionario[MAX_FUNC];
	unsigned short int indice, cod, posicao, compara_nomes, tamanho, contador_entradas, 
	encontrados = 0, cod_errado = 0, flag = 0;

	contador_entradas = lerArquivo(funcionario);	
//	system("CLS");
	if(strcmp(tipo, "CODIGO") == 0){	//pesquisar por codigo
		cod_errado = 0;
		do{
			printf("\nCODIGO: ");	
			fflush(stdin);
			scanf("%d", &cod);
			encontrados = 0;
			for(indice = 0; indice < contador_entradas; indice++){
				if(funcionario[indice].codigo == cod){
					posicao = indice;
					funcionario_temp[encontrados] = funcionario[posicao];
					encontrados++;
				}
			}
			if(encontrados == 0){
				printf("CODIGO NAO CADASTRADO!\n");
			}
			if(cod_errado > 2){
				listarFuncionarios('h');
			}
			cod_errado++;
		}while(encontrados == 0);
	}//fim if codigo
			
	if(strcmp(tipo, "NOME") == 0){	//pesquisar por nome
		char nome[31];

		puts("\nNOME:");
		fflush(stdin);
		gets(nome);
		strlwr(nome);
		
		char *sub, texto[31];
		encontrados = 0;
		for(indice = 0; indice < contador_entradas; indice++){
			flag = 0;
			strcpy(texto, funcionario[indice].nome);
			strlwr(texto);
			sub = strtok(texto, " !.,");
			while(sub != NULL){
				compara_nomes = strncmp(nome, sub, (strlen(nome)));
				if(compara_nomes == 0){	
					flag = 1;
					break;	
				}
				sub = strtok(NULL, " !.,");
			}
			if(flag == 1){
				funcionario_temp[encontrados] = funcionario[indice];
				encontrados++;
			}
		}		
	}//fim if nome
		
	if(strcmp(tipo, "IDADE") == 0){	//pesquisar por idade	
		unsigned short int idade, contadorTemp = 0;
		char opcao;
		do{
			puts("\nIDADE:");
			scanf("%hu", &idade);
			if(idade < 14){
				puts("Na CLT, a idade mínima prevista é de 14 anos, desde que o menor seja contratado na condição de aprendiz.");
			}
			if(idade > 120){
				puts("Informe uma idade válida, pois com mais de 120 anos é improvável que ainda esteja trabalhando.");
			}
		}while((idade < 14) || (idade > 120));
				
		printf("\n\n1 - menores ou com idade igual a %d", idade);
		printf("\n2 - com idade igual a %d", idade);
		printf("\n3 - maiores ou com idade igual a %d", idade);
		printf("\nDESEJA PROCURAR OS FUNCIONARIOS: ");
		fflush(stdin);
		opcao = getche();
		while((opcao == '0')||(opcao > '3')){
			printf("TIPO DE CONSULTA INVALIDO: ");
			contadorTemp++;
			if(contadorTemp > 2){				
				printf("\n1 - menores ou com idade igual a %d", idade);
				printf("\n2 - com idade igual a %d", idade);
				printf("\n3 - maiores ou com idade igual a %d", idade);
				printf("\nDESEJA PROCURAR OS FUNCIONARIOS: ");
			}
			fflush(stdin);
			opcao = getche();
		}
		encontrados = 0;
		switch(opcao){
			case '1':
				for(indice = 0; indice < contador_entradas; indice++){
					flag = 0;
					if(funcionario[indice].idade <= idade){	
						funcionario_temp[encontrados] = funcionario[indice];
						encontrados++;
					}
				}
			break;
			case '2':
				for(indice = 0; indice < contador_entradas; indice++){
					if(idade == funcionario[indice].idade){	
						funcionario_temp[encontrados] = funcionario[indice];
						encontrados++;
					}
				}
			break;
			case '3':
				for(indice = 0; indice < contador_entradas; indice++){
					if(funcionario[indice].idade >= idade){	
						funcionario_temp[encontrados] = funcionario[indice];
						encontrados++;
					}
				}	
			break;
		}
	}//fim if idade		

	if(strcmp(tipo, "SEXO") == 0){	//pesquisar por sexo
		char sexo;
		
		do{
			puts("\nSEXO: ");
			fflush(stdin);
			sexo = getche();
			sexo = tolower(sexo);
			if(sexo != 'f' && sexo != 'm' && sexo != 'x'){
				puts("F para feminino | M para masculino | X para indefinido ");
			}		
		}while(sexo != 'f' && sexo != 'm' && sexo != 'x');

		encontrados = 0;
		for(indice = 0; indice < contador_entradas; indice++){
			if(sexo == funcionario[indice].sexo){
				funcionario_temp[encontrados] = funcionario[indice];
				encontrados++;
			}
		}	
	}//fim if sexo

	if(strcmp(tipo, "CARGO") == 0){	//pesquisar por cargo
		char cargo[21];

		puts("\nCARGO:");
		fflush(stdin);
		gets(cargo);
		strlwr(cargo);
		
		char *sub, texto[21];
		encontrados = 0;
		for(indice = 0; indice < contador_entradas; indice++){
			flag = 0;
			strcpy(texto, funcionario[indice].cargo);
			strlwr(texto);
			sub = strtok(texto, " !.,");
			while(sub != NULL){				
				compara_nomes = strcmp(cargo, funcionario[indice].cargo);
				if(compara_nomes == 0){	
					flag = 1;
					break;	
				}
				compara_nomes = strncmp(cargo, sub, (strlen(cargo)));
				if(compara_nomes == 0){	
					flag = 1;
					break;	
				}
				sub = strtok(NULL, " !.,");
			}
			if(flag == 1){
				funcionario_temp[encontrados] = funcionario[indice];
				encontrados++;
			}
		}		
	}//fim if cargo

	if(strcmp(tipo, "SALARIO") == 0){	//pesquisar por salario	
		unsigned short int contadorTemp = 0;
		float salario;
		char opcao;

		do{
			printf("\nSALARIO: R$ ");
			scanf("%f", &salario);
			if(salario < 400){
				puts("Informe um salário válido, pois menos que R$ 400,00 nem jovem aprendiz recebe...");
			}
		}while(salario < 400);
		printf("\nDESEJA PROCURAR OS FUNCIONARIOS: ");
		printf("\n1 - com salario igual ou menor que R$%.2f", salario);
		printf("\n2 - com salario igual a R$%.2f", salario);
		printf("\n3 - com salario igual ou maior que R$%.2f", salario);
		fflush(stdin);
		opcao = getche();
		while((opcao == '0')||(opcao > '3')){
			printf("\nTIPO DE CONSULTA INVALIDO: ");
			contadorTemp++;
			if(contadorTemp > 2){				
				printf("\nDESEJA PROCURAR OS FUNCIONARIOS: ");
				printf("\n1 - com salario igual ou menor que R$%.2f", salario);
				printf("\n2 - com salario igual a R$%.2f", salario);
				printf("\n3 - com salario igual ou maior que R$%.2f", salario);
			}
			fflush(stdin);
			opcao = getche();
		}
		
		encontrados = 0;
		switch(opcao){
			case '1':
				for(indice = 0; indice < contador_entradas; indice++){
					if(funcionario[indice].salario <= salario){	
						funcionario_temp[encontrados] = funcionario[indice];
						encontrados++;
					}
				}
				break;
			case '2':
				for(indice = 0; indice < contador_entradas; indice++){
					if(salario == funcionario[indice].salario){	
						funcionario_temp[encontrados] = funcionario[indice];
						encontrados++;
					}
				}
				break;
			case '3':
				for(indice = 0; indice < contador_entradas; indice++){
					if(funcionario[indice].salario >= salario){	
						funcionario_temp[encontrados] = funcionario[indice];
						encontrados++;
					}
				}	
				break;
		}
	}//fim if salario		
		
	system("CLS");
	printf("PESQUISA POR %s", tipo);
	printf("\nQUANTIDADE DE FUNCIONARIOS ENCONTRADOS: %i\n\n", encontrados);
	
//	fazer somatorio dos salarios

	printf("%-4s%-30s%-6s%-6s%-20s%-10s\n", "COD","NOME","IDADE","SEXO","CARGO","SALARIO(R$)");
	if(encontrados <= 0){
		puts("NENHUM FUNCIONARIO ENCONTRADO COM A INFORMACAO SOLICITADA.");
	}else{
		for(indice = 0; indice < encontrados; indice++){//mostra nome de todos os func		
			printf("%03u ", funcionario_temp[indice].codigo);
			printf("%-30s",funcionario_temp[indice].nome);
			printf("%-6d",funcionario_temp[indice].idade);
			if(funcionario_temp[indice].sexo == 'f'){
				printf("%-6s%","FEM");
			}else if(funcionario_temp[indice].sexo == 'm'){
				printf("%-6s%","MASC");
			}else{
				printf("%-6s%","INDEF");
			}
			printf("%-20s",funcionario_temp[indice].cargo);
			printf("%10.2f",funcionario_temp[indice].salario);
			printf("\n");
		}
	}
	printf("\n\n");
}
