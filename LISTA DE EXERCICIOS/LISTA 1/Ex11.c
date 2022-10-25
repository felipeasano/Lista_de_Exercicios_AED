#include<stdio.h>

int somaDig(int n){
    if(n == 0) return n;
    return (n%10) + somaDig(n/10);
}

int main(){

    int n;
    scanf("%d", &n);
    printf("%d", somaDig(n));
    return 0;
}