#include <iostream>
#include <bits/stdc++.h>
#define vi vector<int>
#define pb push_back

using namespace std;

struct aresta {
	int u,v;
	double W;
};

struct pont {
	double X, Y;
};

vi pai,tam;
int c, n, u, v, m;
vector<pont> p;
vector<aresta> a;
double resposta, W, X, Y;

bool cmp(aresta a, aresta b) {
	return a.W<b.W;
}

int id(int n) {
	return n!=pai[n] ? pai[n]=id(pai[n]) : pai[n];
}

void join(int u, int v) {
	u=id(u), v=id(v);
	if (tam[u] < tam[v])
		swap(u,v);

	pai[v]=u;
	tam[u]+=tam[v];
}

void init(int n) {
	tam = vi(n,1);
	pai.clear();
	for (int i=0; i < n; i++)
		pai.pb(i);
}

int main() {
	int i, j;

	for (cin >> c; c--;) {
		cin >> n;
		init(n + 1);

		for (i = 0; i < n; i++) {
			cin >> X >> Y;
			p.pb({X,Y});
			for (j = i-1; j >= 0; j--)
				a.pb({i,j,hypot(X-p[j].X,Y-p[j].Y)});
		}

		sort(a.begin(),a.end(),cmp);
		m = a.size(); resposta=0;

		for (i=0, j=0; (i < m) && (j < n-1); i++) {
			u = id(a[i].u), v=id(a[i].v), W=a[i].W;
			if (u != v) {
				join(u,v);
				j++;
				resposta+=W;
			}
		}
		resposta/=100.0;
		printf("%.2lf\n",resposta);
		p.clear(), a.clear();
	}
    return 0;
}