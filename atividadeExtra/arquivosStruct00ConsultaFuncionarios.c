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

#define MAX_FUNC 50

struct dados_pessoais{
	char nome[31];
	int idade;
	char sexo;
	char cargo[21];
	float salario;
};

void menuConsulta(struct dados_pessoais funcionario[], int contador_entradas);
int porStruct(struct dados_pessoais funcionario[]);
void gravarEntrada(struct dados_pessoais *funcionario, FILE *arq);
void listarFuncionarios(struct dados_pessoais funcionario[], int contador_entradas);
void pesquisarFuncionarios(struct dados_pessoais funcionario[], int contador_entradas, char tipo[]);

int main(void){
	setlocale(LC_COLLATE, "Portuguese");
	setlocale(LC_MONETARY, "Portuguese");
	setlocale(LC_NUMERIC, "Portuguese");
	setlocale(LC_TIME, "Portuguese");	
	struct dados_pessoais funcionario[MAX_FUNC];
	int contador_funcionario = 0, indice = 0, indice2 = 0, contador_entradas = 0;
	char continuar;

//	põe todas as entradas na struct
	contador_entradas = (int)porStruct(funcionario);
	
	if(contador_entradas > 0){		
		menuConsulta(funcionario, contador_entradas);
	}else{
		puts("SEM FUNCIONARIOS CADASTRADOS, VERIFIQUE OS DADOS SALVOS E TENTE NOVAMENTE!");
		sleep(3);
		exit(1);
	}
	

	contador_entradas = porStruct(funcionario);
	
	printf("\n\n\nPRESSIONE QUALQUER TECLA PARA ENCERRAR.\n");
	getch();
	return 0;
}


void menuConsulta(struct dados_pessoais funcionario[], int contador_entradas){
	unsigned short int contadorTemp = 0;
	char opcao;
	do{
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

		contadorTemp = 0;
		while((opcao > '7')||(isdigit(opcao) == 0)){
			contadorTemp++;
				contadorTemp++;
				if(contadorTemp > 2){		
					printf("\n\nINFORME UM NUMERO DE 0 a 7!");		
					printf("\n1 - LISTAR TODOS");
					printf("\n2 - PESQUISAR POR CODIGO");
					printf("\n3 - PESQUISAR POR NOME");
					printf("\n4 - PESQUISAR POR IDADE");
					printf("\n5 - PESQUISAR POR SEXO");
					printf("\n6 - PESQUISAR POR CARGO");
					printf("\n7 - PESQUISAR POR SALARIO");
					printf("\n0 - SAIR");
					printf("\nTIPO DE CONSULTA: ");
				}else{
					printf("\nTIPO DE CONSULTA INVALIDO: ");
				}		 
				fflush(stdin);
				opcao = getche();
		}
		switch(opcao){
			case '1':
				listarFuncionarios(funcionario, contador_entradas);
				break;	
			case '2':
				pesquisarFuncionarios(funcionario, contador_entradas, "CODIGO");
				break;
			case '3':
				pesquisarFuncionarios(funcionario, contador_entradas, "NOME");
				break;
			case '4':
				pesquisarFuncionarios(funcionario, contador_entradas, "IDADE");
				break;
			case '5':
				pesquisarFuncionarios(funcionario, contador_entradas, "SEXO");
				break;
			case '6':
				pesquisarFuncionarios(funcionario, contador_entradas, "CARGO");
				break;
			case '7':
				pesquisarFuncionarios(funcionario, contador_entradas, "SALARIO");
				break;		
		}
		if(opcao != '0'){			
			printf("\n\n\nPRESSIONE QUALQUER TECLA PARA CONTINUAR.\n");
			getch();
		}
	}while(opcao != '0');
}

