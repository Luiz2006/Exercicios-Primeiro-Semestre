/*
Name: Editar Cadastro Funcion�rios
Copyright: MIT License
Author: Luiz Araujo - luizcarlos_bsb2006@hotmail.com
Date: 13/12/20 14:31
Description: Manipula��o de Arquivos - edita cadastro de funcionarios.
*/

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
//	//alinhar depois
//	char nome[31];	//31bytes
//	char cargo[21];	//21bytes
//	float salario;	//4bytes
//	int idade;		//4bytes
//	char sexo;		//1bytes
//	char pad[3];	//s� pra alinhar
};

void lerValidarNome(int contador_entradas, struct dados_pessoais funcionario[]);
int lerValidarIdade();
char lerValidarSexo();
void lerValidarCargo(char cargo[]);
float lerValidarSalario();
int contarEntradas(struct dados_pessoais funcionario[]);
int editarFuncionario(struct dados_pessoais funcionario[], int contador_entradas);
void gravarEntrada(struct dados_pessoais *funcionario, FILE *arq);
void listarFuncionarios(struct dados_pessoais funcionario[], int contador_entradas);

int main(void){
	setlocale(LC_COLLATE, "Portuguese");
	setlocale(LC_MONETARY, "Portuguese");
	setlocale(LC_NUMERIC, "Portuguese");
	setlocale(LC_TIME, "Portuguese");	
	struct dados_pessoais funcionario[MAX_FUNC];
	int contador_funcionario = 0, indice = 0, indice2 = 0, contador_entradas = 0;
	char continuar;

//	p�e todas as entradas na struct
//	contador_entradas = (int)contarEntradas(funcionario);
//	
//	if(contador_entradas > 0){
//		listarFuncionarios(funcionario, contador_entradas);
//	}
//	
//	
//	editarrrrrrrrrrrrrrrrrrrr
//	contador_entradas = cadastrarFuncionarios(funcionario, contador_entradas);
	
//	contador_entradas = contarEntradas(funcionario);
	
	editarFuncionario(funcionario, contador_entradas);
	
//	listarFuncionarios(funcionario, contador_entradas);
	printf("\n\n\nPRESSIONE QUALQUER TECLA PARA ENCERRAR.\n");
	getch();
	return 0;
}


