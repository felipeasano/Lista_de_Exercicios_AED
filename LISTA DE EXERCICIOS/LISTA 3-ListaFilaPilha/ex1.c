#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// estrutura para NO da pilha
typedef struct no{
    float numero;
    struct no* prox;
}PILHA;

// verifica se pilha eh vazia
// retorna 1 se for vazia, 0 caso contrario
int vazia(PILHA *p){
    return (p == NULL);
}

// verifica se um caracter eh um numero
// retorna 1 se for numero, 0 caso contrario
int eh_numero(char c){
    int i;
    char temp = '0';
    for(i = 0; i < 10; i++){
        if(c == temp){
            return 1;
        }
        temp++;
    }
    return 0;
}

// verifica se um caractere de entrada eh um operado
// retorna 1 caso verdadeiro, 0 caso contrario
int eh_operador(char c){
    if(c == '+' || c == '-' || c == '*' || c == '/'){
        return 1;
    }
    return 0;
}

// realiza uma operacao matematica de acordo com o caractere passado
// '+' = soma, '-' = subtracao, '*' = multiplicacao, '/' = divisao
// retorna o resultado a operacao
float operacao(float x, float y, char operador){
    if(operador == '+') return x + y;
    if(operador == '-') return x - y;
    if(operador == '*') return x * y;
    if(operador == '/') return x / y;
}

// empilha um novo no contendo o ponto flutuante passado como parametro
// retorna a nova cabeca da pilha
PILHA* empilha(PILHA *p, float n){
    PILHA* nova = (PILHA*)malloc(sizeof(PILHA));
    nova->prox = p;
    nova->numero = n;
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
        printf("%.2f->", p->numero);
        imprime_pilha(p->prox);
    }
}

int main(){

    PILHA* p = NULL;
    char linha[100];
    char *c, *temp;
    float resultado, x1, x2;
    
    fgets(linha, sizeof(linha), stdin);
    c = strtok(linha, " ");

    while(c != NULL){
        if(eh_numero(c[0])){
            x1 = atof(c);
            p = empilha(p, x1);
        }
        if(eh_operador(c[0])){
            x1 = p->numero;
            p = desempilha(p);
            x2 = p->numero;
            p = desempilha(p);
            p = empilha(p, operacao(x1, x2, c[0]));
        }
        c = strtok(NULL, " ");
    }

    printf("Resultado = %.2f\n", p->numero);

    return 0;
}