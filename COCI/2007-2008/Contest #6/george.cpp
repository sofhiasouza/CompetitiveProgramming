
	/*
		The solution is like in this link: https://github.com/mostafa-saad/MyCompetitiveProgramming/tree/master/Olympiad/COCI/official/2008/contest6_solutions	
	*/


#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef pair < int, int > ii;

const int maxn = 1e3+10, maxm = 1e4+10;

int n, m, a, b, k, g, vet[maxn], arest[maxn][maxn], val[maxm], vist[maxn];
ii inter[maxm];

vector < ii > grafo[maxn];

int dijkstra()
{
	priority_queue < ii, vector < ii >, greater < ii > > fila;
	
	fila.push({k, a});
	
	while(fila.size())
	{
		ii x = fila.top();
		fila.pop();
		int u = x.second;
		int time = x.first;
	
		if(u == b) return time;
		if(vist[u]) continue;
		vist[u] = 1;
		
		for(int i = 0 ; i < grafo[u].size() ; i++)
		{
			ii w = grafo[u][i];
			int v = w.first;
			int c = w.second;
			int ar = arest[u][v];
			
			if(inter[ar].first > time or inter[ar].second < time) fila.push({time+c, v});
			else fila.push({inter[ar].second+c+1, v});
		}
	}
}

int main()
{
	cin >> n >> m;
	cin >> a >> b >> k >> g;
	
	for(int i = 0 ; i < g ; i++)
	{
		cin >> vet[i];
	}		
	
	for(int i = 1 ; i <= m ; i++)
	{
		int x, y, l;
		cin >> x >> y >> l;
		
		grafo[x].pb({y, l});
		grafo[y].pb({x, l});
		
		val[i] = l;
		
		arest[x][y] = i;
		arest[y][x] = i;
	}
	
	int cont = 0;
	for(int i = 1 ; i < g ; i++)
	{
		int x = vet[i-1], y = vet[i];
		inter[arest[x][y]] = {cont, cont+val[arest[x][y]]-1};
		cont += val[arest[x][y]];
	}
	
	int resp = dijkstra() - k;			

	cout << resp << endl;
}
