#include<stdio.h>

int main(){
    char sexo;
    
    printf("Digite o sexo [m / f]: ");
    scanf("%c", &sexo);
    
    sexo == 'f' || sexo == 'F' ? printf("Sexo feminino.") : sexo == 'm' || sexo == 'M' ? printf("Sexo masculino.") : printf("Letra errada! ");
    
    return 0;
}
