#include<stdio.h> 
#include<stdlib.h>

int lerValidarIdade();
char lerValidarSexo();
char lerValidarLocal();
void visaoFinal(char sexo[], char local[], int idade[], int contadorPessoas);
void apresentarResultado(char sexo[], char local[], int idade[], int contadorPessoas);

int main(void){
	const int maxPessoas = 500;
	char sexo[maxPessoas], local[maxPessoas];	
	int idade[maxPessoas], contadorPessoas = 0;

	printf("   PESQUISA SOBRE");
	printf("\n(sexo 'n' para encerrar)\n");
	
	do{
		printf("\n%3i%c PESSOA", contadorPessoas + 1, 166);
		sexo[contadorPessoas] = lerValidarSexo();	
		if(sexo[contadorPessoas] == 'n'){
			break; 			
		}		
		idade[contadorPessoas] = lerValidarIdade();	
		local[contadorPessoas] = lerValidarLocal();		
		contadorPessoas++;		
	}while(contadorPessoas < maxPessoas);

	apresentarResultado(sexo, local, idade, contadorPessoas);
	visaoFinal(sexo, local, idade, contadorPessoas);
	
	getch();
	return 0;
}

char lerValidarSexo(){
	char sexo;
	int cont = 0;
	
	printf("\nInforme o sexo: ");
	fflush(stdin);
	sexo = getchar();
	sexo = tolower(sexo);
		
	while((sexo != 'f') && (sexo != 'm') && (sexo != 'n')){
		if(cont > 1){
			printf("\nSexo invalido, informe 'f' para feminino ou 'm' para masculino.");
		}else{
			printf("\nSexo invalido.");
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
			
	printf("Idade: ");
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
	int indice, contMenores = 0;
	float mediaIdade = 0;
	
	for(indice = 0; indice < contadorPessoas; indice++){
		mediaIdade = mediaIdade + idade[indice];
	}
	
	mediaIdade = mediaIdade / contadorPessoas;
	
	system("CLS");
	printf("RESULTADO DA PESQUISA\n");
	if(mediaIdade == 1){
		printf("\n\nRelacao de entrevistados abaixo da media de idade: %.2f ano.\n", mediaIdade);
	}else{
		printf("\n\nRelacao de entrevistados abaixo da media de idade: %.2f anos.\n", mediaIdade);
	}		
	printf("\n SEXO  IDADE    ULTIMA VIAGEM");
	for(indice = 0; indice < contadorPessoas; indice++){
		if(idade[indice] < mediaIdade){
			contMenores++;
			printf("\n   %-3c   %-4i ", sexo[indice], idade[indice]);
			if(local[indice] == 'E'){				
				printf("%-18s ", " EUROPA ");
			}		
			if(local[indice] == 'S'){				
				printf("%-18s ", " ASIA ");
			}		
			if(local[indice] == 'A'){				
				printf("%-18s ", " AMERICA DO NORTE ");
			}		
			if(local[indice] == 'N'){				
				printf("%-18s ", " NUNCA SAIU DO PAIS");
			}
		}			
	}
	if(contMenores == 0){
		if(mediaIdade <= 1){
			printf("\n\nNao ha entrevistados abaixo de %.2f ano.", mediaIdade);
		}else{
			printf("\n\nNao ha entrevistados abaixo de %.2f anos.", mediaIdade);
		}		
	}
}

void visaoFinal(char sexo[], char local[], int idade[], int contadorPessoas){
	int indice, E = 0, S = 0, A = 0, N = 0;

	printf("\n\nRelacao dos paises visitados");
	for(indice = 0; indice < contadorPessoas; indice++){
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
