#include<stdio.h>
int main(){
    char caractere;
    
    printf("Informe um caractere: ");
    scanf("%c", &caractere);

    printf("\nCaractere: %c\n",caractere);
    printf("Octal    : %o\n",caractere);
    printf("Decimal  : %d\n",caractere);
    printf("Hexadec. : %x\n",caractere);
}
