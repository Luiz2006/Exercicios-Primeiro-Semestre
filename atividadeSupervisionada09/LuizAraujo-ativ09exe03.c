#include<stdio.h>
#include<locale.h>
main(){
	setlocale(LC_ALL, "Portuguese");
	float altura, maiorAltura, menorAltura, mediaMulheres;
	char sexo, continuar = 's';
	int contador, homens, mulheres;
	
	homens = 0;
	mulheres = 0;
	maiorAltura = 0;
	menorAltura = 32000;
	
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
		
		while((altura <= 0) || (altura >= 2.5)){
			if((altura <= 0) || (altura >= 2.5)){
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
		printf("Novos dados?[s - para sim]");
		continuar = getche();
		continuar = tolower(continuar);
		printf("\n\n");
		if(continuar != 's'){
			break;
		}
		
	}
	
	printf("\nMaior altura: %.2fm", maiorAltura);
	printf("\nMenor altura: %.2fm", menorAltura);
	printf("\nMédia das alturas femininas: %.2fm", mediaMulheres/mulheres);
	printf("\nNúmero de homens: %i", homens);
	
	printf("\n\n\nPRESSIONE QUALQUER TECLA PARA ENCERRAR.\n");
	getche();
}
