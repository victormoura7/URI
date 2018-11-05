#include <stdio.h>
#define MAX(a,b) ((a) > (b) ? a : b)

int main() {
	int i, j, k, n;
	int tam = 1e+3+35;
	int data[tam][tam];
	int soma[tam][tam];
	int bol[tam][tam][2];

	while(scanf("%d", &n) && n) {
		
		for(i=1; i<=n; i++) {
			for(j=1; j<=i; j++) {
				scanf("%d", &data[i][j]);
			}
		}

		for(i=1; i<=n; i++) {
			for(j=1; j<=i; j++) {
				soma[i][j]=(soma[i-1][j]+soma[i-1][j-1]-(i-2>=0?soma[i-2][j-1]:0))+data[i][j];
			}
		}

		int ans=0;
		
		for(i=1; i<=n; i++) {
			for(j=1; j<=n; j++)  {
				bol[i][j][0]=bol[i][j][1]=0;
			}
		}

		for(j=1; j<=n; j++) {
			for(i=j; i<=n; i++) {
				bol[i][j][0]=soma[i][j];
				bol[i][j][0]=MAX(bol[i][j][0], bol[i-1][j-1][1]+(soma[i][j]-soma[i-1][j-1]));
				ans=MAX(ans, bol[i][j][0]);
			}
			bol[n][j][1]=bol[n][j][0];
			
			for(i=n-1; i>=j; i--) {
				bol[i][j][1]=MAX(bol[i+1][j][1], bol[i][j][0]);
			}
		}
		printf("%d\n", ans);
	}
	
	return 0;
}