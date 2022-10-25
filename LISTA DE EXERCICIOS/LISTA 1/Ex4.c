#include<stdio.h>

//Entrada: Entra com um inteiro n
//Pre-Condicao: Nenhuma
//Pos-Condicao: Retorna o FATORIA de n
int calcFat(int n){
    if(n == 1) return n;
    return n * calcFat(n-1);
}

//Entrada: Entra com um inteiro n
//Pre-Condicao: Nenhuma
//Pos-Condicao: Retorna o SUPERFATORIAL de n
int calcSuperFat(int n){
    if(n == 1) return n;
    return calcFat(n) * calcFat(n-1);
}

int main(){

    int n;
    scanf("%d", &n);
    printf("%d ", calcSuperFat(n));
    return 0;
}