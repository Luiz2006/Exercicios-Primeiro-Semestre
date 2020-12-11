/*
Name: arquivosStruct.c
Copyright: MIT License
Author: Luiz Araujo - luizcarlos_bsb2006@hotmail.com
Date: 06/12/20 13:38
Description: Manipulação de Arquivos - cadastro de funcionarios que persista, utilizando struct.
*/


//VALIDAR CADASTRO DE NOMES REPETIDOS

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<locale.h>

#define MAX_FUNC 100

struct dados_pessoais{
	char nome[31];
	int idade;
	char sexo;
	char cargo[21];
	float salario;
};


void lerValidarNome(char nome[], char tudo[][31], char nome_comparar[][31], int contador_nome);
int lerValidarIdade();
char lerValidarSexo();
void lerValidarCargo(char cargo[]);
float lerValidarSalario();
void gravarEntrada(struct dados_pessoais *funcionario, FILE *arq);
void testarEntradas(struct dados_pessoais funcionario[], int contador_entradas);
int porStruct(struct dados_pessoais funcionario[]);
int main(void){
	setlocale(LC_ALL, "Portuguese");	
	struct dados_pessoais funcionario[MAX_FUNC];
	int contador_funcionario = 0, indice = 0, indice2 = 0, contador_entradas = 0, contador_nome = 0;
	char continuar, tudo[MAX_FUNC * 5][31], nome_comparar[MAX_FUNC][31];

	contador_entradas = porStruct(funcionario);
	
	
	if(contador_entradas > 0){
		testarEntradas(funcionario, contador_entradas);
	}
	
	
	puts("CADASTRO DE FUNCIONÁRIOS");	
	FILE *arq;
	
	do{		
//		arq = fopen("dados_funcionarios.bin", "wb");
		arq = fopen("dados_funcionarios.bin", "ab");
		if(arq == NULL){
			printf("\a\nERRO AO ABRIR O ARQUIVO: dados_funcionarios.bin!");
			sleep(5);
			exit(0);
		}
		
		printf("\n FUNCIONÁRIO %d", contador_entradas + 1);		
		lerValidarNome(funcionario[contador_funcionario].nome, tudo, nome_comparar, contador_nome);
		funcionario[contador_funcionario].idade = lerValidarIdade();
		funcionario[contador_funcionario].sexo = lerValidarSexo();
		lerValidarCargo(funcionario[contador_funcionario].cargo);
		funcionario[contador_funcionario].salario = lerValidarSalario();
		
		gravarEntrada(&funcionario[contador_funcionario], arq);
							
		fclose(arq);
		contador_entradas++;
		
		printf("Novo cadastro? (s para continuar) ");
		fflush(stdin);
		continuar = getchar();

		if(continuar != 's' && continuar != 'S'){
			break;
		}			
	}while(contador_funcionario < MAX_FUNC);

	contador_entradas = porStruct(funcionario);
	testarEntradas(funcionario, contador_entradas);
	printf("\n\n\nPRESSIONE QUALQUER TECLA PARA ENCERRAR.\n");
	getch();
	return 0;
}

void lerValidarNome(char nome[], char tudo[][31], char nome_comparar[][31], int contador_nome){
	int indice;
	
	do{
		puts("\nNOME COMPLETO:");
		fflush(stdin);
		gets(nome);
		if((strlen(nome) <= 5)){
			puts("informe um nome válido!");
		}
		if((strlen(nome) > 30)){
			puts("informe um nome menor!");
		}
	}while((strlen(nome) <= 5)||(strlen(nome) > 30));



//		printf("contador_nome: %2i - %s", contador_nome, nome_comparar[indice]);//funfa
//	nome = strcat(nome, '\n');
	
//	for(indice = 0; indice < contador_nome; indice++){
////		printf("%2i - %s", indice, nome_comparar[indice]);//funfa
//		if(strcmp(nome, nome_comparar[indice]) >= strlen(nome)-2){// problema: está comparando só a primeira letra
////			printf("%2i - %s", indice, nome_comparar[indice]);
//			puts("Funcionário já cadastrado, informe outro nome:");	
//			fflush(stdin);
//			gets(nome);
//			if((strlen(nome) <= 5)){
//				puts("informe um nome válido!");
//			}
//			indice = 0;
//		}
//	}
	
	
	
	/*
//	tudo[MAX_FUNC][50]
		int matricula;
		int ind, flag;
		do{
			flag=0;
			printf("Digite a %i%c matricula:\n", qtde+1, 166);
			scanf("%i", &matricula);
			if(matricula<0){
				puts("Matricula deve ser maior ou igual a zero.");
				flag=1;
			}else{
				for(ind=0;ind<qtde;ind++){
					if(matricula==mat[ind]){
						puts("Matricula deve ser diferente.");
						flag=1;
						break;
					}
				}
			}
		}while(flag==1);
	
	
	
	
	
	
	*/
	
	
	
	
		
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
		printf("SALÁRIO:\nR$ ");
		scanf("%f", &salario);
//		salário mínimoR$ 1.045,00 
		if(salario < 400){
			puts("Informe um salário válido, pois menos que R$ 400,00 nem jovem aprendiz recebe...");
		}
	}while(salario < 400);
	return salario;
}

void testarEntradas(struct dados_pessoais funcionario[], int contador_entradas){	
	int indice;
	system("CLS");
	printf("QUANTIDADE DE FUNCIONARIOS: %i\n", contador_entradas);
//			//VERTICALIZADO
//	for(indice = 0; indice < contador_entradas; indice++){//mostra nome de todos os func
//
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
	printf("%-30s%-6s%-10s%-20s%-11s\n","NOME","IDADE","SEXO","CARGO","SALARIO(R$)");
	for(indice = 0; indice < contador_entradas; indice++){//mostra nome de todos os func

		printf("%-30s",funcionario[indice].nome);
		printf("%-6d",funcionario[indice].idade);
		if(funcionario[indice].sexo == 'f'){
			printf("%-10s%","feminino");
		}else if(funcionario[indice].sexo == 'm'){
			printf("%-10s%","masculino");
		}else{
			printf("%-10s%","indefinido");
		}
		printf("%-20s",funcionario[indice].cargo);
		printf("%10.2f",funcionario[indice].salario);
		printf("\n");
	}
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






