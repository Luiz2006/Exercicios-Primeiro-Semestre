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
#define MAX_BKP 10

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
int deletarFuncionario(struct dados_pessoais funcionario[], int contador_entradas, char tipo[10]);
//void gravarEntrada(struct dados_pessoais *funcionario, FILE *arq);
void listarFuncionarios(struct dados_pessoais funcionario[], int contador_entradas);
void zerarBackups();

int main(void){
	setlocale(LC_COLLATE, "Portuguese");
	setlocale(LC_MONETARY, "Portuguese");
	setlocale(LC_NUMERIC, "Portuguese");
	setlocale(LC_TIME, "Portuguese");	
	struct dados_pessoais funcionario[MAX_FUNC];	
	int contador_funcionario = 0, indice = 0, indice2 = 0, contador_entradas = 0;
	char continuar;
	
	zerarBackups();
	contador_entradas = contarEntradas(funcionario);
	do{
		contador_entradas = deletarFuncionario(funcionario, contador_entradas, "MENU");
		
		printf("\nNOVA OPERACAO?\n(s para sim) ");
		fflush(stdin);
		continuar = getchar();
		contarEntradas(funcionario);
	}while(continuar == 's' || continuar == 'S');
	printf("\n\n\nPRESSIONE QUALQUER TECLA PARA ENCERRAR.\n");
	getch();
	return 0;
}

void zerarBackups(){
	FILE *bkp;
	int indice, contador_bkp = 0, resposta;
	char arquivo_anterior[32], arquivo_novo[32], arquivo_temp[32];
	char s_indice[2];
    strcpy(arquivo_novo, "BKP\\dados_funcionarios.bin");
//	strcpy(arquivo_anterior, "BKP\\dados_funcionarios.bin");

	strcpy(arquivo_temp, "BKP\\dados_funcionarios");
	itoa(MAX_BKP, s_indice, 10);
	strcat(arquivo_temp, s_indice);		
	strcat(arquivo_temp, ".bin");
	bkp = fopen(arquivo_temp, "rb");
	if(bkp != NULL){
		remove(arquivo_novo);
		fclose(bkp);
//			sleep(5);
		resposta = rename(arquivo_temp, arquivo_novo);
//			if(resposta == 0){
//				printf("\n\n\nRENOMEADO COM SUCESSO!");
//				sleep(5);
//			}else{
//				printf("\n\n\nERRO AO RENOMEAR!");
//				sleep(5);
//			}
		for(indice = 1; indice < MAX_BKP; indice++){
			strcpy(arquivo_temp, "BKP\\dados_funcionarios");
			itoa(indice, s_indice, 10);
			strcat(arquivo_temp, s_indice);		
			strcat(arquivo_temp, ".bin");
			remove(arquivo_temp);
		}
	}/*else{	//apagar depoisssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss
		printf("\n\n\nzerarBackups() NÃO FARA NADA!");
		sleep(5);
	}	*/
}







void listarFuncionarios(struct dados_pessoais funcionario[], int contador_entradas){	
	int indice;
	
	contarEntradas(funcionario);
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
	int contador_entradas;
	char opcao;
	FILE *arq;
	arq = fopen("dados_funcionarios.bin", "rb");
	if(arq == NULL){
		printf("\a\a\nNENHUM BANCO DE DADOS ENCONTRADO!\n");
		printf("DESEJA CRIAR UM NOVO BANCO DE DADOS? 's' para sim: ");
		fflush(stdin);
		opcao = getchar();
		if(opcao == 's' || opcao == 'S'){
			arq = fopen("dados_funcionarios.bin", "wb");
		}else{
			puts("DESEJA RESTAURAR O ULTIMO BACKUP?");
			puts("'s' para sim: ");
			fflush(stdin);
			opcao = getchar();
			if(opcao == 's' || opcao == 'S'){
				deletarFuncionario(funcionario, contador_entradas, "RESTAURAR");
			}else{
				printf("\nENCERRANDO PROGRAMA!");
				sleep(5);
				exit(1);
			}
		}
		
			
	}else{
		contador_entradas = 0;

		while(1){
			if(feof(arq)){
				break;
			}
			contador_entradas = fread(funcionario, sizeof(struct dados_pessoais), MAX_FUNC, arq);	
		}
	
	}//fim else fopen "rb"
//	contador_entradas = fread(funcionario, sizeof(struct dados_pessoais), contador_entradas, arq);		
	fclose(arq);
	return contador_entradas;
}

