#include <stdlib.h>
#include <stdio.h>

int n;

int capacidade[100][600]; 
int peso[100];
int valor[100];

int probDaMochila(int i, int capacidad) {
  int resposta, a, b;
  if (i >= n || capacidad == 0)
    return 0;
  else if (capacidad < 0)
    return -123456789;
  else { 
    if (capacidade[i][capacidad] == -1) {
      a = valor[i] + probDaMochila(i, capacidad - peso[i]);
      capacidade[i][capacidad] = a;
    } else
      a = capacidade[i][capacidad];
    
    b = probDaMochila(i + 1, capacidad);
    
    if (a > b)
      resposta = a;
    else
      resposta = b;
  }
  
  capacidade[i][capacidad] = resposta;
  return resposta;
}



int main ( ) {
  int i, j, k, t, instancia, resposta;
  instancia = 1;

  scanf("%d %d", &n, &t);
  while(n != 0 && t != 0) {
    for (j = 0; j < 100; j++) {
      for (k = 0; k < 600; k++) {
          capacidade[j][k] = -1;
      }
    }
    
    for (i = 0; i < n; i++) {
      scanf("%d %d", &peso[i], &valor[i]);
    }
    
    resposta = probDaMochila(0, t);

    printf("Instancia %d\n", instancia);
    printf("%d\n\n", resposta);
    scanf("%d %d", &n, &t);
    
    instancia++;
  }
  
  return 0;
}