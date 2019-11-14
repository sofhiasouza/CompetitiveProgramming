//Seletiva IOI 2016 - Day 1- Energia
//Sofhia de Souza Gonçalves

#include <bits/stdc++.h>
#define pb push_back
#define S second
#define F first
using namespace std;
typedef pair < int, int > ii;
typedef pair < int , ii > iii;

const int maxn = 3e5+10, maxm = 6e5+10;

int n, m, val[maxn], tempo[maxm], cont, comp[maxn], peso[maxn];

vector < iii > vet;
vector < ii > vs[maxn], comp_val[maxn];

int find(int x)
{
	if(comp[x] == x) return x;
	return comp[x] = find(comp[x]);
}

void join(int a, int b)
{
	a = find(a);
	b = find(b);

	if(a == b) return;

	if(peso[a] < peso[b]) swap(a, b);

	comp_val[a].pb({cont, comp_val[a][comp_val[a].size()-1].S+comp_val[b][comp_val[b].size()-1].S});

	comp[b] = a;
	peso[a] += peso[b];

	vs[b].pb({cont, comp[b]});

}

int busca(int v)
{
	int ini = 0, fim = vet.size()-1;
	int resp = -1;

	while(ini <= fim)
	{
		int meio = (ini+fim)/2;
		int aux = vet[meio].F;

		if(aux <= v)
		{
			resp = meio;
			ini = meio+1;
		}
		else fim = meio-1;
	}

	return resp;
}

int busca2(int u, int t)
{
	int ini = 0, fim = vs[u].size()-1;
	int resp;

	while(ini <= fim)
	{
		int meio = (ini+fim)/2;

		if(vs[u][meio].F <= t)
		{
			resp = vs[u][meio].S;
			ini = meio+1;
		}
		else fim = meio-1;
	}

	return resp;
}

int busca3(int c, int t)
{
	int ini = 0, fim = comp_val[c].size() - 1;
	int resp;

	while(ini <= fim)
	{
		int meio = (ini+fim)/2;
		if(comp_val[c][meio].F <= t)
		{
			resp = comp_val[c][meio].S;
			ini = meio+1;
		}
		else fim = meio-1;
	}

	return resp;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;

	for(int i = 1 ; i <= n ; i++)
	{
		cin >> val[i];
		comp[i] = i;
		peso[i] = 1;
		comp_val[i].pb({0, val[i]});
		vs[i].pb({0, i});
	}

	for(int i = 1 ; i <= m ; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;

		vet.pb({w, {u, v}});
	}

	sort(vet.begin(), vet.end());

	int ante = 0;
	for(int i = 0 ; i < vet.size() ; i++)
	{
		int cst = vet[i].F;
		int a = vet[i].S.F, b = vet[i].S.S;
	
		if(cst != ante)
		{
			ante = cst;
			cont++;
		}
		tempo[i] = cont;

		join(a, b);
	}

	int q, resp = 0;
	cin >> q;

	while(q--)
	{
		int a, k;
		cin >> a >> k;

		k += resp;

		int t = busca(k);
		if(t == -1) t = 0;
		else t = tempo[t];
	
		int componente = a;
		while(1)
		{
			int z = componente;
			componente = busca2(componente, t);
			if(componente == z) break;
		}
		resp = busca3(componente, t);

		cout << resp << "\n";
	}
}