void listarFuncionarios(struct dados_pessoais funcionario[], int contador_entradas){	
	int indice;
	system("CLS");
	printf("QUANTIDADE DE FUNCIONARIOS: %i\n", contador_entradas);
//			//VERTICALIZADO
//	for(indice = 0; indice < contador_entradas; indice++){//mostra nome de todos os func
//		printf("CODIGO: %03d ", indice);
//		printf("\nNome   : %s",funcionario[indice].nome);
//		printf("\nIdade  : %d",funcionario[indice].idade);
//		if(funcionario[indice].sexo == 'f'){
//			printf("\nSexo   : feminino");
//		}else if(funcionario[indice].sexo == 'm'){
//			printf("\nSexo   : masculino");
//		}else{
//			printf("\nSexo   : indefinido");
//		}
//		printf("\nCargo  : %s",funcionario[indice].cargo);
//		printf("\nSALARIO: R$ %10.2f",funcionario[indice].salario);
//		printf("\n");
//	}
			//LISTA HORIZONTAL
	printf("COD %-30s%-6s%-6s%-20s%-10s\n","NOME","IDADE","SEXO","CARGO","SALARIO(R$)");
	for(indice = 0; indice < contador_entradas; indice++){//mostra nome de todos os func

//		printf("%03d ", indice);
		printf("%03d ", indice);
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
	printf("\n\n\n\n");
}


void pesquisarFuncionarios(struct dados_pessoais funcionario[], int contador_entradas, char tipo[10]){
	struct dados_pessoais funcionario_temp[MAX_FUNC];
	int indice, encontrados, controle_erros, compara_nomes, tamanho;
	unsigned short int flag = 0;
	
//	system("CLS");
	//pesquisar por codigo
	if(strcmp(tipo, "CODIGO") == 0){
		int cod;
		encontrados = 0;
		printf("\nCODIGO DO FUNCIONARIO: ");
		scanf("%d", &cod);
		while((cod < 0) || (cod >= contador_entradas)){
			controle_erros++;
			if(controle_erros > 2){
				printf("\nCODIGO INVALIDO, INFORME ALGO ENTRE 0 E %d.", (contador_entradas - 1));
			}				
			printf("\nCODIGO DO FUNCIONARIO: ");
			scanf("%d", &cod);
		}			
		strcpy(funcionario_temp[encontrados].nome, funcionario[cod].nome);
		funcionario_temp[encontrados].idade = funcionario[cod].idade;
		funcionario_temp[encontrados].sexo = funcionario[cod].sexo;
		strcpy(funcionario_temp[encontrados].cargo,funcionario[cod].cargo);
		funcionario_temp[encontrados].salario = funcionario[cod].salario;
		encontrados++;		
	}//fim if codigo
		
	//pesquisar por nome
	if(strcmp(tipo, "NOME") == 0){
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
				strcpy(funcionario_temp[encontrados].nome, funcionario[indice].nome);
				funcionario_temp[encontrados].idade = funcionario[indice].idade;
				funcionario_temp[encontrados].sexo = funcionario[indice].sexo;
				strcpy(funcionario_temp[encontrados].cargo,funcionario[indice].cargo);
				funcionario_temp[encontrados].salario = funcionario[indice].salario;
				encontrados++;
			}
		}		
	}//fim if nome
		
	//pesquisar por idade	
	if(strcmp(tipo, "IDADE") == 0){
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
						flag = 1;
					}					
					if(flag == 1){
						strcpy(funcionario_temp[encontrados].nome, funcionario[indice].nome);
						funcionario_temp[encontrados].idade = funcionario[indice].idade;
						funcionario_temp[encontrados].sexo = funcionario[indice].sexo;
						strcpy(funcionario_temp[encontrados].cargo,funcionario[indice].cargo);
						funcionario_temp[encontrados].salario = funcionario[indice].salario;
						encontrados++;
					}
				}
				break;
			case '2':
				for(indice = 0; indice < contador_entradas; indice++){
					flag = 0;
					if(idade == funcionario[indice].idade){	
						flag = 1;
					}					
					if(flag == 1){
						strcpy(funcionario_temp[encontrados].nome, funcionario[indice].nome);
						funcionario_temp[encontrados].idade = funcionario[indice].idade;
						funcionario_temp[encontrados].sexo = funcionario[indice].sexo;
						strcpy(funcionario_temp[encontrados].cargo,funcionario[indice].cargo);
						funcionario_temp[encontrados].salario = funcionario[indice].salario;
						encontrados++;
					}
				}
				break;
			case '3':
				for(indice = 0; indice < contador_entradas; indice++){
					flag = 0;
					if(funcionario[indice].idade >= idade){	
						flag = 1;
					}					
					if(flag == 1){
						strcpy(funcionario_temp[encontrados].nome, funcionario[indice].nome);
						funcionario_temp[encontrados].idade = funcionario[indice].idade;
						funcionario_temp[encontrados].sexo = funcionario[indice].sexo;
						strcpy(funcionario_temp[encontrados].cargo,funcionario[indice].cargo);
						funcionario_temp[encontrados].salario = funcionario[indice].salario;
						encontrados++;
					}
				}	
				break;
		}
	}//fim if idade		
		
	//pesquisar por sexo
	if(strcmp(tipo, "SEXO") == 0){
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
			flag = 0;

			if(sexo == funcionario[indice].sexo){
				flag = 1;
			}
			
			if(flag == 1){
				strcpy(funcionario_temp[encontrados].nome, funcionario[indice].nome);
				funcionario_temp[encontrados].idade = funcionario[indice].idade;
				funcionario_temp[encontrados].sexo = funcionario[indice].sexo;
				strcpy(funcionario_temp[encontrados].cargo,funcionario[indice].cargo);
				funcionario_temp[encontrados].salario = funcionario[indice].salario;
				encontrados++;
			}
		}	
	}//fim if sexo
		
	//pesquisar por cargo
	if(strcmp(tipo, "CARGO") == 0){
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
				strcpy(funcionario_temp[encontrados].nome, funcionario[indice].nome);
				funcionario_temp[encontrados].idade = funcionario[indice].idade;
				funcionario_temp[encontrados].sexo = funcionario[indice].sexo;
				strcpy(funcionario_temp[encontrados].cargo,funcionario[indice].cargo);
				funcionario_temp[encontrados].salario = funcionario[indice].salario;
				encontrados++;
			}
		}		
	}//fim if cargo
		
	//pesquisar por salario	
	if(strcmp(tipo, "SALARIO") == 0){
		unsigned short int contadorTemp = 0;
		float salario;
		char opcao;

		do{
			printf("\nSALARIO: R$ ");
			scanf("%f", &salario);
	//		salário mínimoR$ 1.045,00 
			if(salario < 400){
				puts("Informe um salário válido, pois menos que R$ 400,00 nem jovem aprendiz recebe...");
			}
		}while(salario < 400);
		
		printf("\n\n1 - menores ou com salario igual a %.2f", salario);
		printf("\n2 - com salario igual a %.2f", salario);
		printf("\n3 - maiores ou com salario igual a %.2f", salario);
		printf("\nDESEJA PROCURAR OS FUNCIONARIOS: ");
		fflush(stdin);
		opcao = getche();
		while((opcao == '0')||(opcao > '3')){
			printf("TIPO DE CONSULTA INVALIDO: ");
			contadorTemp++;
			if(contadorTemp > 2){				
				printf("\n1 - menores ou com salario igual a %.2f", salario);
				printf("\n2 - com salario igual a %.2f", salario);
				printf("\n3 - maiores ou com salario igual a %.2f", salario);
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
					if(funcionario[indice].salario <= salario){	
						flag = 1;
					}					
					if(flag == 1){
						strcpy(funcionario_temp[encontrados].nome, funcionario[indice].nome);
						funcionario_temp[encontrados].idade = funcionario[indice].idade;
						funcionario_temp[encontrados].sexo = funcionario[indice].sexo;
						strcpy(funcionario_temp[encontrados].cargo,funcionario[indice].cargo);
						funcionario_temp[encontrados].salario = funcionario[indice].salario;
						encontrados++;
					}
				}
				break;
			case '2':
				for(indice = 0; indice < contador_entradas; indice++){
					flag = 0;
					if(salario == funcionario[indice].salario){	
						flag = 1;
					}					
					if(flag == 1){
						strcpy(funcionario_temp[encontrados].nome, funcionario[indice].nome);
						funcionario_temp[encontrados].idade = funcionario[indice].idade;
						funcionario_temp[encontrados].sexo = funcionario[indice].sexo;
						strcpy(funcionario_temp[encontrados].cargo,funcionario[indice].cargo);
						funcionario_temp[encontrados].salario = funcionario[indice].salario;
						encontrados++;
					}
				}
				break;
			case '3':
				for(indice = 0; indice < contador_entradas; indice++){
					flag = 0;
					if(funcionario[indice].salario >= salario){	
						flag = 1;
					}					
					if(flag == 1){
						strcpy(funcionario_temp[encontrados].nome, funcionario[indice].nome);
						funcionario_temp[encontrados].idade = funcionario[indice].idade;
						funcionario_temp[encontrados].sexo = funcionario[indice].sexo;
						strcpy(funcionario_temp[encontrados].cargo,funcionario[indice].cargo);
						funcionario_temp[encontrados].salario = funcionario[indice].salario;
						encontrados++;
					}
				}	
				break;
		}
	}//fim if salario		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		

		
			
		printf("\n\nPESQUISA POR %s", tipo);
		printf("\nQUANTIDADE DE FUNCIONARIOS ENCONTRADOS: %i\n\n", encontrados);
		
		printf("%-30s%-6s%-6s%-20s%-10s\n","NOME","IDADE","SEXO","CARGO","SALARIO(R$)");
		if(encontrados <= 0){
			puts("NENHUM FUNCIONARIO ENCONTRADO COM A INFORMACAO SOLICITADA.");
		}else{
			for(indice = 0; indice < encontrados; indice++){//mostra nome de todos os func
		
		//		printf("%03d ", indice);
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
		printf("\n\n\n\n");

}
	

void gravarEntrada(struct dados_pessoais *funcionario, FILE *arq){	
	int indice, tamanho_struct = sizeof(struct dados_pessoais);
		fwrite(funcionario, sizeof(struct dados_pessoais), 1, arq);
}

int porStruct(struct dados_pessoais funcionario[]){
	int indice, contador_entradas;
	FILE *arq;
	arq = fopen("dados_funcionarios.bin", "rb");
	if(arq == NULL){
		printf("\a\nERRO AO LER O ARQUIVO: dados_funcionarios.bin!");
		sleep(5);
		exit(1);
	}else{
		indice = contador_entradas = 0;
		
		while(1){
			if(feof(arq)){
				break;
			}
			contador_entradas = fread(funcionario, sizeof(struct dados_pessoais), MAX_FUNC, arq);	
		}
		
	}//fim else fopen "rb"	
	fclose(arq);
	return contador_entradas;
}

