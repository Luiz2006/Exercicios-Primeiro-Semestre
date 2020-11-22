/*
Tem-se um conjunto de dados contendo a altura e o sexo (masculino, feminino) de at� 10 pessoas. 
Fazer um programa que calcule e escreva: a maior e a menor altura do grupo; a m�dia da altura das mulheres; o n�mero de homens. 
Usar os tr�s comandos de repeti��o na solu��o do problema.
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
		printf("%i� Pessoa:\n", contador);	
		do{			
			printf("Sexo [f/m]: ");
			sexo = getche();
			sexo = tolower(sexo);
			if((sexo != 'm') && (sexo != 'f')){
				printf("\nSexo inv�lido! Informe novamente.\n");
			}
		}while((sexo != 'm') && (sexo != 'f'));
		
		printf("\nAltura [com v�rgula]: ");
		scanf("%f", &altura);
		
		while((altura <= 0) || (altura >= 2.3)){
			if((altura <= 0) || (altura >= 2.3)){
				printf("Altura inv�lida! Informe novamente.\n");
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
	printf("\nA m�dia das alturas femininas: %.2fm", mediaMulheres/mulheres);
	printf("\nO n�mero de homens: %i.", homens);
}
