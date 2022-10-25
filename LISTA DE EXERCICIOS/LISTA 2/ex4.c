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
    return l;
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
}

void imprimir(Lista* l){
    if(!vazia(l)){
        printf("%d->", l->info);
        imprimir(l->prox);
    }
}

Lista* remover_aux(Lista* l, int info){
    if(l->prox->info == info && l->prox->prox == NULL){
        Lista* aux = l->prox;
        l->prox = NULL;
        free(aux);
        return l;
    }
    if(l->prox->info == info){
        Lista* aux = l->prox;
        l->prox = l->prox->prox;
        l->prox->prox->ant = l;
        free(aux);
        l = remover_aux(l, info);
    }else l->prox = remover_aux(l->prox, info);
    return l;
}

Lista* remover(Lista* l, int info){
    if(l->info == info){
        Lista* aux = l;
        l = l->prox;
        l->ant = NULL;
        free(aux);
    }else{
        l = remover_aux(l, info);
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