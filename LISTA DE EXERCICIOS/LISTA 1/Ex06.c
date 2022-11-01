#include<stdio.h>

int CalcCatalao(int n){

    if(n == 0) return 1;
    else return ((2*(2*(n-1)))/(n+1)) * CalcCatalao(n-1);
}

int main(){

    int n;
    scanf("%d", &n);
    printf("%d", CalcCatalao(n));
    return 0;
}