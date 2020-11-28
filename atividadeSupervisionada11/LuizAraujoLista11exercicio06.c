#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_FUNC 100
float calcularMaiorSalario(float maiorSalario, float salario);
float calcularMenorSalario(float menorSalario, float salario);
void validarMatricula(int *matricula, int contadorFuncionario);
int main(void){
	int contadorFuncionario = 0, contador;
	int matricula[MAX_FUNC];
	float salario[MAX_FUNC], maiorSalario, menorSalario;

//	zerar tudo
	for(contador = 0; contador < MAX_FUNC; contador++){		
		matricula[contador] = 0; 
		salario[contador] = 0;	
	}
	contador = 0;
	contadorFuncionario = 0;
	
	printf("   SALARIO DOS FUNCIONARIOS\n");
	printf("(matricula negativa para finalizar)\n");
	do{
		printf("\n%i%c FUNCIONARIO ", (contadorFuncionario + 1), 167);
		printf("\nMATRICULA: ");
		scanf("%i", &matricula[contadorFuncionario]);
		if(matricula[contadorFuncionario] <= -1){
			break;
		}				
		validarMatricula(matricula, contadorFuncionario);	
		printf("SALARIO: ");
		scanf("%f", &salario[contadorFuncionario]);	
		contadorFuncionario++;	
	}while(contadorFuncionario < MAX_FUNC);	
	if(contadorFuncionario == 0){
		printf("SEM FUNCIONARIOS!");
	}else{
		system("CLS");	
		printf("%-30s \n", "LISTA DE FUNCIONARIOS");	
		printf("\n");
		printf("%-11s%-18s\n", "MATRICULAS", "SALARIOS");
		for(contador = 0; contador < contadorFuncionario; contador++){ 
			if(contador == 0){
				maiorSalario = salario[0];
				menorSalario = salario[0];
			}
			printf("%010d R$ %-15.2f\n", matricula[contador], salario[contador]);			
			maiorSalario = calcularMaiorSalario(maiorSalario, salario[contador]);
			menorSalario = calcularMenorSalario(menorSalario, salario[contador]);
		}
		printf("\n");	
		printf("MAIOR SALARIO: R$ %-12.2f \n",maiorSalario);	
		printf("MENOR SALARIO: R$ %-12.2f \n",menorSalario);		
	}
	printf("\n\n\nPRESSIONE QUALQUER TECLA PARA ENCERRAR.\n");		
	getche();
	return 0;
}
void validarMatricula(int matricula[], int contadorFuncionario){
	int contador;
	for(contador = (contadorFuncionario - 1); contador >= 0; contador--){
		while(matricula[contador] == matricula[contadorFuncionario]){
			if(contador!=contadorFuncionario){				
				printf("MATRICULA JA CADASTRADA: ");
				scanf("%i", &matricula[contadorFuncionario]);	
			}		
		}			
	}
}
float calcularMaiorSalario(float maiorSalario, float salario){	
	if(maiorSalario < salario){
		 maiorSalario = salario;
	}	
	return maiorSalario;
}	
float calcularMenorSalario(float menorSalario, float salario){
	if(menorSalario > salario){
		 menorSalario = salario;
	}	
	return menorSalario;
}



