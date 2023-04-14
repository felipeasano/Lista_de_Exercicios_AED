#include<stdio.h>

//Entrada: entra com um inteiro n
//Pre-Condicao: nenhuma
//Pos-Condicao: retorna o somatorio de 0-n
int somatorio(int n){
    if(n == 0) return 0;
    return n + somatorio(n-1);
}

int main(){

    int n;
    scanf("%d", &n);
    printf("%d\n", somatorio(n));
    return 0;
}