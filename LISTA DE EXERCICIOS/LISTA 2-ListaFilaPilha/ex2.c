#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    char c;
    struct no* prox;
}Lista;

int vazia(Lista* l){
    return (l == NULL);
}

Lista* inserir(Lista* l, char c){
    if(vazia(l)){
        Lista* aux = (Lista*) malloc(sizeof(Lista));
        aux->c = c;
        aux->prox = NULL;
        return aux;
    }
    l->prox = inserir(l->prox, c);
    return l;
}

void imprimir(Lista* l){
    if(!vazia(l)){
        printf("%c->", l->c);
        imprimir(l->prox);
    }
}

void imprimir_aux(Lista* l, int i){

    int j = 0;
    

}

void imprimir_comb_pos(Lista* l){

    int i = 1;
    while(l){
        imprimir_aux(l, i);
        l = l->prox;
        i++;
    }
}

int main(){

    Lista* l = NULL;
    l = inserir(l, 'a');
    l = inserir(l, 'b');
    l = inserir(l, 'c');
    l = inserir(l, 'd');
    l = inserir(l, 'e');

    imprimir(l);

    return 0;
}