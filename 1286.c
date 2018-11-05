#include <stdlib.h>
#include <stdio.h>
 
typedef struct {
    int tempo;
    int qtdPizzas;
}Pedido;

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}
 
int main() {
    int n, p;
    Pedido pedidos[21];
    int array[21][31];
    
    scanf("%d", &n);
    while (n != 0) {
        scanf("%d", &p);
        int i;
        
        for (i = 1; i <= n; i++) {
            scanf("%d %d", &pedidos[i].tempo, &pedidos[i].qtdPizzas);
        }
        
        for (i = 0; i <= n; i++) {
            int j;
            for (j = 0; j <= p; j++) {
                if (i == 0 || j == 0)
                    array[i][j] = 0;
                else {
                    if (pedidos[i].qtdPizzas > j) {
                        array[i][j] = array[i - 1][j];
                    }
                    else {
                        int maiorPed = max(array[i - 1][j - pedidos[i].qtdPizzas] + pedidos[i].tempo, array[i - 1][j]);
                        array[i][j] = maiorPed;
                    }
                }
            }
        }
        printf("%d min.\n", array[n][p]);
        scanf("%d", &n);
    }
    
    return 0;
}