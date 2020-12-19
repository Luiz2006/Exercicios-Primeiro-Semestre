/*
Name: 
Copyright: MIT License
Author: Luiz Araujo - luizcarlos_bsb2006@hotmail.com
Date:
Description: 
*/

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<locale.h>
#include<time.h>

#define MAX_FUNC 100

//struct dados_pessoais1{
//	char nome[31];
//	int idade;
//	char sexo;
//	char cargo[21];
//	float salario;
//};
struct dados_pessoais1{
	//alinhar depois	
	unsigned short codigo;	//2bytes
	char nome[31];			//31bytes
	unsigned short idade;	//2bytes
	char sexo;				//1bytes
	char cargo[21];			//21bytes
	float salario;			//4bytes
	char pad[3];			//pra alinhar
};
struct dados_pessoais{
	//alinhar depois	
	unsigned short codigo;	//2bytes
	char nome[31];			//31bytes
	unsigned short idade;	//2bytes
	char sexo;				//1bytes
	char cargo[21];			//21bytes
	float salario;			//4bytes
};
 
 

int main(void){
	int tamanho;
	unsigned short age;
	struct dados_pessoais1 func_anterior[MAX_FUNC];
	struct dados_pessoais funcionario[MAX_FUNC];
	struct dados_pessoais c[MAX_FUNC];
	
	
	int tam = sizeof(struct dados_pessoais);
printf("TAMANHO STRUCT: %d", tam);


//===========================================================//
//		CONTAR QUANTOS FUNCIONARIOS CADASTRADOS				 //
//===========================================================//

	int indice, contador_entradas;
	FILE *fp;
	fp = fopen("anterior\\dados_funcionarios.bin", "rb");
	if(fp == NULL){
//		fp = fopen("dados_funcionarios.bin", "wb");
		printf("\a\nERRO AO LER O ARQUIVO ANTERIOR na raiz!");
		sleep(3);
		exit(1);
	}else{
		indice = contador_entradas = 0;
		
		while(1){
			if(feof(fp)){
				break;
			}
			contador_entradas = fread(func_anterior, sizeof(struct dados_pessoais), MAX_FUNC, fp);	
		}
		
	}//fim else fopen "rb"	
	
	fclose(fp);
	
	FILE *arq_anterior, *arq;
	
	arq_anterior = fopen("anterior\\dados_funcionarios.bin", "rb");
	if(arq_anterior == NULL){
		puts("Erro ao abrir o arquivo anterior, na raiz.");
	}
	
	fread(func_anterior, sizeof(struct dados_pessoais1), contador_entradas, arq_anterior);
	
	fclose(arq_anterior);

//===========================================================
//		passar tudo pra struct nova	
//===========================================================
	
	for(indice = 0; indice < contador_entradas; indice++){		
		funcionario[indice].codigo = indice;
		strcpy(funcionario[indice].nome, func_anterior[indice].nome);
		funcionario[indice].idade = func_anterior[indice].idade;
		funcionario[indice].sexo = func_anterior[indice].sexo;
		strcpy(funcionario[indice].cargo, func_anterior[indice].cargo);
		funcionario[indice].salario = func_anterior[indice].salario;
		
	}
	
//===========================================================
//		dar uns confere
//===========================================================

	for(indice = 0; indice < contador_entradas; indice++){		
		printf("\n\nfunc_anterior[%d].nome: %s", indice, func_anterior[indice].nome);	
		printf("\nfunc_anterior[%d].idade: %d", indice, func_anterior[indice].idade);
		printf("\nfunc_anterior[%d].sexo: %c", indice, func_anterior[indice].sexo);
		printf("\nfunc_anterior[%d].cargo: %s", indice, func_anterior[indice].cargo);
		printf("\nfunc_anterior[%d].salario: %.2f", indice, func_anterior[indice].salario);

	}
	
	for(indice = 0; indice < contador_entradas; indice++){		
		printf("\n\nfuncionario.codigo: %d", funcionario[indice].codigo);
		printf("\nfunc_anterior[%d].nome: %s == funcionario[%d].nome: %s", indice, func_anterior[indice].nome, indice, funcionario[indice].nome);	
		printf("\nfunc_anterior[%d].idade: %d == funcionario[%d].idade: %d", indice, func_anterior[indice].idade, indice, funcionario[indice].idade);
		printf("\nfunc_anterior[%d].sexo: %c == funcionario[%d].sexo: %c", indice, func_anterior[indice].sexo, indice, funcionario[indice].sexo);
		printf("\nfunc_anterior[%d].cargo: %s == funcionario[%d].cargo: %s", indice, func_anterior[indice].cargo, indice, funcionario[indice].cargo);
		printf("\nfunc_anterior[%d].salario: %.2f == funcionario[%d].salario: R$ %.2f", indice, func_anterior[indice].salario, indice, funcionario[indice].salario);

	}
printf("\n\n\n");
//===========================================================
//		passar pro novo arquivo
//===========================================================

	arq = fopen("dados_funcionarios.bin", "wb");
	if(arq == NULL){
		puts("Erro ao abrir o arquivo novo, na pasta novo22222222222222222222.");
	}
	
	fwrite(funcionario, sizeof(struct dados_pessoais), contador_entradas, arq);
	
	fclose(arq);
//===========================================================
//		dar uns confere 2
//===========================================================
	arq = fopen("dados_funcionarios.bin", "rb");
	if(arq == NULL){
		puts("Erro ao abrir o arquivo novo, na pasta novo333333333333333333.");
	}
	fread(c, sizeof(struct dados_pessoais), contador_entradas, arq);
	for(indice = 0; indice < contador_entradas; indice++){		
//		printf("\n\nfunc_anterior.codigo: %d", funcionario[indice].codigo);
//		printf("\nfunc_anterior[%d].nome: %s", indice, func_anterior[indice].nome);	
//		printf("\nfunc_anterior[%d].idade: %d", indice, func_anterior[indice].idade);
//		printf("\nfunc_anterior[%d].sexo: %c", indice, func_anterior[indice].sexo);
//		printf("\nfunc_anterior[%d].cargo: %s", indice, func_anterior[indice].cargo);
//		printf("\nfunc_anterior[%d].salario: %.2f", indice, func_anterior[indice].salario);
		printf("%03d ", c[indice].codigo);
		printf("%-30s",c[indice].nome);
		printf("%-6d",c[indice].idade);
		if(c[indice].sexo == 'f'){
			printf("%-6s%","FEM");
		}else if(c[indice].sexo == 'm'){
			printf("%-6s%","MASC");
		}else{
			printf("%-6s%","INDEF");
		}
		printf("%-20s",c[indice].cargo);
		printf("%10.2f",c[indice].salario);
		printf("\n");
	}
	
	fclose(arq);
		
	
	printf("\n\n\nPRESSIONE QUALQUER TECLA PARA ENCERRAR.\n");
	getch();
	return 0;
}
