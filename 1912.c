#include <stdio.h>

int main() {
    int tira, areaTira, i, aux;
    int somaArea = 0, tamTira = 0; 
    int qtdTira[10010];
    float aux2;
    
    scanf("%d %d", &tira, &areaTira);
    
    while(tira != 0 && areaTira != 0){
        for (i = 0; i < 10010; i++) 
        	qtdTira[i] = 0;

        for (i = 0; i < tira; i++) {
            scanf("%d", &aux);
            qtdTira[aux]++;
            
            if (aux > tamTira)
            	tamTira = aux;
        }

        for (i = tamTira-1; i > 0; i--) 
        	qtdTira[i] += qtdTira[i+1];

        i = tamTira;
        while ((somaArea + qtdTira[i] <= areaTira) && (i > 0)) {
            somaArea += qtdTira[i];
            i--;
        }

        if (somaArea == areaTira) {
                if (i == 0) 
                	printf(":D\n");
                else 
                	printf("%.4lf\n", (float)i);
        } else {
            if (i == 0)
                printf("-.-\n");
            else {
                aux2 = (float)(areaTira - somaArea)/qtdTira[i];
                printf("%.4lf\n", i - aux2);
            }
        }
        
        tamTira = 0;
        somaArea = 0;
        scanf("%d %d", &tira, &areaTira);
    }
    
    return 0;
}