#include<stdio.h>

int main(){
    char sexo;
    
    printf("Escreva m ou f: ");
    scanf("%c", &sexo);
    
    sexo == 'f' || sexo == 'F' ? printf("Sexo femenino.") : sexo == 'm' || sexo == 'M' ? printf("Sexo masculino.") : printf("Letra errada! ");
    
    return 0;
}
