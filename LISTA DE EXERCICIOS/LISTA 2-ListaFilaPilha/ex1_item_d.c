/*
    implemente a funcao Lista* append(Lista* l1, Lista* l2)
    que concatena l2 no final de l1 retornando l1 modificada.
*/
#include<stdio.h>
#include<stdlib.h>

// estrutura de no para lista encadeada
typedef struct no {
    int info;
    struct no *prox;
} Lista;

// Testa se uma lista eh vazia
// Entrada: lista
// Retorno: 1 se a lista eh vazia ou 0 caso contrario
// Pre-condicao: nenhuma
// Pos-condicao: nenhuma
int vazia(Lista * l){
    return (l == NULL);
}

Lista* inserir_cabeca(Lista* l, int info){
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->info = info;
    novo->prox = l;
    return novo;
}

// Insere um elemento na lista
// Entrada: lista e elemento a ser inserido
// Retorno: lista alterada
// Pre-condicao: nenhuma
// Pos-condicao: elemento e inserido na lista de maneira ordenada
Lista* inserir_ordenado(Lista* l, int info){
    if(vazia(l)){
        l = (Lista*) malloc(sizeof(Lista));
        l->info = info;
        l->prox = NULL;
        return l;
    }
    
    if(info < l->info){
        Lista* novo = (Lista*) malloc(sizeof(Lista));
        novo->info = info;
        novo->prox = l;
        return novo;
    }
    l->prox = inserir_ordenado(l->prox, info);
    return l;
}

Lista* inserir(Lista* l, int info){
    if(vazia(l)){
        l = (Lista*) malloc(sizeof(Lista));
        l->info = info;
        l->prox = NULL;
        return l;
    }
    else l->prox = inserir(l->prox, info);
    return l;
}

// Remove um elemento da lista
// Entrada: lista e elemento a ser removido
// Retorno: lista alterada
// Pre-condicao: nenhuma
// Pos-condicao: elemento eh removido da lista
Lista* remover(Lista* l, int info){
    
    if(vazia(l)) 
        return l;   
    if(l->info == info){
        Lista * aux = l;
        l = l->prox;
        free(aux);
        l = remover(l, info);
    }
    else l->prox = remover(l->prox,info);
    return l;
}


// Imprime os elementos da lista
// Entrada: lista
// Retorno: nenhum
// Pre-condicao: nenhuma
// Pos-condicao: os elementos sao impressos no console
void imprimir(Lista* l){
    if(l){
        printf("%d->", l->info);
        imprimir(l->prox);
    }
}

Lista* inverter_aux(Lista* l, Lista* l2){
    if(vazia(l)) return l2;
    l2 = inserir_cabeca(l2, l->info);
    l2 = inverter_aux(l->prox, l2);
    return l2;
}

// Inverte uma lista
// Entrada: lista
// Retorno: lista invertida
// Pre-condicao: nenhuma
// Pos-condicao: lista original nao eh modificada
Lista* inverter(Lista* l){
    Lista* nova = NULL;
    nova = inverter_aux(l, nova);
    return nova;
}

Lista* concatenar_aux(Lista* l1, Lista* l2, Lista* l3){
    if(!vazia(l1)){
        l3 = inserir(l3, l1->info);
        l3->prox = concatenar_aux(l1->prox, l2, l3->prox);
    }else{
        if(!vazia(l2)){
            l3 = inserir(l3, l2->info);
            l3->prox = concatenar_aux(l1, l2->prox, l3->prox);
        }
    }
    return l3;
}

// Concatena duas listas
// Entrada: listas a serem concatenadas
// Retorno: lista resultante da concatenacao
// Pre-condicao: nenhuma
// Pos-condic~ao: listas originais nao sao modificadas
Lista* concatenar(Lista* l1, Lista* l2){
    Lista* nova = NULL;
    nova = concatenar_aux(l1, l2, nova);
    return nova;
}

Lista* intercalar_aux(Lista* l1, Lista* l2, Lista* l3){

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

// Intercala duas listas
// Entrada: listas a serem intercaladas
// Retorno: lista resultante da intercalacao
// Pre-condicao: nenhuma
// Pos-condicao: listas originais permanecem inalteradas
Lista* intercalar(Lista* l1, Lista* l2){
    Lista* nova = NULL;
    nova = intercalar_aux(l1, l2, nova);
    return nova;
}

// Intercala duas listas
// Entrada: Listas a serem intercaladas
// Retorno: Lista resultante da intercalaca
// Pre-condicao: nenhuma
// Pos-Condicao: concatena l2 no final de l1 retornando l1 modificada.
Lista* append(Lista* l1, Lista* l2){

    if(vazia(l1)){
        l1 = l2;
        return l1;
    }
    l1->prox = (append(l1->prox, l2));
    return l1;
}

int main(){

    Lista* l = NULL;
    Lista* l2 = NULL;
    Lista* l3 = NULL;

    l = inserir(l, 10);
    l = inserir(l, 20);
    l = inserir(l, 30);
    l = inserir(l, 40);
    l = inserir(l, 50);
    l2 = inserir(l2, 5);
    l2 = inserir(l2, 7);
    l2 = inserir(l2, 2);
    l2 = inserir(l2, 9);
    l2 = inserir(l2, 2);

    printf("Lista 1: ");
    imprimir(l);
    printf("\nLista 2: ");
    imprimir(l2);

    l = append(l, l2);
    printf("\n\nLista nova: ");
    imprimir(l);
    printf("\nLista 2: ");
    imprimir(l2);
    return 0;
}