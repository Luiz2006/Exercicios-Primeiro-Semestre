#include<stdio.h>

int main(){
    char sexo;
    
    printf("Escreva m ou f: ");
    scanf("%c", &sexo);
    
    while(sexo != 'f' || sexo != 'F' || sexo != 'm' || sexo == 'M'){
        printf("Escreva m ou f: ");
        scanf("%c", &sexo);
    }
    
    sexo == 'f' || sexo == 'F' ? printf("Sexo femenino.") : printf("Sexo masculino! ");
    
    return 0;
}