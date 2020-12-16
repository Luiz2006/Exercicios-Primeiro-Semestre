/*
Name: arquivosStruct00DeletarFuncionarios.c
Copyright: MIT License
Author: Luiz Araujo - luizcarlos_bsb2006@hotmail.com
Date: 14/12/20 10:48
Description: Manipulação de Arquivos - apaga cadastro de funcionario.
*/

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<locale.h>
#include<time.h>

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

//void lerValidarNome(int contador_entradas, struct dados_pessoais funcionario[]);
//int lerValidarIdade();
//char lerValidarSexo();
//void lerValidarCargo(char cargo[]);
//float lerValidarSalario();
int contarEntradas(struct dados_pessoais funcionario[]);
int deletarFuncionario(struct dados_pessoais funcionario[], int contador_entradas);
//void gravarEntrada(struct dados_pessoais *funcionario, FILE *arq);
void listarFuncionarios(struct dados_pessoais funcionario[], int contador_entradas);

int main(void){
	setlocale(LC_COLLATE, "Portuguese");
	setlocale(LC_MONETARY, "Portuguese");
	setlocale(LC_NUMERIC, "Portuguese");
	setlocale(LC_TIME, "Portuguese");	
	struct dados_pessoais funcionario[MAX_FUNC];
	int contador_funcionario = 0, indice = 0, indice2 = 0, contador_entradas = 0;
	char continuar;
	contador_entradas = contarEntradas(funcionario);
	deletarFuncionario(funcionario, contador_entradas);

	printf("\n\n\nPRESSIONE QUALQUER TECLA PARA ENCERRAR.\n");
	getch();
	return 0;
}

