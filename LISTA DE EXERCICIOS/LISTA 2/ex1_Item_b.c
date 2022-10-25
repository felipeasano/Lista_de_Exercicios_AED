/*
    2 Abordagem:
        -As Funcoes devem ser implementadas de maneira RECURSIVA
        -A funcao INSERIR insere o elemento no final da lista
        -Os elementos podem estar desordenados
        -Pode haver elementos repetidos e a operacao REMOVER retira apenas a primeira ocorrencia do elemento
*/

#include<stdio.h>
#include<stdlib.h>

//Estrutura de no para lista encadeada
typedef struct no{
    int info;
    struct no *prox;
}LISTA;

//Testa se uma lista eh vazia
//Entrada: Lista
//Retorno: 1 se vazia, 0 caso contrario
//Pre-Condicao: Nenhuma
//Pos-Condicao: Nenhuma
int vazia(LISTA* l){
    return (l == NULL);
}

//Insere um elemento na lista
//Entrada: Lista e elemento a ser inserido
//Retorno: Lista alterada
//Pre-Condicao: Nenhuma
//Pos-Condicao: Elemento eh inserido na lista
LISTA* inserir(LISTA* l, int info){
    if(vazia(l)){
        l = (LISTA*) malloc(sizeof(LISTA));
        l->info = info;
        l->prox = NULL;
        return l;
    }
    else{
        l->prox = inserir(l->prox, info);
    }
    return l;
}

LISTA* inserir_cabeca(LISTA* l, int info){
    LISTA* aux = (LISTA*) malloc(sizeof(LISTA));
    aux->info = info;
    aux->prox = l;
    return aux;
}

LISTA* remover_aux(LISTA *ant, LISTA* prox, int info){
    if(vazia(prox)) return NULL;
    if(prox->info == info){
        ant->prox = prox->prox;
        free(prox);
        return ant;
    }
    return remover_aux(prox, prox->prox, info);
}

//Remove um elemento da lista
//Entrada:Lista e elemento a ser removido
//Retorno:Lista alterada
//Pre-Condicao:Nenhuma
//Pos-Condicao:Elemento eh removido da lista
LISTA* remover(LISTA* l, int info){

    if(l->info == info){
        LISTA* aux = l;
        l = l->prox;
        free(aux);
        return l;
    }
    LISTA* aux = l;
    aux = remover_aux(aux, aux->prox, info);
    return l;
}

//Imprime os elementos da lista
//Entrada: Lista
//Retorno: Nenhum
//Pre-Condicao: Nenhuma
//Pos-Condicao: Elementos sao impressos no console
void imprimir(LISTA* l){
    if(l){
        printf("%d->", l->info);
        imprimir(l->prox);
    }
}

LISTA* inverter_aux(LISTA* l1, LISTA* l2){
    if(vazia(l1)) return l2;
    l2 = inserir_cabeca(l2, l1->info);
    l2 = inverter_aux(l1->prox, l2);
    return l2;
}

//Inverte uma lista
//Entrada: Lista
//Retorno: Lista invertida
//Pre-Condicao: Nenhuma
//Pos-Condicao: Lista original nao eh modificada
LISTA* inverter(LISTA *l){
    if(l->prox == NULL) return l;
    LISTA* aux = NULL;
    aux = inverter_aux(l, aux);
    return aux;
}

LISTA* concatenar_aux(LISTA* l1, LISTA* l2){

    if(!vazia(l2)){
        if(vazia(l1)) {
            l1 = inserir(l1, l2->info);
            l1->prox = concatenar_aux(l1->prox, l2->prox);
        }else{
            l1->prox = concatenar_aux(l1->prox, l2);
        }
    }
    return l1;
}

//Concatena lista
//Entrada: Listas a serem concatenadas
//Retorno: Lista resultante da concatenacao
//Pre-Condicao: Nenhuma
//Pos-Condicao: Listas originais nao sao modificadas
LISTA* concatenar(LISTA* l1, LISTA* l2){
    
    LISTA* l3 = NULL;

    l3 = concatenar_aux(l3, l1);
    l3 = concatenar_aux(l3, l2);
    return l3;
}

LISTA* intercalar_aux(LISTA *l1, LISTA* l2, LISTA* l3){

    if(!vazia(l1)){
        l3 = inserir(l3, l1->info);
        l1 = l1->prox;
    }
    if(!vazia(l2)){
        l3 = inserir(l3, l2->info);
        l2 = l2->prox;
    }
    if(vazia(l1) && vazia(l2)) return l3;
    else l3->prox = intercalar_aux(l1, l2, l3->prox);

    return l3;
}

//Intercala lista
//Entrada: Listas a serem intercaladas
//Retorno: Lista resultante da intercalacao
//Pre-Condicao: Nenhuma
//Pos-Condicao: Listas originais permanecem inalteradas
LISTA* intercalar(LISTA* l1, LISTA* l2){
    LISTA* l3 = NULL;
    l3 = intercalar_aux(l1, l2, l3);
    return l3;
}

int main(){

    LISTA* l = NULL;
    LISTA* l2 = NULL;
    LISTA* l3 = NULL;

    l = inserir(l, 10);
    l = inserir(l, 20);
    l = inserir(l, 30);
    l = inserir(l, 40);
    l = inserir(l, 50);
    l2 = inserir(l2, 60);
    l2 = inserir(l2, 70);
    l2 = inserir(l2, 20);
    l2 = inserir(l2, 90);
    l2 = inserir(l2, 100);

    printf("Lista 1: ");
    imprimir(l);
    printf("\nLista 2: ");
    imprimir(l2);
//    l = remover(l, 20);
//    l = inverter(l);
    l3 = intercalar(l, l2);
    printf("\nNova Lista: ");
    imprimir(l3);
    return 0;
}
