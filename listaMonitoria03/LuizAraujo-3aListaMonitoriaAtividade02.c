/*
Name: Luiz Araujo
Description: 
*/

#include<stdio.h> 
#include<stdlib.h>

char lerValidarSexo();
int lerValidarIdade();
char lerValidarLocal();
void apresentarResultado(char sexo[], char local[], int idade[], int contadorPessoas);
void visaoFinal(char sexo[], char local[], int idade[], int contadorPessoas);

int main(void){
	int maxPessoas = 500;
	char sexo[maxPessoas], local[maxPessoas];
	int idade[maxPessoas], contadorPessoas = 0;

		printf("PESQUISA SOBRE");
		printf("\n (sexo n para encerrar)\n");
	do{
		printf("\n%3i%c PESSOA", contadorPessoas + 1, 166);
		sexo[contadorPessoas] = lerValidarSexo();	
		if(sexo[contadorPessoas] == 'n'){ //aqui pára o loop, não pode ser na função porque o loop é fora da função;
			break; 			
		}		
		local[contadorPessoas] = lerValidarLocal();	
		idade[contadorPessoas] = lerValidarIdade();				
		
	//	printf("\n Idade: %i", idade[contadorPessoas]);
//		printf("\n Local: %c", local[contadorPessoas]);
//		printf("\nSEXO: %c\n", sexo[contadorPessoas]);	// sempre deixo comentarios pra testar as paradas, aí qndo pronto eu "limpo" o código

		contadorPessoas++;		
	}while(contadorPessoas < maxPessoas); //se eu não parar antes vai até 499

	apresentarResultado(sexo, local, idade, contadorPessoas);
	visaoFinal(sexo, local, idade, contadorPessoas);
	
//	getch();
	return 0;
}

char lerValidarSexo(){
	char sexo;
	int cont = 0;
	printf("\nInforme o sexo: ");
	fflush(stdin);
	sexo = getchar();	//descobri, estava pulando o input porque tinha "lixo" de outra entrada, por isso repetia. Tive que por fflush(stdin); em tudo...
	sexo = tolower(sexo);
	
	while((sexo != 'f') && (sexo != 'm') && (sexo != 'n')){
		if(cont > 1){
			printf("\nSexo Invalido, informe 'f' para feminino ou 'm' para masculino.");
		}else{
			printf("\nSexo Invalido.");
		}
		
		
		
		printf("\nInforme o sexo: ");
		fflush(stdin);
		sexo = getchar();
		sexo = tolower(sexo);
		
		cont++;
	}
	return sexo;
}

int lerValidarIdade(){
	int idade, cont = 0;
			
	printf("idade: ");
	fflush(stdin);
	scanf("%i", &idade);
	
	while(idade <= 0 || idade > 130){
		if(cont > 1){
			printf("\nIdade invalida, informe algo entre 1 e 130(Matusalem):");
		}else{
			printf("\nIdade invalida: ");
		}
		fflush(stdin);
		scanf("%i", &idade);
		
		cont++;
	}
			
	return idade;

}

char lerValidarLocal(){
	char local;
	int cont = 0;
	
	puts("\nUltima viagem fora do pais dentre os seguintes continentes: ");
	puts("E - Europa");
	puts("S - Asia");
	puts("A - America do Norte");
	puts("N - quem nunca saiu do pais");
	fflush(stdin);
	local = getchar(); 
	local = toupper(local);		
	
	while((local) != 'E' && (local != 'S') && (local != 'A') && (local != 'N')){
		if(cont > 1){
			puts("\n\nEntrada invalida, informe: ");
			puts("Ultima viagem fora do pais dentre os seguintes continentes: ");
			puts("E - Europa");
			puts("S - Asia");
			puts("A - America do Norte");
			puts("N - quem nunca saiu do pais");
		}else{
			puts("\nEntrada invalida: ");
		}
		
		fflush(stdin);
		local = getchar();
		local = toupper(local);
		cont++;	//contador pra quando errar muito, mudar a msg
	}
	return local;
}	//aqui fim da função

void apresentarResultado(char sexo[], char local[], int idade[], int contadorPessoas){
	int indice;
	float mediaIdade = 0;
	
	for(indice = 0; indice < contadorPessoas; indice++){	//percorre todo o o vetor
		mediaIdade = mediaIdade + idade[indice];
	}
	
	mediaIdade = mediaIdade / contadorPessoas;
	
	
	//fazer a tabela
	system("CLS");
	printf("RESULTADO DA PESQUISA\n");
	printf("\nRelacao de entrevistados abaixo da media de idade(%.2f):", mediaIdade);
	printf("\n SEXO  IDADE  ULTIMA VIAGEM");
	for(indice = 0; indice < contadorPessoas; indice++){	//percorre todo o o vetor
		if(idade[indice] < mediaIdade){
			printf("\n|  %-3c|  %-4i|     %-9c|", sexo[indice], idade[indice], local[indice]);
		}			
	}
}

void visaoFinal(char sexo[], char local[], int idade[], int contadorPessoas){
	int indice, E = 0, S = 0, A = 0, N = 0;

	printf("\n\nRelacao dos paises visitados");
	for(indice = 0; indice < contadorPessoas; indice++){	//percorre todo o o vetor
		if(local[indice] == 'E'){
			E++;
		}			
		if(local[indice] == 'S'){
			S++;
		}			
		if(local[indice] == 'A'){
			A++;
		}			
		if(local[indice] == 'N'){
			N++;
		}			
	}
	printf("\nEUROPA    : %i", E);
	printf("\nASIA      : %i", S);
	printf("\nAMERICA N.: %i", A);
	printf("\nNUNCA     : %i", N);
}
