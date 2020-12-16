#include<stdio.h>
main(){	
	int voto = 0, pele = 0, maradona = 0, branco = 0, nulo = 0;
	char confirmar, continuar;
	
	printf("QUAL O MELHOR JOGADOR DE TODOS OS TEMPOS");		
	do{
		printf("\n");		
		printf("\n  OPCOES DE VOTO");
		printf("\n 25 - PEL\x90");
		printf("\n 33 - MARADONA");
		printf("\n 00 - BRANCO");
		printf("\n OUTRO N%c ANULA\n", 167);
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
    printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n"); 
    printf("\xBA APURACAO DA VOTACAO       \xBA\n");
    printf("\xBA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBA\n"); 
    printf("\xBA PEL\x90: %-5i               \xBA\n", pele);
    printf("\xBA MARADONA: %-5i           \xBA\n", maradona);
    printf("\xBA BRANCOS: %-5i            \xBA\n", branco);
    printf("\xBA NULO: %-5i               \xBA\n", nulo);
    printf("\xBA                           \xBA\n");
    
	if((pele > maradona) && (pele > branco) && (pele > nulo)){
		printf("\xBA PEL\x90 \x82 o melhor do mundo! \xBA\n");
	}else{	
		if((maradona > pele) && (maradona > branco) && (maradona > nulo)){
			printf("\xBA MARADONA venceu!          \xBA\n");
		}else{	
			if((nulo > pele) && (nulo > branco) && (nulo > maradona)){
				printf("\xBA  Houve mais votos nulos!  \xBA\n");
			}else{	
				if((branco > pele) && (branco > nulo) && (branco > maradona)){
					printf("\xBAHouve mais votos em branco!\xBA\n");
				}else{						
					if(pele == maradona){
						printf("\xBA     Houve um empate!      \xBA\n");
					}					
				}	
				
			}	
			
		}		
	}    
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
	printf("\n\n\nPRESSIONE QUALQUER TECLA PARA ENCERRAR.\n");		
	getche();
}
