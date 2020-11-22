#include<stdio.h>
#include<conio.h>
#include<conio.c>

main(){
	int menu;

	printf("\n\n\n\n\n\n\n\n\n\n");
	
	printf("\t\t\t\t\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
	printf("\t\t\t\t\xBA                                                \xBA\n");
	printf("\t\t\t\t\xBA                                                \xBA\n");
	printf("\t\t\t\t\xBA                                                \xBA\n");
	printf("\t\t\t\t\xBA  QUAL REGI\xc7O DO BRASIL GOSTARIA DE CONHECER?   \xBA\n");
	printf("\t\t\t\t\xBA                                                \xBA\n");
	printf("\t\t\t\t\xBA                                                \xBA\n");
	printf("\t\t\t\t\xBA                                                \xBA\n");
	printf("\t\t\t\t\xBA                                                \xBA\n");
	printf("\t\t\t\t\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
	
	system("PAUSE");
	system("CLS");
	
	printf("\n\n\n\n\n\n\n\n\n\n");
	
	printf("\t\t\t\t\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
	printf("\t\t\t\t\xBA Menu de Op%c%ces                                 \xBA\n", 135, 228);
	printf("\t\t\t\t\xBA ============================================== \xBA\n");
	printf("\t\t\t\t\xBA 1 - Norte                                      \xBA\n");
	printf("\t\t\t\t\xBA 2 - Nordeste                                   \xBA\n");
	printf("\t\t\t\t\xBA 3 - Centro-Oeste                               \xBA\n");
	printf("\t\t\t\t\xBA 4 - Sudeste                                    \xBA\n");
	printf("\t\t\t\t\xBA 5 - Sul                                        \xBA\n");
	printf("\t\t\t\t\xBA 0 - Sair do programa                           \xBA\n");
	printf("\t\t\t\t\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
 
	printf("\t\t\t\tQual regi\xc6o gostaria de conhecer? ");
	scanf("%i", &menu);
	
	
	while((menu < 0) && (menu > 5)){
		printf("\t\t\t\tQual regi\xc6o gostaria de conhecer? ");
		scanf("%i", &menu);
	}
	
		system("CLS");
		
		printf("\n\n\n\n\n\n\n\n\n\n");
		
		printf("\t\t\t\t\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
		printf("\t\t\t\t\xBA                                                \xBA\n");
		printf("\t\t\t\t\xBA                                                \xBA\n");
		printf("\t\t\t\t\xBA                                                \xBA\n");

	switch(menu){
		case 1:			
			printf("\t\t\t\t\xBA   VOCE GOSTARIA DE CONHECER A REGI\xc7O NORTE!    \xBA\n");
			break;
		case 2:
			printf("\t\t\t\t\xBA  VOCE GOSTARIA DE CONHECER A REGI\xc7O NORDESTE!  \xBA\n");
			break;
		case 3:
			printf("\t\t\t\t\xBAVOCE GOSTARIA DE CONHECER A REGI\xc7O CENTRO-OESTE!\xBA\n");
			break;
		case 4:
			printf("\t\t\t\t\xBA  VOCE GOSTARIA DE CONHECER A REGI\xc7O SUDESTE!   \xBA\n");
			break;
		case 5:
			printf("\t\t\t\t\xBA    VOCE GOSTARIA DE CONHECER A REGI\xc7O SUL!     \xBA\n");
			break;
		case 0:
			printf("\t\t\t\t\xBA              SAIR DO PROGRAMA.                 \xBA\n");
			printf("\t\t\t\t\xBA                                                \xBA\n");
			printf("\t\t\t\t\xBA                                                \xBA\n");
			printf("\t\t\t\t\xBA                                                \xBA\n");
			printf("\t\t\t\t\xBA                                                \xBA\n");
			printf("\t\t\t\t\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
    		exit(1);
			break;
	}
	
		printf("\t\t\t\t\xBA                                                \xBA\n");
		printf("\t\t\t\t\xBA                                                \xBA\n");
		printf("\t\t\t\t\xBA                                                \xBA\n");
		printf("\t\t\t\t\xBA                                                \xBA\n");
		printf("\t\t\t\t\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
}
