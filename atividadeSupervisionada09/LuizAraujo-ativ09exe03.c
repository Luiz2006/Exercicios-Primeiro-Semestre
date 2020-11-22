/*
Tem-se um conjunto de dados contendo a altura e o sexo (masculino, feminino) de até 10 pessoas. 
Fazer um programa que calcule e escreva: a maior e a menor altura do grupo; a média da altura das mulheres; o número de homens. 
Usar os três comandos de repetição na solução do problema.
*/
#include<stdio.h>
#include<locale.h>
main(){
	setlocale(LC_ALL, "Portuguese");
	float altura, maiorAltura, menorAltura, mediaMulheres;
	char sexo;
	int contador, homens, mulheres;
	
	homens = 0;
	mulheres = 0;
	maiorAltura = 0;
	menorAltura = 3;
	
	for(contador = 1; contador <= 10; contador++){
		printf("%iº Pessoa:\n", contador);	
		do{			
			printf("Sexo [f/m]: ");
			sexo = getche();
			sexo = tolower(sexo);
			if((sexo != 'm') && (sexo != 'f')){
				printf("\nSexo inválido! Informe novamente.\n");
			}
		}while((sexo != 'm') && (sexo != 'f'));
		
		printf("\nAltura [com vírgula]: ");
		scanf("%f", &altura);
		
		while((altura <= 0) || (altura >= 2.3)){
			if((altura <= 0) || (altura >= 2.3)){
				printf("Altura inválida! Informe novamente.\n");
			}
			printf("\nAltura: ");
			scanf("%f", &altura);
		}
		
		if(sexo == 'm'){
			++homens;
		}else{
			++mulheres;
			mediaMulheres += altura;
		}
		
		//maior altura
		if(altura > maiorAltura){
			maiorAltura = altura;
		}
		
		//menor altura
		if(altura < menorAltura){
			menorAltura = altura;
		}
	}
	
	printf("\nA maior altura: %.2fm.", maiorAltura);
	printf("\nA menor altura: %.2fm.", menorAltura);
	printf("\nA média das alturas femininas: %.2fm", mediaMulheres/mulheres);
	printf("\nO número de homens: %i.", homens);
}
