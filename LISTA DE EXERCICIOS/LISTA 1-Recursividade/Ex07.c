#include<stdio.h>
#include<string.h>


//Entrada: Entra com dois ponteiros pra char, um apontando pro comeco da string e outro apontando pro final
//Pre-Condicao: String existir e as entradas estarem de acordo com a string
//Pos-Condicao: Retorna 0 caso a string nao seja palindrome e 1 caso seja
int eh_palindrome(char* c, char* f){

    if(*c != *f) return 0;
    if(c >= f) return 1;
    else return eh_palindrome(c+1, f-1);

}

int main(){

    char *str;
    char *c;
    int tam;
    gets(str);
    c = str+strlen(str)-1;
    if(eh_palindrome(c, str)) printf("eh palindrome\n");
    else printf("nao eh palindrome\n");

    return 0;
}