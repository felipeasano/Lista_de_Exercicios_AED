#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int info;
    struct no* prox;
}Lista;

int vazia(Lista *l){
    return (l == NULL);
}

int main(){

    return 0;
}