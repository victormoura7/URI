#include <stdio.h>
#include <string.h>

#define MAX 500001

int retornaIndice(int n) {
    return n & (-n);
}

int indice[MAX];

int indiceRemove(int a) {
    int soma = 0;
    while(a > 0){
        soma += indice[a];
        a -= retornaIndice(a);
    }
    return soma;
}

void atualizaIndice(int a, int v) {
    while(a < MAX){
        indice[a] += v;
        a += retornaIndice(a);
    }
}

int main(){
    int n, x, i;
    scanf("%d", &n);
    memset(indice, 0, sizeof indice);
    for(i = 1; i <= n; i++) {
        scanf("%d", &x);
        printf("%d%s", (x - indiceRemove(x)), (i == n ? "\n" : " "));
        atualizaIndice(x, 1);
    }
    return 0;
}