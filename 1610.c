#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    int valor;
    struct no *prox;
} tipoNo;
 
tipoNo * lista[10001];

tipoNo *criaNo (int valor) {
    tipoNo *novoNo = NULL;
    novoNo = (tipoNo*) malloc(sizeof(tipoNo));
    novoNo->valor = valor;
    novoNo->prox = NULL;
    return novoNo;
}
 
void insereFim (tipoNo **lista, int valor) {
    tipoNo *novo_No = criaNo(valor);
    tipoNo *aux;
 
    if (*lista == NULL) *lista=novo_No;
    else {
        aux = *lista;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
    aux->prox = novo_No;
    }
}
 
void adicionaVertice ( int v, int w ) {
    insereFim (&lista[v], w);
}

int verificaCadaCiclo (int v, int visited[], int pilha[]) {
    if (visited[v] == 0) {
        visited[v] = 1;
        pilha[v] = 1;
    }

    while ( lista[v] != NULL ) {
        if (!visited[lista[v]->valor] && verificaCadaCiclo(lista[v]->valor, visited, pilha))
            return 1;
        else if (pilha[lista[v]->valor])
            return 1;
        lista[v] = lista[v]->prox;
    }
    pilha[v] = 0;
    return 0;
}

int verificaCiclo(int tam) {
    int i;
    int visited[10001];
    int pilha[10001];
    memset (visited, 0, sizeof(visited));
    memset (pilha, 0, sizeof(pilha));
 
    for ( i=0; i < tam; i++ )
        if (verificaCadaCiclo(i, visited, pilha))
        return 1;
 
    return 0;
}
 
int main(int argc, char *argv[]) {
    int T, X, M, A, B;
    scanf ("%d", &T );
    while (T--) {
        scanf ("%d %d", &X, &M );
        int i;

        for (i = 0; i <= X; i++)
            lista[i] = NULL;

        while (M--) {
            scanf("%d %d", &A, &B);
            adicionaVertice(A, B);
        }

        if (verificaCiclo(X + 1))
            puts ("SIM");
        else
            puts ("NAO");
    }
 
    return 0;
}
