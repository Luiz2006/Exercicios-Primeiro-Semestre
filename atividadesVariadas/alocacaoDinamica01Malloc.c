/*
Name: Alocacao Dinamica 01 Malloc
Copyright: MIT License
Author: Luiz Araujo - luizcarlos_bsb2006@hotmail.com
Date:
Description: 01 Malloc
-> malloc
-> calloc
-> realloc
-> free
=> sizeof
*/

#include<stdio.h>
#include<stdlib.h>


int main(void)
{
    short x; //2 bytes
    x = 10;

    int c[10]; //40 bytes

    short *d = &x; //8 bytes

    int *p = (int *)malloc(sizeof(int));
//	int *p = (int *)malloc(200000000000);

    printf("%li\n\n", sizeof(c));
    printf("%i\n\n", *d);

    printf("%i\n\n", p);



    if(p == NULL)
    {
        puts("O SISTEMA NAO CONSEGUIU ALOCAR MEMORIA!!!");
        //aqui colocaria um algoritmo pra contornar a alocação de mem, ou oferta de outro serviço
    }




    printf("\n\n\nPRESSIONE QUALQUER TECLA PARA ENCERRAR.\n");
    getch();
    return 0;
}
