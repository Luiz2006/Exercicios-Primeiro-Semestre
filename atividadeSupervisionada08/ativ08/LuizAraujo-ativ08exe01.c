#include<stdio.h>

int main(){
    float porcentagem, resultado;
    int const valor = 555;
    
    
    printf("Informe uma porcentagem: ");
    scanf("%f", &porcentagem);
    
    resultado = (555 * (porcentagem/100));

    printf("%.2f%% de %i: %.2f%%.", porcentagem, valor, resultado);
}
