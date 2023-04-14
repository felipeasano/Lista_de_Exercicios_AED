#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// estrutura para NO da pilha
typedef struct no{
    char c;
    struct no* prox;
}PILHA;

// verifica se pilha eh vazia
// retorna 1 se for vazia, 0 caso contrario
int vazia(PILHA *p){
    return (p == NULL);
}

// empilha um novo no contendo o ponto flutuante passado como parametro
// retorna a nova cabeca da pilha
PILHA* empilha(PILHA *p, char c){
    PILHA* nova = (PILHA*)malloc(sizeof(PILHA));
    nova->prox = p;
    nova->c = c;
    return nova;
}

// desempilha o ultimo no inserido na pilha
// retorna a nova cabeca da pilha
PILHA* desempilha(PILHA* p){
    PILHA* nova = p;
    p = p->prox;
    free(nova);
    return p;
}

// imprime o conteudo da pilha
// retorno = nenhum
void imprime_pilha(PILHA* p){
    if(!vazia(p)) {
        printf("%.2f->", p->c);
        imprime_pilha(p->prox);
    }
}

int main(){

    char linha[100];
    PILHA* p = NULL;

    fgets(linha, sizeof(linha), stdin);
    for(int i = 0; linha[i] != '\0'; i++){

        if(linha[i] == '('){
            p = empilha(p, '(');
        }
        if(linha[i] == ')'){
            p = desempilha(p);
        }
    }

    if(vazia(p)){
        printf("Expressao Balanceada\n");
    }else{
        printf("Expressao Desbalanceada\n");
    }

    return 0;
}