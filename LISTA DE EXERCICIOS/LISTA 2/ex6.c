#include<stdio.h>
#include<stdlib.h>

//Estrutura de no para lista encadeada
typedef struct no{
    int info;
    struct no* prox;
}No;

//Estrutura para fila
typedef struct fila{
    int n; //numero de elementos
    struct no* prim;
    struct no* ultimo;
}Fila;

void inicializa_fila(Fila* f){
    f->n = 0;
    f->prim = NULL;
    f->ultimo = NULL;
}

//Testa se a fila esta vazia
//Entrada: fila;
//Retorno: 1 se a fila eh vazia ou 0 caso contrario
//Pre-conticao: ponteiro nao nulo para estrutura fila
//Pos-condicao: nenhuma
int vazia(Fila* f){
    return (f->prim == NULL);
}

//Insere um elemento na fila
//Entrada: fila e inteiro a ser inserido
//Retorno: nenhum
//Pre-condicao: ponteiro nao nulo para estrutura fila
//Pos-condicao: elemento eh inserido na fila
void enqueue(Fila* f, int info){

    No* aux = (No*)malloc(sizeof(No));
    aux->info = info;
    aux->prox = NULL;
    f->n++;
    if(vazia(f)) f->prim = aux;
    else f->ultimo->prox = aux;
    f->ultimo = aux;
}

//Remove um elemento da fila
//Entrada: fila
//Retorno: nenhum
//Pre-condicao: ponteiro nao nulo para estrutura fila
//Pos-condicao: elemento ehremovido da fila
void dequeue(Fila* f){
    No* aux = f->prim;
    f->prim = f->prim->prox;
    free(aux);
    f->n--;
}

No* remove_ultimo(Fila* f, No* l){
    if(l->prox->prox == NULL){
        No* aux = l->prox;
        l->prox = NULL;
        f->ultimo = l;
        free(aux);
        return l;
    }
    l->prox = remove_ultimo(f, l->prox);
}

void dequeue_fim(Fila* f){
    if(vazia(f)) return;
    f->prim = remove_ultimo(f, f->prim);
    f->n--;
}

void imprimir_aux(No* l){
    if(l == NULL) return;
    printf("%d->", l->info);
    imprimir_aux(l->prox);
}

//Imprime os elementos da fila
//Entrada: fila
//Retorno: nenhum
//Pre-condicao: ponteiro nao nulo para estrutura fila
//Pos-condicao: os elementos sao impressos no console
void imprimir(Fila* f){
    if(vazia(f)) return;
    imprimir_aux(f->prim);
}

No* inserir_cabeca(No* l, int info){
    No* novo = (No*) malloc(sizeof(No));
    novo->info = info;
    novo->prox = l;
    return novo;
}

No* inverter_aux(No* l, No* l2){
    if(l == NULL) return l2;
    l2 = inserir_cabeca(l2, l->info);
    l2 = inverter_aux(l->prox, l2);
    return l2;
}

// Inverte uma No
// Entrada: lista
// Retorno: lista invertida
// Pre-condicao: nenhuma
// Pos-condicao: lista original nao eh modificada
No* inverter_lista(No* l){
    No* nova = NULL;
    nova = inverter_aux(l, nova);
    return nova;
}

void inverter(Fila* f){
    f->prim = inverter_lista(f->prim);
}

int main(){

    Fila* f;
    inicializa_fila(f);
    enqueue(f, 1);
    enqueue(f, 2);
    enqueue(f, 3);
    enqueue(f, 4);
    enqueue(f, 5);
    imprimir(f);
    inverter(f);
    printf("\n");
    imprimir(f);
    
    return 0;
}