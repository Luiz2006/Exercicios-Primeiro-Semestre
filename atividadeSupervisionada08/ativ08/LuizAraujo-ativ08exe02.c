#include<stdio.h>
#include<conio.h>
#include<locale.h>
int main(){
    setlocale(LC_ALL,"Portuguese");
    float val1, val2, val3;
    
    printf("Informe o primeiro valor: ");
    scanf("%f", &val1);
    printf("Informe o segundo valor: ");
    scanf("%f", &val2);
    printf("Informe o terceiro valor: ");
    scanf("%f", &val3);
    gotoxy(24,11);
    if((val1 > val2) && (val1 > val3)){  
    	gotoxy(24,11);
        printf("O maior valor informado é o %f!", val1);
    }else{
        if((val2 > val1) && (val2 > val3)){  
            printf("O maior valor informado é o %f!", val2);
        }else{
            if((val3 > val1) && (val3 > val2)){  
                printf("O maior valor informado é o %f!", val3);
            }else{  
    			gotoxy(20,11);
                printf("Não há um valor maior!");
            }
        }
    }
}
