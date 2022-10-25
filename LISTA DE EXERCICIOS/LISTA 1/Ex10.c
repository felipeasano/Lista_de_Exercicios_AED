#include<stdio.h>

int calcArc(int m, int n){
    if(m == 0) return n+1;
    if(m > 0 && n == 0) return calcArc(m-1, 1);
    if(m > 0 && n > 0) return calcArc(m-1, calcArc(m, n-1));
}

int main(){

    int m, n;
    scanf("%d %d", &m, &n);
    printf("%d", calcArc(m, n));
    return 0;
}