/*
    1 Abordagem:
        -As funcoes sao implementadas de maneira ITERATIVA
        -A funcao inserir insere na cabeca da lista
        -Os elementos podem estar desordenados
        -Pode haver elementos repetidos e a operacoa remover retira apenas a primeira ocorrencia do elemento  
*/
#include<stdio.h>
#include<stdlib.h>

//Numero Maximo de intens na Lista
#define TAM_MAX 1000

//Estrutura de no para lista encadeada
typedef struct{
    int item[TAM_MAX];
    int pos_livre;
}LISTA;

//Cria uma Lista Vazia
//Pre-Condicao: Nenhuma
//Pos-Condicao: Lista criada
LISTA* cria_lista_vazia(){
    LISTA* nova_lista = (LISTA*) malloc(sizeof(LISTA));
    nova_lista->pos_livre = 0;
    return nova_lista;
}

//Testa se uma lista eh vazia
//Entrada: Lista
//Retorno: 1 se a lista esta vazia ou 0 caso contrario
//Pre-Condicao: Nenhuma
//Pos-Condicao: Nenhuma
int vazia(LISTA* l){
    return (l->pos_livre == 0);
}

//Insere um elemento na lista
//Entrada: Lista e elemento a ser inserido
//Retorno: Lista alterada
//Pre-Condicao: Nenhuma
//Pos-Condicao: Elemento eh inserido na lista
void inserir(LISTA *l, int info){
    if(l->pos_livre >= TAM_MAX) printf("LISTA CHEIA.");
    //else l->item[l->pos_livre++] = info;
    else{
        l->pos_livre++;
        int i;
        for(i = l->pos_livre; i > 0; i--){
            l->item[i] = l->item[i-1];
        }
        l->item[0] = info;
    }
}

void inserir_fim(LISTA* l, int info){
    if(l->pos_livre >= TAM_MAX) printf("LISTA CHEIA.");
    else l->item[l->pos_livre++] = info;
}

//Remover um elemento da lista
//Entrada: Lista e elemento a ser removido
//Retorno: Lista alterada
//Pre-Condicao: Nenhuma
//Pos-Condicao: Elemento eh removido da lista
void remover(LISTA* l, int info){
    if(vazia(l)) printf("Lista vazia: Sem elementos para retirar.");
    else{
        int pos = 0;
        while(pos < l->pos_livre && info != l->item[pos]) pos++;
        if(pos == l->pos_livre) printf("Elemento nao encontrado");
        else{
            int i;
            for(i = pos; i < l->pos_livre; i++)
                l->item[i] = l->item[i+1];
            l->pos_livre--;
        }
    }
}

//Imprime os elementos da lista
//Entrada: Lista
//Retorno: Nenhum
//Pre-Condicao: Nenhuma
//Pos-Condicao: Os elementos sao impressos no console
void imprimir(LISTA* l){
    if(vazia(l)) printf("Lista vazia\n");
    else{
        int pos;
        for(pos = 0; pos < l->pos_livre; pos++){
            printf("%d ", l->item[pos]);
        }
    }
}

//Inverte uma lista
//Entrada: Lista
//Retorno: Lista invertida
//Pre-Condicao: Nenhuma
//Pos-Condicao: Lista original nao eh modificada
LISTA* inverter(LISTA *l){
    LISTA* l_invertida = cria_lista_vazia();
    int j;
    int i;
    for(i = 0, j = l->pos_livre-1; i < l->pos_livre; i++, j--)
        l_invertida->item[i] = l->item[j];
    l_invertida->pos_livre = l->pos_livre;
    return l_invertida;
}

//Concatena duas listas
//Entrada: Listas a serem concatenadas
//Retorno: Lista resultate da concatenacao
//Pre-Condicao: Nenhuma
//Pos-Condicao: Listas originais nao sao modificadas
LISTA* concatenar(LISTA* l1, LISTA* l2){

    LISTA* nova_lista = cria_lista_vazia();
    int i, loc = 0, j, pos;
    pos = l1->pos_livre + l2->pos_livre;
    for(i = 0, j = 0; i < pos; i++, j++){
        if(j == l1->pos_livre){
            j = 0;
            loc = 1;
        }
        if(loc == 0) inserir_fim(nova_lista, l1->item[j]);
        else inserir_fim(nova_lista, l2->item[j]);
    }
    return nova_lista;
}

//Intercala duas listas
//Entrada: Listas a serem intercaladas
//Retorno: Lista resultante da intercalacao
//Pre-Condicao: Nenhuma
//Pos-Condicao: Listas originais Permanecem inalteradas
LISTA* intercalar(LISTA *l1, LISTA *l2){

    LISTA* nova_lista = cria_lista_vazia();
    int i, j, k;
    int pos = l1->pos_livre + l2->pos_livre;
    int loc = 0;

    for(i = 0, j = 0, k = 0; i < pos; i++){
        if(j == l1->pos_livre && loc == 0){
            j = 0;
            loc = 1;
        }
        if(i%2 == 0 && loc == 0){
            inserir_fim(nova_lista, l1->item[j]);
            j++;
        } 
        else {
            inserir_fim(nova_lista, l2->item[k]);
            k++;
        }
    }
    return nova_lista;
}

int main(){

    LISTA* l = cria_lista_vazia();
    inserir(l, 50);
    inserir(l, 10);
    inserir(l, 30);
    inserir(l, 20);
    inserir(l, 100);

    LISTA* l2 = cria_lista_vazia();
//    l2 = inverter(l);
    inserir(l2, 5);
    inserir(l2, 1);
    inserir(l2, 3);
    inserir(l2, 2);

    LISTA* l3 = cria_lista_vazia();
//    l3 = concatenar(l, l2);
    l3 = intercalar(l, l2);
//  remover(l, 30);
    printf("Lista 1: ");
    imprimir(l);
    printf("\nLista 2: ");
    imprimir(l2);
    printf("\nLista 3: ");
    imprimir(l3);

    return 0;
}