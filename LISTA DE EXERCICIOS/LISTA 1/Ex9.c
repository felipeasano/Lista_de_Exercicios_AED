#include<stdio.h>

//Entrada: Entra com dois Valores inteiros a serem trocados
//Pre-condicao: Nenhuma;
//Pos-Condicao: Troca o valor das variaveis entre si
void trocaVal(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

//Entrada: Entra com um vetor e um ponteiro apontando pro fim do vetor
//Pre-Condicao: Vetor precisa estar preenchido e ponteiro ja apontar para o fim do vetor
//Pos-Condicao: o vetor termina invertido
void invertVet(int v[], int* fim){

    if(v > fim) return;
    trocaVal(v, fim);
    invertVet(v+1, fim-1);
}

int main(){

    int vet[10], i;
    int *aux;
    for(i = 0; i < 10; i++) {
        scanf("%d", &vet[i]);
    }
    aux = &vet[9];
    
    invertVet(vet, aux);

    for(i = 0; i < 10; i++) {
        printf("%d ", vet[i]);
    }
    return 0;
}