/*
Name: Luiz Araujo
Description: programa que efetua os c�lculos relacionados a avalia��o final de uma disciplina, 
		onde o c�lculo da m�dia dever� ser realizado por uma fun��o denominada MEDIA.
*/

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
//#include <time.h> //para testar automaticamente
	
float MEDIA(float A1, float A2, float A3, float AS);
float calcularFrequencia(float aulas, float faltas);
void validarNota(float *nota);
void validarFrequencia(float *aula, float total);
void mensagemResultado(float media, float A1, float A2, float A3, float frequencia);
//float notaAleatoria(); //para testar automaticamente

int main(void){
	
//srand(time(NULL)); //para testar automaticamente
//float r = rand(); //para testar automaticamente

	setlocale(LC_ALL, "Portuguese");
//declara��es
	float media, avaliacao1, avaliacao2, avaliacao3, atividades, frequencia, aulas, faltas;
//instru��es
	printf("AVALIA��O ALGORITMOS DE PROGRAMA��O");
	printf("\n\tSEMESTRE/ANO: 2/2020");
	
	printf("\n\n\n\tINFORME AS NOTAS ");
	
	printf("\n1� Atividade Avaliativa   : ");
	scanf("%f", &avaliacao1);	 //comentar para testar automaticamente
	validarNota(&avaliacao1);	 //comentar para testar automaticamente
//	avaliacao1 = notaAleatoria(); printf("%.1f\n", avaliacao1);//para testar automaticamente
	printf("2� Atividade Avaliativa   : ");
	scanf("%f", &avaliacao2);	 //comentar para testar automaticamente
	validarNota(&avaliacao2);	 //comentar para testar automaticamente
//	avaliacao2 = notaAleatoria(); printf("%.1f\n", avaliacao2);//para testar automaticamente
	printf("3� Atividade Avaliativa   : ");
	scanf("%f", &avaliacao3);	 //comentar para testar automaticamente
	validarNota(&avaliacao3);	 //comentar para testar automaticamente
//	avaliacao3 = notaAleatoria(); printf("%.1f\n", avaliacao3);//para testar automaticamente
	
	printf("Atividades Supervisionadas: ");
	scanf("%f", &atividades);	 //comentar para testar automaticamente
	validarNota(&atividades);	 //comentar para testar automaticamente
//	atividades = notaAleatoria(); printf("%.1f\n", atividades);//para testar automaticamente
	
	
//averiguar frequ�ncia 
	printf("\n\n\tFREQU�NCIA ");	
	printf("\nQuantidade de aulas: ");
	scanf("%f", &aulas);				 //comentar para testar automaticamente
	validarFrequencia(&aulas, faltas);	 //comentar para testar automaticamente
//	aulas = 10; printf("%.0f\n", aulas);//para testar automaticamente
	
	printf("Quantidade de faltas: ");
	scanf("%f", &faltas);				//comentar para testar automaticamente
	validarFrequencia(&faltas, aulas);	//comentar para testar automaticamente
//	faltas = notaAleatoria(); printf("%.0f\n", faltas);//para testar automaticamente
	
	
	media = MEDIA(avaliacao1, avaliacao2, avaliacao3, atividades);
	frequencia = calcularFrequencia(aulas, faltas);
	
//resultado
	printf("\n\n\tRESULTADO ");	
	printf("\nM�DIA FINAL   : %.2f.", media);
	printf("\nAPROVEITAMENTO: %.2f%%.", ((media*1000)/100));
	printf("\nFREQU�NCIA: %.2f %%.", frequencia);
	mensagemResultado(media, avaliacao1, avaliacao2, avaliacao3, frequencia);

	return 0;
}

float MEDIA(float A1, float A2, float A3, float AS){
	float media;
	media = ((A1*0.20) + (A2*0.20) + (A3*0.30) + (AS*0.30));
	return media;
}

float calcularFrequencia(float aulas, float faltas){	
	float freq;
	if(faltas == 0){
		freq = 100;
	}else{
		freq = ((faltas*aulas));	
	}	
	return freq;
}

void validarNota(float *nota){
	while((*nota < 0)||(*nota > 10)){
		printf("Nota inv�lida, informe novamente: ");
		scanf("%f", *&nota);
	}
}

void validarFrequencia(float *aula, float total){ 	
	//aula recebe aulas ou faltas
	if(!total){							//se total for != 0 quer dizer que foi chamada na parte de faltas
		while(*aula <= 0){
			printf("Entrada inv�lida, informe novamente: ");
			scanf("%f", *&aula);
		}
	}else{		
		while((*aula <= 0) || (*aula > total)) { //�ltima parte da cond � para as faltas n�p ultrapassar as aulas
			printf("Entrada inv�lida, informe novamente: ");
			scanf("%f", *&aula);
		}
	}
}

void mensagemResultado(float media, float A1, float A2, float A3, float freq){	
	if((freq < 50)){ //padr�o: < 75
		if((media < 5)){ //padr�o: < 7
			printf("\n\nREPROVADO PELA NOTA E POR FALTA, QUE PENA!");
		}else{
			printf("\n\nREPROVADO POR FALTA, QUE PENA!");			
		}		
	}else{
		if(media >= 5){ //padr�o: < 7
			if(media >= 9){
				printf("\n\nAPROVADO COM LOUVOR, PARAB�NS!");
			}else{
				printf("\n\nAPROVADO, PARAB�NS!");
			}
		}else{
			printf("\n\nREPROVADO POR NOTA, QUE PENA!");
		}
		if(media < 5){ //padr�o: < 7		
			printf("\n\nObs.:Haver� uma avalia��o de recupera��o/substitui��o (AR) que ser� utilizada para substituir a nota da: ");
			if(A1 < 5){ //padr�o: < 7
				printf("\n 1� AVALIA��O");
			}
			if(A2 < 5){ //padr�o: < 7
				printf("\n 2� AVALIA��O");
			}
			if(A3 < 5){ //padr�o: < 7
				printf("\n 3� AVALIA��O");
			}			
			printf("\n\nATEN��O: As notas de atividades supervisionadas (AS) n�o poder�o ser substitu�das pela avalia��o de recupera��o.");			
		}	
	}
}

// para testar automaticamente
//float notaAleatoria(){
//	return (rand() % 9);
//}