void listarFuncionarios(struct dados_pessoais funcionario[], int contador_entradas){	
	int indice;
	
//	contador_entradas = (int)contarEntradas(funcionario);
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
	printf("COD %-30s%-6s%-6s%-20s%-10s\n","NOME","IDADE","SEXO","CARGO","SALARIO(R$)");
	for(indice = 0; indice < contador_entradas; indice++){//mostra nome de todos os func

		printf("%03d ", indice);
//		printf("%03d ", indice + 1);
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

void gravarEntrada(struct dados_pessoais *funcionario, FILE *arq){	
	int indice, tamanho_struct = sizeof(struct dados_pessoais);
		fwrite(funcionario, sizeof(struct dados_pessoais), 1, arq);
}

int contarEntradas(struct dados_pessoais funcionario[]){
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

int editarFuncionario(struct dados_pessoais funcionario[], int contador_entradas){	
	FILE *arq;
	char continuar = 's', opcao;
	int resultado, cod, controle_erros, contadorTemp;
	struct dados_pessoais c[MAX_FUNC];
//	fseek retorna 0 caso sucesso

	do{	
		system("CLS");
		puts("EDITAR CADASTRO DE FUNCIONARIOS");
//		arq = fopen("dados_funcionarios.bin", "wb");
		arq = fopen("dados_funcionarios.bin", "rb");
		if(arq == NULL){
			printf("\a\nERRO AO ABRIR O ARQUIVO: dados_funcionarios.bin!");
			sleep(5);
			exit(1);
		}
		
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
	//		fseek(arq, cod * sizeof(struct dados_pessoais), SEEK_SET);
			
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
			
			
			/////////////////////Fazer v�rios IFs para alterar mais de uma coisa de uma vez
			contadorTemp = 0;
			while((opcao> '5')||(isdigit(opcao) == 0)){
				contadorTemp++;
					contadorTemp++;
					if(contadorTemp > 2){		
						printf("\n\nINFORME UM NUMERO DE 0 a 5.");		
						puts("\n1 - NOME");
						puts("2 - IDADE");
						puts("3 - SEXO");
						puts("4 - CARGO");
						puts("5 - SALARIO");
						puts("0 - CANCELAR");
						printf("ALTERAR:");
					}else{
						printf("\nOPCAO INVALIDA: ");
					}		 
					fflush(stdin);
					opcao = getche();
			}
			if(opcao != '0'){			
				switch(opcao){
					char texto_temp[31], sexo_temp;
					float salario_temp;
					int idade_temp;
					case '1':
						do{
							puts("\nNOME COMPLETO:");
							fflush(stdin);
							gets(texto_temp);
							if((strlen(texto_temp) <= 5)){
								puts("informe um nome v�lido!");
							}
							if((strlen(texto_temp) > 30)){
								puts("informe um nome menor!");
							}
						}while((strlen(texto_temp) <= 5) || (strlen(texto_temp) > 30));							
						printf("\nANTES : %s", c[cod].nome);
						printf("\nDEPOIS: %s", texto_temp);
						printf("\n's' PARA CONFIRMAR ALTERACAO: ");
						fflush(stdin);
						continuar = getchar();
						if(continuar == 's'|| continuar == 'S'){
							arq = fopen("dados_funcionarios.bin","w+b");//tive que passar todos pra dentro dos IFs, pois, �s vezes, qndo fechava o prg apagava o arquivo
							if(arq == NULL){
								printf("\a\a\a\nERRO AO SALVAR NO ARQUIVO: dados_funcionarios.bin!");
								sleep(5);
								exit(1);
							}else{
								strcpy(c[cod].nome, texto_temp);
								fwrite(&c, sizeof(struct dados_pessoais), contador_entradas, arq);
								printf("\a\nAlteracao realizada com sucesso!");
							}
							fclose(arq);
						}						
						break;
					case '2':			
						do{
							printf("\nIDADE:");
							scanf("%d", &idade_temp);
							if(idade_temp < 14){
								puts("Na CLT, a idade m�nima prevista � de 14 anos, desde que o menor seja contratado na condi��o de aprendiz.");
							}
							if(idade_temp > 120){
								puts("Informe uma idade v�lida, pois com mais de 120 anos � improv�vel que ainda esteja trabalhando.");
							}
						}while((idade_temp < 14) || (idade_temp > 120));						
						printf("\nANTES : %d", c[cod].idade);
						printf("\nDEPOIS: %d", idade_temp);
						printf("\n's' PARA CONFIRMAR ALTERACAO: ");
						fflush(stdin);
						continuar = getchar();
						if(continuar == 's'|| continuar == 'S'){
							arq = fopen("dados_funcionarios.bin","w+b");
							if(arq == NULL){
								printf("\a\a\a\nERRO AO SALVAR NO ARQUIVO: dados_funcionarios.bin!");
								sleep(5);
								exit(1);
							}else{
								c[cod].idade = idade_temp;
								fwrite(&c, sizeof(struct dados_pessoais), contador_entradas, arq);
								printf("\a\nAlteracao realizada com sucesso!");
							}
							fclose(arq);							
						}
						break;
					case '3':
						do{
							printf("\nSEXO: ");
							fflush(stdin);
							sexo_temp = getche();
							sexo_temp = tolower(sexo_temp);
							if(sexo_temp != 'f' && sexo_temp != 'm' && sexo_temp != 'x'){
								puts("F para feminino | M para masculino | X para indefinido ");
							}		
						}while(sexo_temp != 'f' && sexo_temp != 'm' && sexo_temp != 'x');						
						printf("\nANTES : %c", c[cod].sexo);
						printf("\nDEPOIS: %c", sexo_temp);
						printf("\n's' PARA CONFIRMAR ALTERACAO: ");
						fflush(stdin);
						continuar = getchar();
						if(continuar == 's'|| continuar == 'S'){
							arq = fopen("dados_funcionarios.bin","w+b");
							if(arq == NULL){
								printf("\a\a\a\nERRO AO SALVAR NO ARQUIVO: dados_funcionarios.bin!");
								sleep(5);
								exit(1);
							}else{
								c[cod].sexo = sexo_temp;
								fwrite(&c, sizeof(struct dados_pessoais), contador_entradas, arq);
								printf("\a\nAlteracao realizada com sucesso!");
							}
							fclose(arq);
						}
						break;
					case '4':
						do{
							puts("\nCARGO:");
							fflush(stdin);
							gets(texto_temp);
							if(strlen(texto_temp) < 3){
								puts("Informe um cargo v�lido!");
							}
							if(strlen(texto_temp) > 20){
								puts("Informe um cargo menor que 20!");
							}
						}while((strlen(texto_temp) < 3)||(strlen(texto_temp) > 20));
						printf("\nANTES : %s", c[cod].cargo);
						printf("\nDEPOIS: %s", texto_temp);
						printf("\n's' PARA CONFIRMAR ALTERACAO: ");
						fflush(stdin);
						continuar = getchar();
						if(continuar == 's'|| continuar == 'S'){
							arq = fopen("dados_funcionarios.bin","w+b");
							if(arq == NULL){
								printf("\a\a\a\nERRO AO SALVAR NO ARQUIVO: dados_funcionarios.bin!");
								sleep(5);
								exit(1);
							}else{
								strcpy(c[cod].cargo, texto_temp);
								fwrite(&c, sizeof(struct dados_pessoais), contador_entradas, arq);
								printf("\a\nAlteracao realizada com sucesso!");
							}
							fclose(arq);
						}						
						break;
					case '5':					      
						do{  
							printf("\nSALARIO:\nR$ ");
							scanf("%f", &salario_temp);
						//		sal�rio m�nimoR$ 1.045,00 
							if(salario_temp < 400){
								puts("Informe um sal�rio v�lido, pois menos que R$ 400,00 nem jovem aprendiz recebe...");
							}    
						}while(salario_temp < 400);						
						printf("\nANTES : R$%.2f", c[cod].salario);
						printf("\nDEPOIS: R$%.2f", salario_temp);
						printf("\n's' PARA CONFIRMAR ALTERACAO: ");
						fflush(stdin);
						continuar = getchar();
						if(continuar == 's'|| continuar == 'S'){
							arq = fopen("dados_funcionarios.bin","w+b");
							if(arq == NULL){
								printf("\a\a\a\nERRO AO SALVAR NO ARQUIVO: dados_funcionarios.bin!");
								sleep(5);
								exit(1);
							}else{
								c[cod].salario = salario_temp;
								fwrite(&c, sizeof(struct dados_pessoais), contador_entradas, arq);
								printf("\a\nAlteracao realizada com sucesso!");
							}
							fclose(arq);
						}
						break;		
				}//fim switch
					
//				fseek(arq, cod * sizeof(struct dados_pessoais), SEEK_SET);
//				fwrite(&c, sizeof(struct dados_pessoais), contador_entradas, arq);
			}//fim if != '0'

//			fclose(arq);
			printf("\nEditar o mesmo funcionario? (s para sim)");
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