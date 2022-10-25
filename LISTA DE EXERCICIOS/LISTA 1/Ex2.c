#include<stdio.h>

//Entrada: entra com um inteiro n
//Pre-condicao: nenhuma
//Pos-Condicao: imrprime de maneira decrescente de n-0
void PrintDecrescente(int n){

    printf("%d ", n);
    if(n == 0) return;
    PrintDecrescente(n-1);
}

int main(){

    int n;
    scanf("%d", &n);
    PrintDecrescente(n);
    return 0;
}