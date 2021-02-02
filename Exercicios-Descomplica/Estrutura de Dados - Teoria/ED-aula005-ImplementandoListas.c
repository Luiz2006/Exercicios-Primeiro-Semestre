#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include "ED-aula005-ImplementandoListas.h"

struct lista{
    int qtd;
    struct aluno dados[MAX];
};

int main(void){
    setlocale(LC_ALL, "Portuguese");

    Lista *li;
    li = cria_lista();

    int x = tamanho_lista(li);

    int y = lista_cheia(li);

    int z = lista_vazia(li);

    int a = insere_lista_final(li, dados_aluno);

    int b = insere_lista_inicio(li, dados_aluno);

    libera_lista(li);
    system("PAUSE");
    return 0;
}

Lista * cria_lista(){
    Lista *li;
    li = (Lista*) malloc(sizeof(struct lista));
    if(li != NULL){
        li->qtd = 0;
        printf("Lista criada com sucesso!");
    }
    return li;
}

void libera_lista(Lista* li){
    printf("\nAlocação liberada com sucesso!");
    free(li);
}

int tamanho_lista(Lista* li){
    if(li == NULL){
        return -1;
    } else{
        return li->qtd;
    }
}

int lista_cheia(Lista* li){
    if(li == NULL){
        return -1;
    } else{
        if(li->qtd == MAX){
            return 1;
        } else {
            return 0;
        }
    }
}

int lista_vazia(Lista* li){
    if(li == NULL){
        return -1;
    }else{
        if(li->qtd == 0){
            return 1;
        }else{
            return 0;
        }
    }

int insere_lista_final(Lista* li, struct aluno a1){
    if(li == NULL){
        return 0;
    }
    if(lista_cheia(li)){
        return 0;
    }
    li->dados[li->qtd] = a1;
    li->qtd++;
    return 1;
}

int insere_lista_inicio(Lista* li, struct aluno a1){
    if(li == NULL) return 0;
    if(lista_cheia(li)) return 0;
    int i;
    for(i = li->qtd - 1; i >= 0; i--){
        li->dados[i+1] = li->dados[i];
    }
    li->dados[0] = a1;
    li->qtd++;
    return 1;
}

int insere_lista_ordenada(Lista* li, struct aluno a1){
    if(li == NULL) return 0;
    if(lista_cheia(li)) return 0;
    int k, i = 0;
    while(i<li->qtd && li->dados[i].matricula < a1.matricula){
        i++;
    }
    for(k = li->qtd - 1; k >= i; k--){
        li->dados[k + 1] = li->dados[k];
    }
    li->dados[i] = a1;
    li->qtd++;
    return 1;

}







