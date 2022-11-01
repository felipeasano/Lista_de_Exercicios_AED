#include<stdio.h>
#include<math.h>

//Entrada: entra com dois inteiros, o primeiro sera a base e o seugndo sera o expoente
//Pre-condicao: Nenhuma
//Pos-Condicao: Retorna a potencia de n elevado ao exp
int calculaPotencia(int n, int exp){

    if(exp == 1) return n;
    return n * (calculaPotencia(n, exp-1));
}

//Entrada: Entra com inteiro n
//Pre-Condicao: Nenhuma:
//Pos-Condicao: Retorna o FATORIAL EXPONENCIAL de n
int FatExp(int n){

    if(n == 1) return n;
    return calculaPotencia(n, FatExp(n-1));
}

int main(){

    int n;
    scanf("%d", &n);
    printf("%d ", FatExp(n));
    return 0;
}