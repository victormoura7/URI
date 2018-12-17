#include <iostream>
   
using namespace std;
  
struct pedra{
    char tipo;
    int d;
};
  
int main() {
    int T, dist, distPedra, n, i, salto, numTestes;
    int max = 0;
    char tipo, aux;
    pedra p[100];
    
    scanf("%d", &T);
  
    for (numTestes = 1; numTestes <= T ; numTestes++) {
        scanf("%d %d", &n, &dist);
        
        for (i = 0; i < n; i++) {
  
            cin.ignore();
            cin >> tipo >> aux >> distPedra;
              
            p[i].tipo = tipo;
            p[i].d = distPedra;
        }
  
        int i = -1;
        while (i < n) {
            if (i == -1) {
                salto = p[0].d;
                i++;
  
                if (salto > max)
                    max = salto;
            } else if (p[i].tipo == 'S') {
  
                p[i].tipo = 'X';
  
                if (i + 1 == n) {
  
                    salto = dist - p[i].d;
                    if (salto > max)
                        max = salto;
                    break;
                } else {
                    if (p[i+1].tipo == 'B') {
                        salto = p[i+1].d - p[i].d;
                        i = i + 1;
                        if (salto > max)
                             max = salto;
                    }
                    else if (i + 2 == n) {
                        salto = dist - p[i].d;
                        i = i + 2;
  
                        if (salto > max)
                             max = salto;
                    } else {
                        salto = p[i+2].d - p[i].d;
                        i = i + 2;
  
                        if (salto > max)
                            max = salto;                        
                    }               
                }
            } else if (p[i].tipo == 'B') {
                if (i + 1 == n) {
                    salto = dist - p[i].d;
                    if (salto > max)
                        max = salto;
                    break;                    
                } else {
                    salto = p[i+1].d - p[i].d;
                    i++;
                    if (salto > max)
                        max = salto;
                }
            }
            if (salto > max)
                max = salto;
        }
  
        i = n;
        int saltoFinal = dist;
        while (i != -1) {
            if (i - 1 == -1) {
                salto = saltoFinal;
 
                if (p[0].tipo != 'X')
                    salto = p[0].d;

                if (salto > max)
                    max = salto;
  
                break;
            }
  
            if (p[i-1].tipo == 'B' || p[i-1].tipo == 'S') {
  
                salto = abs(saltoFinal - p[i-1].d);
                saltoFinal = p[i-1].d;

                i--;
            } else if (p[i-1].tipo == 'X') {
  
                i--;
            }
            if (salto > max)
                max = salto;
        }
        printf("Case %d: %d\n", numTestes, max);
        max = 0;
    }
   
    return 0;
}