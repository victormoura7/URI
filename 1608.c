#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int qSortCrescente(const void *a, const void *b) {
    if (*(int*)a == *(int*)b)
        return 0;
    else {
        if (*(int*)a < *(int*)b)
            return -1;
        else
            return 1;
    }
}


int main(){
    int i, j, k;
    int T, D, I, B, Q;
    int ingrediente, qtdIngrediente;

    scanf("%i", &T);
    
    for(i=0; i < T; i++) {
        scanf("%i %i %i", &D, &I, &B);
          
        int preco[I];
        int custoBolo[B];
        memset(custoBolo,0,sizeof(custoBolo)); 
          
        for(j=0; j < I; j++) {
            scanf("%i", &preco[j]);
        }
        
        for(j=0;j < B; j++){
            scanf("%i", &Q);
            for(k=0; k < Q; k++){
                scanf("%i %i", &ingrediente, &qtdIngrediente);
                custoBolo[j] += preco[ingrediente]*qtdIngrediente;
            }
        }

        qsort(custoBolo, B, sizeof(int), qSortCrescente);
        printf("%i\n", D/custoBolo[0]);
    }
    return 0;
}