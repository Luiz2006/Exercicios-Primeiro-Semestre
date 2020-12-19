/*
Name: arquivosStruct00CadastroFuncionarios.c
Copyright: MIT License
Author: Luiz Araujo - luizcarlos_bsb2006@hotmail.com
Date: 06/12/20 13:38
Description: Manipula��o de Arquivos - cadastro de funcionarios que persista, utilizando struct.
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
	
void lerValidarNome();
int lerValidarIdade();
char lerValidarSexo();
void lerValidarCargo();
float lerValidarSalario();
void cadastrarFuncionarios();
void listarFuncionarios(char tipo);
unsigned short int lerArquivo(struct dados_pessoais funcionario[]);

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

void lerValidarNome(char nome[]){
	struct dados_pessoais funcionario[MAX_FUNC];	
	unsigned short int contador_entradas, indice;	
	do{
		contador_entradas = lerArquivo(funcionario);		
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
			puts("Funcion�rio j� cadastrado, informe outro nome:");	
			fflush(stdin);
			gets(nome);
			if((strlen(nome) <= 5)){
				puts("informe um nome v�lido!");
			}
			indice = 0;
		}
	}		
}

int lerValidarIdade(){
	unsigned int idade;	
	do{
		puts("IDADE:");
		scanf("%d", &idade);
		if(idade < 14){
			puts("Na CLT, a idade m�nima prevista � de 14 anos, desde que o \nmenor seja contratado na condi��o de aprendiz.");
		}
		if(idade > 100){
			puts("Informe uma idade v�lida, pois com mais de 100 anos � \nimprov�vel que ainda esteja trabalhando.");
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
			puts("Informe um cargo v�lido!");
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
			puts("Informe um sal�rio v�lido, pois menos que R$ 400,00 \nnem jovem aprendiz recebe...");
		}
	}while(salario < 400);
	return salario;
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

void cadastrarFuncionarios(){	
	FILE *arq;
	char continuar = 's';
	unsigned short int contador_entradas;
	struct dados_pessoais funcionario_gravar, funcionario[MAX_FUNC];
	
	puts("CADASTRO DE FUNCIONARIOS");
	do{
		contador_entradas = lerArquivo(funcionario);	
		
		unsigned short entradas_temp = (funcionario[contador_entradas - 1].codigo);
		funcionario_gravar.codigo =  entradas_temp + 1;
		printf("\nFUNCIONARIO %d", (contador_entradas + 1));	
		lerValidarNome(funcionario_gravar.nome);
		funcionario_gravar.idade = lerValidarIdade();
		funcionario_gravar.sexo = lerValidarSexo();
		lerValidarCargo(funcionario_gravar.cargo);
		funcionario_gravar.salario = lerValidarSalario();
		
		arq = fopen("dados_funcionarios.bin", "ab");
		contador_entradas = fwrite(&funcionario_gravar, sizeof(struct dados_pessoais), 1, arq);
		if((arq == NULL) || (contador_entradas == 0)){
			printf("\a\nERRO AO SALVAR CADASTRO!");
			sleep(5);
			exit(1);
		}
		fclose(arq);		
		printf("Novo cadastro? (s para continuar) ");
		fflush(stdin);
		continuar = getchar();
		if(continuar != 's' && continuar != 'S'){
			break;
		}			
	}while(contador_entradas < MAX_FUNC);
}
