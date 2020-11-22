#include<stdio.h>

int main()
{
    int num1, num2, num3;
    float media;

    printf("Informe o 1° número: ");
    scanf("%i", &num1);
    printf("Informe o 2° número: ");
    scanf("%i", &num2);
    printf("Informe o 3° número: ");
    scanf("%i", &num3);
    
    media = ((num1 + num2 + num3) / 3);
    
    printf("MÉDIA: %i.", media);
    return 0;
}