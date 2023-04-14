#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int info;
    struct no* prox;
    struct no* ant;
}Lista;

int vazia(Lista* l){
    return(l == NULL);
}

void printa_lista(Lista* l, Lista* cabeca){
    printf("%d->", l->info);
    if(l->prox != cabeca) printa_lista(l->prox, cabeca);
}

Lista* inserir(Lista* l, int info){

    if(vazia(l)){
        l = (Lista*)malloc(sizeof(Lista));
        l->prox = l;
        l->ant = l;
        l->info = info;
    }else{
        Lista* aux = (Lista*)malloc(sizeof(Lista));
        aux->info = info;
        aux->prox = l;
        aux->ant = l->ant;
        l->ant->prox = aux;
        l->ant = aux;
        return aux;
    }
    return l;
}

Lista* remover(Lista* l, int info){

    if(vazia(l)) return NULL;
    Lista* rem = l;

    //remocao caso o elemento esteja na cabeca
    if(rem->info == info){
        l = l->prox;
        l->ant = rem->ant;
        rem->ant->prox = l;
        free(rem);
        return l;
    }
    rem = rem->prox;
    while(rem != l && rem->info != info){
        rem = rem->prox;
    }

    if(rem != l){
        Lista* aux = rem->ant;
        aux->prox = rem->prox;
        rem->prox->ant = rem;
        free(rem);
    }
    return l;
}


int main(){

    Lista* l = NULL;
    l = inserir(l, 1);
    l = inserir(l, 2);
    l = inserir(l, 3);

    printa_lista(l, l);
    l = remover(l, 1);
    printf("\n");
    printa_lista(l, l);
    return 0;
}