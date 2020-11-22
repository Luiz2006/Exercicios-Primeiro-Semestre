#include<stdio.h>
#include<math.h>

int main()
{
    float raio, area;

    printf("Informe o raio: ");
    scanf("%i", &raio);
    area = 3.14 * pow(raio,2);
    printf("Área = %i.\n", area);
    
    return 0;
}