/*
Name: arquivosStruct.c
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
	char nome[50];
	int idade;
	char sexo;
	char cargo[30];
	float salario;
};

void testarEntradas(struct dados_pessoais funcionario);
void lerValidarNome(char nome[]);
int lerValidarIdade();
char lerValidarSexo();
void lerValidarCargo(char cargo[]);
float lerValidarSalario();
void gravarEntradas(struct dados_pessoais funcionario, FILE *arq);

int main(void){	
	setlocale(LC_ALL, "Portuguese");	
	struct dados_pessoais funcionario[MAX_FUNC];
	int contadorFuncionario = 0;
	char continuar;
	
	FILE *arq = fopen("dados_funcionarios.txt", "a");
	if(arq == NULL){
		printf("\nERRO AO ABRIR O ARQUIVO: dados_funcionarios.txt!");
		sleep(5);
		exit(0);
	}
	
	puts("CADASTRO DE FUNCIONÁRIOS");	
	do{
		printf("\n%dº FUNCIONÁRIO", contadorFuncionario + 1);		
		lerValidarNome(funcionario[contadorFuncionario].nome);
		funcionario[contadorFuncionario].idade = lerValidarIdade();
		funcionario[contadorFuncionario].sexo = lerValidarSexo();
		lerValidarCargo(funcionario[contadorFuncionario].cargo);
		funcionario[contadorFuncionario].salario = lerValidarSalario();
		printf("Novo cadastro? (s para continuar) ");
		fflush(stdin);
		continuar = getchar();
		
		gravarEntradas(funcionario[contadorFuncionario], arq);
		if(continuar != 's' && continuar != 'S'){
			break;
		}
//		testarEntradas(funcionario[contadorFuncionario]);
		contadorFuncionario++;
	}while(contadorFuncionario < MAX_FUNC);

	fclose(arq);
	
	printf("\n\n\nPRESSIONE QUALQUER TECLA PARA ENCERRAR.\n");
	getch();
	return 0;
}

void lerValidarNome(char nome[]){
	do{
		puts("\nNOME COMPLETO:");
		fflush(stdin);
		gets(nome);
		if((strlen(nome) <= 5)){
			puts("informe um nome válido!");
		}
	}while((strlen(nome) <= 5));	
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
	}while(strlen(cargo) < 3);
}

float lerValidarSalario(){
	float salario;

	do{
		printf("SALÁRIO:\nR$ ");
		scanf("%f", &salario);
//		salário mínimoR$ 1.045,00 
		if(salario < 400){
			puts("Informe um salário válido, pois menos que R$ 400,00 nem jovem aprendiz recebe...");
		}
	}while(salario < 400);
	return salario;
}

void testarEntradas(struct dados_pessoais funcionario){	
	printf("\n\n\n\n");
	printf("\nNome   : %s",funcionario.nome);
	printf("\nIdade  : %d",funcionario.idade);
	if(funcionario.sexo == 'f'){
		printf("\nSexo   : feminino");
	}else if(funcionario.sexo == 'm'){
		printf("\nSexo   : masculino");
	}else{
		printf("\nSexo   : indefinido");
	}
	printf("\nCargo  : %s",funcionario.cargo);
	printf("\nSALARIO: R$ %.2f",funcionario.salario);
}

void gravarEntradas(struct dados_pessoais funcionario, FILE *arq){	
	printf("\n");
	fputs(funcionario.nome, arq);
	fprintf(arq, "\n%d",funcionario.idade);
	fprintf(arq, "\n%c\n",funcionario.sexo);
	fputs(funcionario.cargo, arq);
	fprintf(arq, "\n%f\n",funcionario.salario);
}