int deletarFuncionario(struct dados_pessoais funcionario[], int contador_entradas, char tipo[10]){	
	FILE *arq, *bkp;
	char continuar, opcao;
	int resultado, cod, controle_erros, contadorTemp, indice, posicao;
	struct dados_pessoais c[MAX_FUNC];

	zerarBackups();
	if(strcmp(tipo, "MENU") == 0){

		system("CLS");
		puts("APAGAR CADASTRO DE FUNCIONARIOS");
		arq = fopen("dados_funcionarios.bin", "rb");
		if(arq == NULL){
			printf("\a\a\nNENHUM BANCO DE DADOS ENCONTRADO!");
			printf("\nDESEJA CRIAR UM NOVO BANCO DE DADOS? 's' para sim: ");
			fflush(stdin);
			opcao = getchar();
			if(opcao == 's' || opcao == 'S'){
				arq = fopen("dados_funcionarios.bin", "wb");
				deletarFuncionario(funcionario, contador_entradas, "MENU");

			}else{
				puts("DESEJA RESTAURAR O ULTIMO BACKUP?");
				puts("'s' para sim: ");
				fflush(stdin);
				opcao = getchar();
				if(opcao == 's' || opcao == 'S'){
					deletarFuncionario(funcionario, contador_entradas, "RESTAURAR");
				}else{
					printf("\nENCERRANDO PROGRAMA!");
					sleep(5);
					exit(1);
				}
			}
		}
		fclose(arq);
		
		puts("1 - LISTAR TODOS");
		puts("2 - INSERIR CODIGO");
		puts("3 - RESTAURAR BACKUP");
		puts("0 - APAGAR TODOS");
		printf("OPCAO: ");
		fflush(stdin);
		opcao = getche();
		contadorTemp = 0;
		while((opcao > '3') || (isdigit(opcao) == 0)){
			contadorTemp++;
			if(contadorTemp > 2){	
				printf("\n\nINFORME UM NUMERO DE 0 a 2.");	
				puts("\n1 - LISTAR TODOS");	
				puts("2 - INSERIR CODIGO");
				puts("3 - RESTAURAR BACKUP");
				puts("0 - APAGAR TODOS");
				printf("OPCAO:");
			}else{
				printf("\nOPCAO INVALIDA: ");
			}		 
			fflush(stdin);
			opcao = getche();
		}

		if(opcao == '0'){
//			strcpy(tipo, "TODOS");
			deletarFuncionario(funcionario, contador_entradas, "TODOS");
		}
		if(opcao == '1'){
//			strcpy(tipo, "LISTAR");
			deletarFuncionario(funcionario, contador_entradas, "LISTAR");
		}
		if(opcao == '2'){
//			strcpy(tipo, "INSERIR");
			deletarFuncionario(funcionario, contador_entradas, "INSERIR");
		}
		if(opcao == '3'){
//			strcpy(tipo, "RESTAURAR");
			deletarFuncionario(funcionario, contador_entradas, "RESTAURAR");
		}
	}	//fim if menu

	    
	if(strcmp(tipo, "TODOS") == 0){	
	    char arquivo_anterior[32];
	    char arquivo_novo[32];
	    char arquivo_temp[32];
	    char s_indice[2];
	    int flag = 0;
			printf("\a\a\n's' PARA APAGAR OS DADOS DE TODOS OS FUNCIONARIOS:\n");
			fflush(stdin);
			continuar = getchar();

			if(continuar == 's' || continuar == 'S'){
			    strcpy(arquivo_anterior, "dados_funcionarios.bin");
			    strcpy(arquivo_novo, "BKP\\dados_funcionarios.bin");
				int resposta;
			    if((arq = fopen("dados_funcionarios.bin", "rb")) == NULL){
					puts("ERRO AO APAGAR O ARQUIVO, NENHUM BANCO DE DADOS ENCONTRADO!");
					sleep(5);
					exit(1);
				}else{
					fclose(arq);
					bkp = fopen("BKP\\dados_funcionarios.bin", "rb");						
					if(bkp != NULL){
						for(indice = 1; indice <= MAX_BKP; indice++){	
				   			strcpy(arquivo_temp, "BKP\\dados_funcionarios");
							itoa(indice, s_indice, 10);
							strcat(arquivo_temp, s_indice);
							strcat(arquivo_temp, ".bin");
							fclose(bkp);
							if((arq = fopen(arquivo_temp, "rb")) == NULL){
								break;
							}
							fclose(arq);
						}
						strcpy(arquivo_novo, arquivo_temp);
					}
				}
	
				
				resposta = rename(arquivo_anterior, arquivo_novo);
			    if(resposta == 0) {
			      printf("\nARQUIVO APAGADO COM SUCESSO.\n");
			    }else{
			       printf("\nNAO FOI POSSIVEL APAGAR O ARQUIVO\n");
			    }	
			}
		}	//fim if pagar
	if(strcmp(tipo, "LISTAR") == 0){
		listarFuncionarios(funcionario, contador_entradas);
	}	//fim if listar
	
	if(strcmp(tipo, "INSERIR") == 0){	
		puts("\nPOSSUI O CODIGO DO FUNCIONARIO?");
		printf("'s' para sim: ");
		fflush(stdin);
		continuar = getchar();
		contador_entradas = contarEntradas(funcionario);	//atualizar funcionario e contador
		if(continuar != 's' && continuar != 'S'){
			listarFuncionarios(funcionario, contador_entradas);
		}
		
		puts("\nINFORME O CODIGO DO FUNCIONARIO:");
		scanf("%u", &cod);
		
		controle_erros = 0;
		for(indice = 0; indice < contador_entradas; indice++){
			if(funcionario[indice].codigo == cod){
				posicao = indice;
				controle_erros++;
			}
		}
		if(controle_erros == 0){
			puts("\nNENHUM FUNCIONARIO ENCONTRADO!");
		}else{
			
			
			printf("\nCodigo : %03u ", funcionario[posicao].codigo);
			printf("\nNome   : %s",funcionario[posicao].nome);
			printf("\nIdade  : %d",funcionario[posicao].idade);
			if(funcionario[posicao].sexo == 'f'){
				printf("\nSexo   : feminino");
			}else if(funcionario[posicao].sexo == 'm'){
				printf("\nSexo   : masculino");
			}else{
				printf("\nSexo   : indefinido");
			}
			printf("\nCargo  : %s",funcionario[posicao].cargo);
			printf("\nSALARIO: R$ %10.2f",funcionario[posicao].salario);
			printf("\n");
			
			
			
			
			puts("DESEJA APAGAR DADOS DESSE FUNCIONARIO?");
			fflush(stdin);
			continuar = getchar();
			if(continuar == 's' || continuar == 'S'){				
				
				for(indice = posicao; indice < (contador_entradas - 1); indice++){
					funcionario[indice] = funcionario[indice + 1];
				}
							
				arq = fopen("dados_funcionarios.bin", "wb");
				if(arq == NULL){
					printf("\a\a\nFALHA AO DELETAR! NÂO FOI POSSIVEL ACESSAR O BANCO DE DADOS.");
					sleep(5);
					exit(1);
				}			
				fwrite(funcionario, sizeof(struct dados_pessoais), (contador_entradas - 1), arq);
				fclose(arq);
				puts("CADASTRO APAGADO COM SUCESSO!");
				struct dados_pessoais funcionario_temp[contador_entradas];
				for(indice = posicao; indice < (contador_entradas - 1); indice++){
					funcionario_temp[indice] = funcionario[indice];
				}
			}
			
		}
	}	//fim if inserir
			
	if(strcmp(tipo, "RESTAURAR") == 0){
	    char arquivo_anterior[32];
	    char arquivo_novo[32];
	    char arquivo_temp[32];
	    char s_indice[2];
	    int flag = 0;
	    
		printf("\a\a\n's' PARA RESTAURAR O BACKUP MAIS RECENTE: ");
		fflush(stdin);
		continuar = getchar();

		if(continuar == 's' || continuar == 'S'){
		    strcpy(arquivo_anterior, "BKP\\dados_funcionarios.bin");
		    strcpy(arquivo_novo, "dados_funcionarios.bin");
			int resposta;
		    if((arq = fopen("BKP\\dados_funcionarios.bin", "rb")) == NULL){
		    	flag = 0;
		    	for(indice = 1; indice <= MAX_BKP; indice++){
					strcpy(arquivo_temp, "BKP\\dados_funcionarios");
					itoa(indice, s_indice, 10);
					strcat(arquivo_temp, s_indice);
					strcat(arquivo_temp, ".bin");
					if((arq = fopen(arquivo_temp, "rb")) != NULL){
						fclose(arq);
						flag = 1;
						strcpy(arquivo_anterior, arquivo_temp);
					}
				}
		    	
		    	
		    	if(flag == 0){
				
					puts("ERRO AO RESTAURAR O ARQUIVO, NENHUM BACKUP ENCONTRADO!");
					sleep(5);
					exit(1);
				}
			}else{
				fclose(arq);
				flag = 0;
		    	for(indice = 1; indice <= MAX_BKP; indice++){
					strcpy(arquivo_temp, "BKP\\dados_funcionarios");
					itoa(indice, s_indice, 10);
					strcat(arquivo_temp, s_indice);
					strcat(arquivo_temp, ".bin");
					if((arq = fopen(arquivo_temp, "rb")) != NULL){
						fclose(arq);
						flag = 1;
						strcpy(arquivo_anterior, arquivo_temp);	
					}
				}
				
				if(flag == 0){						
					strcpy(arquivo_anterior, "BKP\\dados_funcionarios.bin");
				}
		    		
			}
			arq = fopen("dados_funcionarios.bin", "rb");
			if(arq != NULL){
				puts("JA EXISTE UM BANCO DE DADOS, DESEJA SUBSTITUIR?('s' para sim) ");
				fflush(stdin);
				continuar = getchar();
				fclose(arq);
				if(continuar != 's' && continuar != 'S'){
					deletarFuncionario(funcionario, contador_entradas, "MENU");
				}
			}
			remove(arquivo_novo);
			fclose(arq);
			
			resposta = rename(arquivo_anterior, arquivo_novo);
		    if(resposta == 0) {
		      printf("\nARQUIVO RESTAURADO COM SUCESSO.\n");
			  contarEntradas(funcionario);			      
		    }else{
		       printf("\nNAO FOI POSSIVEL RESTAURAR O ARQUIVO\n");
		    }	
		}
	}	// fim if restaurar
	

	contador_entradas = contarEntradas(funcionario);
	return contador_entradas;
}


