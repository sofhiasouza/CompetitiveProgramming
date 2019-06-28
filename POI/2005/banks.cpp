
	/*
		Author: Sofhia de Souza Gonçalves
		
		Idea:
			-Idealize a directional graph where the bank with the key x go to bank x.
			-Count the quantity of components using union find (because the graph is directional)	
	
	*/



#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int maxn = 1e6+2;

int n, comp[maxn], cont, vist[maxn], vi[maxn];

vector < int > grafo[maxn];

int busca(int x)
{
	if(comp[x] == x) return x;
	return comp[x] = busca(comp[x]);
}

void join(int a, int b)
{
	if(comp[a] > comp[b]) swap(a, b);
	
	comp[busca(b)] = busca(a);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	for(int i = 1 ; i <= n ; i++) comp[i] = i;
	for(int i = 1 ; i <= n ; i++)
	{
		int a;
		cin >> a;
		join(a, i);
	}
	
	int resp = 0;
	for(int i = 1 ; i <= n ; i++)
	{
		if(!vist[busca(i)]) resp++;
		vist[comp[i]] = 1;
	}
	
	cout << resp << endl;
}
