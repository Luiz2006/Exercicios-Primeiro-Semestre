/*
Name: arquivosStruct00CadastroFuncionarios.c
Copyright: MIT License
Author: Luiz Araujo - luizcarlos_bsb2006@hotmail.com
Date: 06/12/20 13:38
Description: Manipulação de Arquivos - cadastro de funcionarios que persista, utilizando struct.
*/

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<locale.h>

#define MAX_FUNC 100

struct dados_pessoais{
	unsigned short codigo;	//2bytes
	char nome[31];			//31bytes
	unsigned short idade;	//2bytes
	char sexo;				//1bytes
	char cargo[21];			//21bytes
	float salario;			//4bytes
	char pad[3];			//pra alinhar
};
	
void lerValidarNome();
int lerValidarIdade();
char lerValidarSexo();
void lerValidarCargo();
float lerValidarSalario();
void cadastrarFuncionarios();
void listarFuncionarios(char tipo);

int main(void){
	setlocale(LC_COLLATE, "Portuguese");
	setlocale(LC_MONETARY, "Portuguese");
	setlocale(LC_NUMERIC, "Portuguese");
	setlocale(LC_TIME, "Portuguese");	
	
	listarFuncionarios('h');
	cadastrarFuncionarios();
	listarFuncionarios('h');
	
	printf("\n\n\nPRESSIONE QUALQUER TECLA PARA ENCERRAR.\n");
	getch();
	return 0;
}

void lerValidarNome(char nome[]){
	struct dados_pessoais funcionario[MAX_FUNC];	
	int contador_entradas, indice;
	
	do{
		FILE *arq;
		arq = fopen("dados_funcionarios.bin", "rb");
		if(arq == NULL){
			printf("\a\nERRO AO ACESSAR O BANCO DE DADOS.");
			sleep(5);
			exit(0);
		}
		contador_entradas = fread(funcionario, sizeof(struct dados_pessoais), MAX_FUNC, arq);
		fclose(arq);
		
		puts("\nNOME COMPLETO:");
		fflush(stdin);
		gets(nome);
		if((strlen(nome) <= 5)){
			puts("informe um nome valido!");
		}
		if((strlen(nome) > 30)){
			puts("informe um nome menor!");
		}
	}while((strlen(nome) <= 5)||(strlen(nome) > 30));

	for(indice = 0; indice < contador_entradas; indice++){
		while(strcmp(nome, funcionario[indice].nome) == 0){
			puts("Funcionário já cadastrado, informe outro nome:");	
			fflush(stdin);
			gets(nome);
			if((strlen(nome) <= 5)){
				puts("informe um nome válido!");
			}
			indice = 0;
		}
	}		
}

int lerValidarIdade(){
	int idade;	
	
	do{
		puts("IDADE:");
		scanf("%d", &idade);
		if(idade < 14){
			puts("Na CLT, a idade mínima prevista é de 14 anos, desde que o menor seja contratado na condição de aprendiz.");
		}
		if(idade > 120){
			puts("Informe uma idade válida, pois com mais de 120 anos é improvável que ainda esteja trabalhando.");
		}
	}while((idade < 14) || (idade > 120));
	return idade;
}

char lerValidarSexo(){
	char sexo;
	
	do{
		puts("SEXO: ");
		fflush(stdin);
		sexo = getchar();
		sexo = tolower(sexo);
		if(sexo != 'f' && sexo != 'm' && sexo != 'x'){
			puts("F para feminino | M para masculino | X para indefinido ");
		}		
	}while(sexo != 'f' && sexo != 'm' && sexo != 'x');
	return sexo;
}

void lerValidarCargo(char cargo[]){
	do{
		puts("CARGO:");
		fflush(stdin);
		gets(cargo);
		if(strlen(cargo) < 3){
			puts("Informe um cargo válido!");
		}
		if(strlen(cargo) > 20){
			puts("Informe um cargo menor que 20!");
		}
	}while((strlen(cargo) < 3)||(strlen(cargo) > 20));
}

float lerValidarSalario(){
	float salario;

	do{
		printf("SALARIO:\nR$ ");
		scanf("%f", &salario);
		if(salario < 400){
			puts("Informe um salário válido, pois menos que R$ 400,00 nem jovem aprendiz recebe...");
		}
	}while(salario < 400);
	return salario;
}

void listarFuncionarios(char tipo){	
	struct dados_pessoais funcionario[MAX_FUNC];
	int indice, contador_entradas;
	FILE *arq;
	
	arq = fopen("dados_funcionarios.bin", "rb");
	if(arq == NULL){
		printf("\aNENHUM FUNCIONARIO ENCONTRADO, VERIFIQUE O BANCO DE DADOS.");
		sleep(5);
		exit(0);
	}
	contador_entradas = fread(funcionario, sizeof(struct dados_pessoais), MAX_FUNC, arq);
	fclose(arq);
	
	system("CLS");
	printf("QUANTIDADE DE FUNCIONARIOS: %i\n", contador_entradas);
	if((tipo == 'v') || (tipo == 'V')){
//		VERTICALIZADO
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
		printf("\n");
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
		printf("\n");
	}
}

void cadastrarFuncionarios(){	
	FILE *arq;
	char continuar = 's';
	int contador_entradas;
	struct dados_pessoais funcionario_gravar, funcionario[MAX_FUNC];
	puts("CADASTRO DE FUNCIONARIOS");

	do{
		arq = fopen("dados_funcionarios.bin", "rb");
		if(arq == NULL){
			printf("\a\nERRO AO ACESSAR O BANCO DE DADOS.");
			sleep(5);
			exit(0);
		}
		contador_entradas = fread(funcionario, sizeof(struct dados_pessoais), MAX_FUNC, arq);
		fclose(arq);
		
		unsigned short entradas_temp = (funcionario[contador_entradas - 1].codigo);
		funcionario_gravar.codigo =  entradas_temp + 1;
		printf("\nFUNCIONARIO %d",  contador_entradas);	
		lerValidarNome(funcionario_gravar.nome);
		funcionario_gravar.idade = lerValidarIdade();
		funcionario_gravar.sexo = lerValidarSexo();
		lerValidarCargo(funcionario_gravar.cargo);
		funcionario_gravar.salario = lerValidarSalario();
		
		arq = fopen("dados_funcionarios.bin", "ab");
		if(arq == NULL){
			printf("\a\nERRO AO ABRIR O ARQUIVO: dados_funcionarios.bin!");
			sleep(5);
			exit(0);
		}
		fwrite(&funcionario_gravar, sizeof(struct dados_pessoais), 1, arq);
		fclose(arq);
		
		printf("Novo cadastro? (s para continuar) ");
		fflush(stdin);
		continuar = getchar();

		if(continuar != 's' && continuar != 'S'){
			break;
		}			
	}while(contador_entradas < MAX_FUNC);
}
