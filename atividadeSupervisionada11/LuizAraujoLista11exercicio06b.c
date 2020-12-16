/*
Name: Luiz Araujo
Description: Fazer um algoritmo/programa que leia a matricula e o salário dos funcionários de uma empresa (máximo de 100 funcionários). 
Após a leitura de todos os dados, informe em uma tela limpa os dados lidos e o maior e menor salário dos funcionários. 
O maior e menor salário deverão ser obtidos, cada um, por uma função. Sabe-se ainda que não existe matrícula repetida na empresa.
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_FUNC 5 //padrão: 100

float calcularMaiorSalario(float maiorSalario, float salario);
float calcularMenorSalario(float menorSalario, float salario);
void validarMatricula(int *matricula, int contadorFuncionario);

int main(void){
	int contadorFuncionario = 0, contador;
	int matricula[MAX_FUNC];
	float salario[MAX_FUNC], maiorSalario, menorSalario;
	

	for(contador = 0; contador < contadorFuncionario; contador++){		
		matricula[contador] = 0; 
		salario[contador] = 0;	
	}
	printf("   SALARIO DOS FUNCIONARIOS\n");
	printf("(numero negativo para finalizar)\n");
	
	while((matricula[contadorFuncionario] >= 0) && (salario[contadorFuncionario] >= 0) && (contadorFuncionario <= MAX_FUNC)){	
			printf("\n%i%c FUNCIONARIO ", (contadorFuncionario + 1), 167);
			printf("\nMATRICULA: ");
			scanf("%i", &matricula[contadorFuncionario]);
			validarMatricula(&matricula, contadorFuncionario);
			
	//		for(contador = (contadorFuncionario - 1); contador >= 0; contador--){
	//			while(matricula[contador] == matricula[contadorFuncionario]){
	//				printf("MATRICULA JA CADASTRADA: ");
	//				scanf("%i", &matricula[contadorFuncionario]);	
	//				for(contador = (contadorFuncionario - 1); contador >= 0; contador--){
	//					while(matricula[contador] == matricula[contadorFuncionario]){
	//						printf("MATRICULA JA CADASTRADA: ");
	//						scanf("%i", &matricula[contadorFuncionario]);					
	//					}			
	//				}				
	//			}			
	//		}
			
			printf("SALARIO: ");
			scanf("%f", &salario[contadorFuncionario]);
	
			contadorFuncionario++;
		
	}	//fim while
	
	
	
//	contadorFuncionario = MAX_FUNC; // para testar quadro
//	for(contador = 0; contador < contadorFuncionario; contador++){		
//		matricula[contador] = 0; 
//		salario[contador] = 0;	
//	}
	
	system("CLS");	
	printf("%-30s \n", "LISTA DE FUNCIONARIOS");	
	printf("\n");
	printf("%-13s%-18s\n", "MATRICULA", "SALARIO");
	for(contador = 0; contador < contadorFuncionario; contador++){ 
		if(contador == 0){
			maiorSalario = salario[0];
			menorSalario = salario[0];
		}
		printf("%-12i R$ %-15.2f\n", matricula[contador], salario[contador]);	
						
		maiorSalario = calcularMaiorSalario(maiorSalario, salario[contador]);
		menorSalario = calcularMenorSalario(menorSalario, salario[contador]);			
		
	}	//fim for
	
	printf("\n");
	printf("MAIOR SALARIO: R$ %-12.2f \n",maiorSalario);	
	printf("MENOR SALARIO: R$ %-12.2f \n",menorSalario);	
		
	
	return 0;
}	//fim main




void validarMatricula(int *matricula, int contadorFuncionario){
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



