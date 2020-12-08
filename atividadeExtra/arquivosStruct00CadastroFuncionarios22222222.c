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
	char nome[50];
	int idade;
	char sexo;
	char cargo[30];
	float salario;
};

void testarEntradas(struct dados_pessoais funcionario);
void lerValidarNome(char nome[], char tudo[][50]);
int lerValidarIdade();
char lerValidarSexo();
void lerValidarCargo(char cargo[]);
float lerValidarSalario();
void gravarEntradas(struct dados_pessoais funcionario, FILE *arq);

int main(void){
	setlocale(LC_ALL, "Portuguese");	
	struct dados_pessoais funcionario[MAX_FUNC];
	int contadorFuncionario = 0, indice = 0, indice2 = 0, contadorEntradas = 0, contadorNome = 0;
	char continuar, tudo[MAX_FUNC * 5][50], nomeCmp[MAX_FUNC][50];
	printf("\a\a");
	//para pegar todos nomes do arquivo e por em vetor para cmp
	FILE *file = fopen("dados_funcionarios.txt", "r");
	if(file == NULL){
		printf("\nERRO AO ABRIR O ARQUIVO: dados_funcionarios.txt!");
		sleep(5);
		exit(0);
	}else{
		

		indice = 0;
	//	poe todo o arquivo em um vetor
		while(fgets(tudo[contadorEntradas], (MAX_FUNC * 5), file) != NULL){	
		
			
			contadorEntradas++;
		}
	//	poe só os nomes do arquivo em um vetor
		for(indice2= 0; indice2 < contadorEntradas; indice2++){
	//		printf("%i - %s", indice2, tudo[indice2]);//mostra tudo
			if(indice2 % 5 == 0){
	//			printf("\n\nindice2: %i -> %s\n\n\n", indice2, tudo[indice2]);//mostra só os nome do vetor tudo[]
				strcpy(nomeCmp[contadorNome], tudo[indice2]);
				
				//passar pra struct
				strcpy(funcionario[contadorNome].nome, tudo[indice2]);
				funcionario[contadorNome].idade = atoi(tudo[indice2+1]);
				funcionario[contadorNome].sexo = (char)tudo[indice2+2][0];
				strcpy(funcionario[contadorNome].cargo, tudo[indice2+3]);
				funcionario[contadorNome].salario = atof(tudo[indice2+4]);
				contadorNome++;	
			}
		}
		for(indice2 = 0; indice2 < contadorNome; indice2++){//mostra todos os func
			printf("%2i - %s", indice2, nomeCmp[indice2]);
		}
	}//fim else fopen "r"
	
	FILE *arq = fopen("dados_funcionarios.txt", "a");
	if(arq == NULL){
		printf("\nERRO AO ABRIR O ARQUIVO: dados_funcionarios.txt!");
		sleep(5);
		exit(0);
	}else{
		

		puts("CADASTRO DE FUNCIONÁRIOS");	
		
		puts("TEEEESSSSSTTTTTEEEE SSSSTTTRUUUCCTT:");
	
		puts("\n\n\n\n\tNOME\t\tIDADE\tSEXO\tCARGO\t\tSALARIO:");
		for(indice = 0; indice < (contadorEntradas/5); indice++){
			printf("%iº: %s %i %c %s %.2f\n", indice, funcionario[indice].nome, funcionario[indice].idade, funcionario[indice].sexo, funcionario[indice].cargo, funcionario[indice].salario);
		}
		puts("\n\n\n\n");
		
		
		do{
			printf("\n%dº FUNCIONÁRIO", contadorFuncionario + 1);		
			lerValidarNome(funcionario[contadorFuncionario].nome, tudo);
			funcionario[contadorFuncionario].idade = lerValidarIdade();
			funcionario[contadorFuncionario].sexo = lerValidarSexo();
			lerValidarCargo(funcionario[contadorFuncionario].cargo);
			funcionario[contadorFuncionario].salario = lerValidarSalario();
			
			printf("Novo cadastro? (s para continuar) ");
			fflush(stdin);
			continuar = getchar();
	
			gravarEntradas(funcionario[contadorFuncionario], arq);
	//		int total_gravado = 0;
	//		total_gravado = fwrite(funcionario, sizeof(struct dados_pessoais), 1, arq);
	//		if(total_gravado != 1){
	//			puts("ERRO AO SALVAR NO ARQUIVO!");
	//			sleep(5);
	//			exit(0);
	//		}
	
			if(continuar != 's' && continuar != 'S'){
				break;
			}
	//		testarEntradas(funcionario[contadorFuncionario]);
			contadorFuncionario++;
		}while(contadorFuncionario < MAX_FUNC);
	}//fim else fopen "a"
	fclose(arq);
	fclose(file);
	
	printf("\n\n\nPRESSIONE QUALQUER TECLA PARA ENCERRAR.\n");
	getch();
	return 0;
}

void lerValidarNome(char nome[], char tudo[][50]){
	do{
		puts("\nNOME COMPLETO:");
		fflush(stdin);
		gets(nome);
		if((strlen(nome) <= 5)){
			puts("informe um nome válido!");
		}
	}while((strlen(nome) <= 5));
	
	
	
	
	
	

	
	
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









