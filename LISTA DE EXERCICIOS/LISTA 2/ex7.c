#include<stdio.h>
#include<stdlib.h>

// estrutura de no para lista encadeada
typedef struct no{
    int info;
    struct no* prox;
}Lista;

// testa se uma pilha eh vazia
// entrada: pilha
// retorno: 1 se a pilha eh cazia ou 0 caso contrario
// pre-condicao: nenhuma
// pos-condicao: nenhuma
int vazia(Lista* st){
    return (st == NULL);
}

// enpilha um elemento na pilha
// entrada: pilha e inteiro a ser empilhado
// retorno: pilha alterada
// pre-condicao: nenhuma
// pos-condicao: elemento eh empilhado
Lista* push(Lista* l, int info){
    Lista* nova = (Lista*)malloc(sizeof(Lista));
    nova->info = info;
    nova->prox = l;
    return nova;
}

// desempilha um elemento da pilha
// entrada: pilha
// retorno: pilha alterada
// pre-condicao: nenhuma
// pos-condicao: elemento do topo eh removido
Lista* pop(Lista* st){
    Lista* aux = st;
    st = st->prox;
    free(aux);
    return st;
}

// le o topo da pilha
// entrada: pilha
// retorno: elemento do topo da pilha ou -1 se a pilha estiver vazia
// pre-condicao: nenhuma
// pos-condicao: retorna o topo da pilha
int topo(Lista* st){
    if(vazia(st)) return -1;
    else return st->info;
}

// imprime os elementos da pilha
// entrada: pilha
// retorno: nenhum
// pre-condicao: nenhuma
// pos-condicao: os elementos sao impressos no console
void imprimir(Lista* st){
    if(vazia(st)) return;
    printf("[%d]->", st->info);
    imprimir(st->prox);
}

int main(){
    Lista* st = NULL;
    st = push(st, 1);
    st = push(st, 2);
    st = push(st, 3);
    st = push(st, 4);
    st = push(st, 5);

    imprimir(st);
    printf("\n[%d]\n\n", topo(st));
    st = pop(st);
    imprimir(st);
    printf("\n[%d]", topo(st));
    return 0;
}