void listarFuncionarios(struct dados_pessoais funcionario[], int contador_entradas){	
	int indice;

	system("CLS");
	printf("QUANTIDADE DE FUNCIONARIOS: %i\n", contador_entradas);

	printf("COD %-30s%-6s%-6s%-20s%-10s\n","NOME","IDADE","SEXO","CARGO","SALARIO(R$)");
	for(indice = 0; indice < contador_entradas; indice++){//mostra nome de todos os func
		printf("%03d ", funcionario[indice].codigo);
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

//void gravarEntrada(struct dados_pessoais *funcionario, FILE *arq){	
//	int indice, tamanho_struct = sizeof(struct dados_pessoais);
//		fwrite(funcionario, sizeof(struct dados_pessoais), 1, arq);
//}

int contarEntradas(struct dados_pessoais funcionario[]){
	int indice, contador_entradas;
	FILE *arq;
	arq = fopen("dados_funcionarios.bin", "rb");
	if(arq == NULL){
		arq = fopen("dados_funcionarios.bin", "wb");
//		printf("\a\nERRO AO LER O ARQUIVO: dados_funcionarios.bin!");
//		sleep(5);
//		exit(1);
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

int deletarFuncionario(struct dados_pessoais funcionario[], int contador_entradas){	
	FILE *arq;
	char continuar = 's', opcao;
	int resultado, cod, controle_erros, contadorTemp;
	struct dados_pessoais c[MAX_FUNC];

	do{	
		system("CLS");
		puts("APAGAR CADASTRO DE FUNCIONARIOS");
		arq = fopen("dados_funcionarios.bin", "rb");
		if(arq == NULL){
			printf("\a\nERRO AO ABRIR O ARQUIVO: dados_funcionarios.bin!");
			sleep(5);
			exit(1);
		}
		fclose(arq);
		puts("1 - RESTAURAR BACKUP");
		puts("2 - INSERIR CODIGO");
		puts("3 - LISTAR TODOS");
		puts("0 - APAGAR TODOS");
		printf("OPCAO: ");
		fflush(stdin);
		opcao = getche();

		while((opcao > '2') || (isdigit(opcao) == 0)){
			contadorTemp++;
			if(contadorTemp > 2){		
				printf("\n\nINFORME UM NUMERO DE 0 a 2.");		
				puts("\n1 - INSERIR CODIGO");
				puts("2 - LISTAR TODOS");
				puts("0 - APAGAR TODOS");
				printf("OPCAO:");
			}else{
				printf("\nOPCAO INVALIDA: ");
			}		 
			fflush(stdin);
			opcao = getche();
		}



		switch(opcao){
			case '0':	
				printf("\a\a\n'S' PARA APAGAR OS DADOS DE TODOS OS FUNCIONARIOS:\n");
				fflush(stdin);
				continuar = getchar();

				if(continuar == 's' || continuar == 'S'){
				    char nome_anterior[23] = "dados_funcionarios.bin";
				    char nome_novo[32] = "BKP\\dados_funcionarios.bin";

				    if((arq = fopen("dados_funcionarios.bin", "rb")) == NULL){

					}

				    if(rename(nome_anterior, nome_novo) == 0) {
				      printf("\nARQUIVO APAGADO COM SUCESSO.\n");
				    } else {
				       printf("\nNAO FOI POSSIVEL APAGAR O ARQUIVO\n");
				    }	
				}	
				break;
			case '1':					
				printf("\a\a\n'S' PARA RESTAURAR O ULTIMO BACKUP:\n");
				fflush(stdin);
				continuar = getchar();

				if(continuar == 's' || continuar == 'S'){






				    char nome_anterior[32] = "BKP\\dados_funcionarios.bin";
				    char nome_novo[27] = "dados_funcionarios.bin";

				   	remove(nome_novo);









					criar vários bkp. loop verificando a existencia de 0 a 9 ou MAX;


				    if(rename(nome_anterior, nome_novo) == 0) {
				      printf("\nARQUIVO RESTAURADO COM SUCESSO.\n");
				    } else {
				       printf("\nNAO FOI POSSIVEL RESTAURAR O ARQUIVO\n");
				    }	
				}	
				break;













//					arq = fopen("dados_funcionarios.bin","w+b");
//					
//					if(arq == NULL){
//						printf("\a\a\a\nERRO AO SALVAR NO ARQUIVO: dados_funcionarios.bin!");
//						sleep(5);
//						exit(1);
//					}else{
//						strcpy(c[cod].nome, texto_temp);
//						fwrite(&c, sizeof(struct dados_pessoais), contador_entradas, arq);
//						printf("\a\nAlteracao realizada com sucesso!");
//					}
//					fclose(arq);
//			
//					
//				}else{
//					break;
//				}
//	
//				break;
//			case '1':				
//				break;
//			case '2':				
//				break;
		}//fim switch










		puts("TEM O CODIGO? (s para sim)");
		fflush(stdin);
		continuar = getche();
		if(continuar != 's' && continuar != 'S'){
			contador_entradas = (int)contarEntradas(funcionario);
			fread(&c, sizeof(struct dados_pessoais), contador_entradas, arq);
			listarFuncionarios(funcionario, contador_entradas);
		}		
		fclose(arq);
		//pesquisar por codigo
		printf("CODIGO DO FUNCIONARIO: ");
		scanf("%d", &cod);
		while((cod < 0) || (cod >= contador_entradas)){
			controle_erros++;
			if(controle_erros > 2){
				printf("\nCODIGO INVALIDO, INFORME ALGO ENTRE 0 E %d.", (contador_entradas - 1));
			}				
			printf("\nCODIGO DO FUNCIONARIO: ");
			scanf("%d", &cod);
		}
		do{
			system("CLS");
			printf("CADASTRO DO FUNCIONARIO: %d", cod);
			printf("\n1 - NOME   : %s", c[cod].nome);
			printf("\n2 - IDADE  : %d", c[cod].idade);

			if(c[cod].sexo == 'f'){
				printf("\n3 - SEXO   : %s","FEMININO");
			}else if(c[cod].sexo == 'm'){
				printf("\n3 - SEXO   : %s","MASCULINO");
			}else{
				printf("\n3 - SEXO   : %s","INDEFINIDO");
			}
			printf("\n4 - CARGO  : %s", c[cod].cargo);
			printf("\n5 - SALARIO:R$ %.2f", c[cod].salario);
			fclose(arq);		
			printf("\n0 - CANCELAR");
			printf("\nALTERAR:");
			fflush(stdin);
			opcao = getche();

			contadorTemp = 0;













			printf("\nEditar o mesmo funcionario? (s para sim) ");
			fflush(stdin);
			continuar = getche();
		}while(continuar == 's' || continuar == 'S');

		printf("\nEditar outro funcionario? (s para sim) ");
		fflush(stdin);
		continuar = getche();

		if(continuar != 's' && continuar != 'S'){
			break;
		}			
	}while(contador_entradas < MAX_FUNC);
	return contador_entradas;
}
