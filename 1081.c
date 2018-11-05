#include <stdio.h> 
#include <stdlib.h>

#define MAX 20
#define ESPACO 2

int matrizAdj[MAX][MAX];
int vetorVisitados[MAX];

void inicializar(int vertices){
    int i, j;
    for (i = 0; i < vertices; i++){
        vetorVisitados[i] = 0;
        for (j = 0; j < vertices; j++){
            matrizAdj[i][j] = 0;
        }
    }
    return;
}
void preencherMatriz(int arestas){
    int a, b;
    while (arestas--){
        scanf("%d %d", &a, &b);
        matrizAdj[a][b] = 1;
    }
    return;
}
void executarDFS(int vertices) {
    int i, v = 0;
 
    while (1) {
        if (DFS(v, vertices, ESPACO)){
            puts("");
        }
        v = -1;
        for (i = 0; i < vertices; i++) {
            if (!vetorVisitados[i]) {
                v = i;
                break;
            }
        }
        if (v == -1){
            break;
        }
    }
}
int DFS(int v, int vertices, int tString) {
    int i, j;
    int caminho = 0;
 
    vetorVisitados[v] = 1;
     for (i = 0; i < vertices; i++){
        if (matrizAdj[v][i] == 1){
            caminho = 1;
            if (vetorVisitados[i] == 0){
                for (j = 0; j < tString; j++){
                    printf(" ");
                }
                printf("%d-%d pathR(G,%d)\n", v, i, i);
                DFS(i, vertices, tString + ESPACO);
            }
            else{
                for (j = 0; j < tString; j++){
                    printf(" ");
                }
                printf("%d-%d\n", v, i);
            }
        }
    }
    return caminho;
}
int main(int argc, char const *argv[])
{
    int n, vertices, arestas;
    int caso = 1;
    scanf("%d", &n);
    while (n--){
        scanf("%d %d", &vertices, &arestas);
        // inicializa vetor e matriz de adjacencias n x n
        inicializar(vertices);
        // preenchendo dependencias existentes
        preencherMatriz(arestas);
        // busca em profundidade (DFS)
        printf("Caso %d:\n", caso++);
        executarDFS(vertices);
    }
    return 0;
}