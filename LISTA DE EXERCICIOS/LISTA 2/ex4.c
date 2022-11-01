// Lista Duplamente Encadeada

#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int info;
    struct no* prox;
    struct no* ant;
}Lista;

int vazia(Lista* l){
    return (l == NULL);
}

Lista* inserir_cabeca(Lista* l, int info){
    if(vazia(l)){
        l = (Lista*)malloc(sizeof(Lista));
        l->info = info;
        l->ant = NULL;
        l->prox = NULL;
        return l;
    }
    Lista* aux = (Lista*) malloc(sizeof(Lista));
    aux->info = info;
    aux->ant = NULL;
    aux->prox = l;
    l->ant = aux;
    return aux; 
}

Lista* inserir_cauda(Lista* l, int info){
    if(vazia(l)){
        l = (Lista*)malloc(sizeof(Lista));
        l->info = info;
        l->ant = NULL;
        l->prox = NULL;
        return l;
    }
    l->prox = inserir_cauda(l->prox, info);
    l->prox->ant = l;
    return l;
}

void imprimir(Lista* l){
    if(!vazia(l)){
        printf("%d->", l->info);
        imprimir(l->prox);
    }
}


Lista* remover(Lista* l, int info){
    if(vazia(l)) return NULL;
    Lista* rem = l;

    if(rem->info == info){
        l = l->prox;
        l->ant = NULL;
        free(rem);
        return l;
    }

    while(rem && rem->info != info){
        rem = rem->prox;
    }

    if(rem != NULL){
        Lista* aux = rem->ant;
        aux->prox = rem->prox;
        if(rem->prox != NULL){
            rem->prox->ant = aux;
        }
        free(rem);
    }
    return l;
}

int main(){

    Lista* l = NULL;
    l = inserir_cauda(l, 10);
    l = inserir_cauda(l, 20);
    l = inserir_cauda(l, 30);
    l = inserir_cauda(l, 30);
    l = inserir_cauda(l, 50);

    imprimir(l);
    l = remover(l, 30);
    printf("\n");
    imprimir(l);

    return 0;
}