#include<stdio.h>

int main()
{
    int num1, num2;

    printf("Informe o 1° número: ");
    scanf("%i", &num1);
    printf("Informe o 2° número: ");
    scanf("%i", &num2);
    
    printf("O quociente de %i / %i: %i.\n", num1, num2, (num1 / num2));
    printf("O resto de %i / %i: %i.\n", num1, num2, (num1 % num2));
    return 0;
}