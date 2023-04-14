// verificar se uma lista  ́e vazia
// inserir um elemento na cabeca
// inserir um elemento na cauda
// remover um dado elemento da lista

#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int info;
    struct no *prox;
}No;


//Estrututra para lista encadeada com cabeca e cauda
typedef struct {
    struct no* inicio;
    struct no* fim;
}Fila;

int vazia(Fila* l){
    return(l->inicio == NULL);
}

Fila* cria_Fila_vazia(){
    Fila* l = (Fila*)malloc(sizeof(Fila));
    l->inicio = NULL;
    l->fim = NULL;
    return l;
}

// Enfila um elemento na cabeca da fila
void enqueue_cabeca(Fila* f, int info){
    struct no* aux = (No*)malloc(sizeof(No));
    aux->info = info;
    if(vazia(f)){
        f->inicio = aux;
        f->fim = aux;
        aux->prox = NULL;
    }else{
        aux->prox = f->inicio;
        f->inicio = aux;
    }
}

// Enfila um elemento no fim da fila
void enqueue(Fila* l, int info){
    struct no* aux = (No*)malloc(sizeof(No));
    aux->info = info;
    aux->prox = NULL;
    if(vazia(l)) l->inicio = aux;
    else l->fim->prox = aux;
    l->fim = aux;
}

void busca_aux(No* l, int info){
    if(l->info == info) {
        printf("%d", info);
        return;
    }
    busca_aux(l->prox, info);
}

void busca(Fila* l, int info){
    busca_aux(l->inicio, info);
}

void remover_fim(Fila* f, No* l){
    if(l->prox->prox == NULL){
        No* aux = l->prox;
        l->prox = NULL;
        f->fim = l;
        free(aux);
    }
    else remover_fim(f, l->prox);
}

No* remover_meio(No* l, int info){
    if(l == NULL) return NULL;
    if(l->prox->info == info){
        No* aux = l->prox;
        l->prox = l->prox->prox;
        free(aux);
        return l;
    }
    else l->prox = remover_meio(l->prox, info);
    return l;
}

void remover(Fila* f, int info){
    if(f->inicio->info == info){
        struct no* aux = f->inicio;
        f->inicio = f->inicio->prox;
        free(aux);
    }else{
        if(f->fim->info == info){
            remover_fim(f, f->inicio);
        }else{
            f->inicio = remover_meio(f->inicio, info);
        }
    }
}

void imprimir_aux(No* l){
    if(l){
        printf("%d->", l->info);
        imprimir_aux(l->prox);
    }
}

// Imprime uma Fila
void imprimir(Fila* l){
    imprimir_aux(l->inicio);
}

int main(){

    Fila* l = cria_Fila_vazia();
    enqueue_cabeca(l, 1);
    enqueue_cabeca(l, 2);
    enqueue_cabeca(l, 3);
    enqueue_cabeca(l, 4);
    enqueue_cabeca(l, 5);
    enqueue_cabeca(l, 6);
    enqueue_cabeca(l, 7);
    enqueue_cabeca(l, 8);
    enqueue_cabeca(l, 9);
    enqueue_cabeca(l, 10);

    imprimir(l);

    remover(l, 1);
    printf("\n");
    imprimir(l);
    remover(l, 10);
    printf("\n");
    imprimir(l);
    remover(l, 2);
    printf("\n");
    imprimir(l);
    remover(l, 9);
    printf("\n");
    imprimir(l);
    remover(l, 6);
    printf("\n");
    imprimir(l);

    return 0;
}

