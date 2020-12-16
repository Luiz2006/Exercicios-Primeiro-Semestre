#include<stdio.h>

int main()
{
    int horas;

    printf("Informe um valor em horas: ");
    scanf("%i", &horas);
    printf("%ih em minutos: %im.\n", horas, horas*60);
    printf("%ih em segunds: %is.\n", horas, horas*3600);

    return 0;
}