#include<stdio.h>

//Entrada: Entra com um inteiro
//Pre-condicao: nenhuma
//Pos-condicao: printa de 0-n e retorna n
int Print_Cresc(int n){

    if(n == 0){
        printf("%d ", n);
        return n;
    }else{
        Print_Cresc(n-1);
    }
    printf("%d ", n);
}

int main(){

    int n;
    scanf("%d", &n);

    n = Print_Cresc(n);
    return 0;
}