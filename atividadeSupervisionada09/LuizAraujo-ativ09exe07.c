/*
Escreva um programa que transforme o computador em uma urna eletrônica para eleição do melhor jogador de futebol de todos os tempos. 
O número 25 é do candidato Pelé e o 33 do candidato Maradona. Cada voto será efetivado pelo numero do candidato, 
permitindo-se ainda o voto 0 (em branco) e qualquer outro voto diferente dos especificados sera considerado nulo. 
O eleitor devera sempre ser consultado quanto a confirmacao do voto. Ao final da eleicao devera ser apresentado um relatorio contendo:
„h Quantidade de votos de cada candidato;
„h Quantidade de votos em branco e nulos;
„h Nome do candidato vencedor (prever possibilidade de empate).
*/
#include<stdio.h>
main(){	
	int voto, pele, maradona, branco, nulo;
	char confirmar, continuar;
	voto = 0;
	pele = 0;
	maradona = 0;
	branco = 0;
	nulo = 0;
	printf("QUAL O MELHOR JOGADOR DE TODOS OS TEMPOS");	
	
	do{
		printf("\n");
		
		printf("\nVOTE 25 PARA PEL\x90");
		printf("\nVOTE 33 PARA MARADONA");
		printf("\nVOTO: ");
		scanf("%i", &voto);
		
		switch(voto){
			case 25:
				printf("Pel\x82 \x82 o melhor jogador de futebol de todos os tempos?");
				printf("\n[s - para sim]: ");
				confirmar = getche();
				confirmar = tolower(confirmar);			
				if(confirmar == 's'){
					pele++; 
				}
				break;
			case 33:
				printf("Maradona \x82 o melhor jogador de futebol de todos os tempos?");
				printf("[s - para sim]: ");
				confirmar = getche();
				confirmar = tolower(confirmar);			
				if(confirmar == 's'){
					maradona++; 
				}
				break;
			case 0:
				printf("Deseja votar em branco?");
				printf("[s - para sim]: ");
				confirmar = getche();
				confirmar = tolower(confirmar);			
				if(confirmar == 's'){
					branco++; 
				}
				break;
			default:
				printf("Deseja anular o voto?");
				printf("[s - para sim]: ");
				confirmar = getche();
				confirmar = tolower(confirmar);			
				if(confirmar == 's'){
					nulo++; 
				}
				break;			
		}
		printf("\n\nNovo voto [s - para sim]?");
		continuar = getche();
		continuar = tolower(continuar);
	}while(continuar == 's');	
	
	system("CLS");
	
    printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n"); 
    printf("\xBA BALAN\x80O DA VOTA\x80\xc7O       \xBA\n");
    printf("\xBA PEL\x90: %-5i              \xBA\n", pele);
    printf("\xBA MARADONA: %-5i          \xBA\n", maradona);
    printf("\xBA BRANCOS: %-5i           \xBA\n", branco);
    printf("\xBA NULO: %-5i              \xBA\n", nulo);
    printf("\xBA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBA\n");
    
	if((pele > maradona) && (pele > branco) && (pele > nulo)){
		printf("\xBA PEL\x90 \x82 o melhor do mundo!\xBA\n");
	}else{	
		if((maradona > pele) && (maradona > branco) && (maradona > nulo)){
			printf("\xBA MARADONA venceu!         \xBA\n");
		}else{	
			if((nulo > pele) && (nulo > branco) && (nulo > maradona)){
				printf("\xBA Houve mais votos nulos!\xBA\n");
			}else{	
				if((branco > pele) && (branco > nulo) && (branco > maradona)){
					printf("\xBA Houve mais votos em branco!\xBA\n");
				}else{						
					if(pele == maradona){
						printf("\xBA Houve um empate!\xBA\n");
					}					
				}	
				
			}	
			
		}		
	}    
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
}
