
/*
	Author: Sofhia de Souza Gonçalves

	Idea:
		-For each citizen, I do two dijkstras and one dfs:
			
			-The first dijktra calculate, for each vertice i that I found before visit B, the shortest distance between A and i,
			and the number of vertices that found i with the shortest distance in array sob[i], and returns the shortest 
			distance between A and B.
			
			-The second dijktra calculate, for each vertice i that I found before visit A, the shortest distance between B and i,
			and the number of vertices that found i with the shortest distance in array des[i],
			
			-The dfs checks for it vertice if it is in some shortest path between A and B, and marks it in the array ok[].
			
			-After that, for each vertice that is in some shortest path, I calculate the total number of shortest paths that it
			is in, doing cont[i] = sob[i]*des[i] (because sob[i] is the number of possible shortest paths that i can pass until A, and 
			sob[i] is the number of possible shortest paths that i can pass until B).
			
			-cont[A] is the total of paths, I add to the E of every vertice i cont/total.
		
		-Lastly, I check what is the greater E and print. 

*/



#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef pair < int, int > ii;

const int maxn = 5e3+10, maxm = 4e4+10, inf = 1e9;

int n, m, k, vist[maxn], total, sob[maxn], des[maxn], cont[maxn], ok[maxn], menor, minn[maxn];

double resp[maxn];

vector < int > grafo[maxn];

int bfs(int a, int b, int mod)
{
	priority_queue < ii, vector < ii >, greater < ii > > fila;
	memset(vist, 0, sizeof vist);
	fila.push({0, a});
	if(mod == 1) sob[a] = 1;
	else des[a] = 1;
	
	vist[a] = 1;
	while(fila.size())
	{
		int c = fila.top().first;
		int u = fila.top().second;
		fila.pop();
		
		if(u == b)
		{
			if(mod == 1) minn[u] = c;
			return c;
		}
		
		if(mod == 1) minn[u] = c;
		
		for(int i = 0 ; i < grafo[u].size() ; i++)
		{
			int v = grafo[u][i];
			if(!vist[v] or vist[v] == c+1)
			{
				if(!vist[v]) fila.push({c+1, v});
				vist[v] = c+1;
				if(mod == 1) sob[v]+=sob[u];
				else des[v] += des[u]; 
			}
		}
	}
}

int dfs(int a, int b, int c)
{
	if(c > menor or c > minn[a]) return 0;
	
	if(a == b)
	{
		ok[a] = 1;
		return 1;
	}
	
	vist[a] = 1;
	
	int maior = 0;
	for(int i = 0 ; i < grafo[a].size() ; i++)
	{
		int v = grafo[a][i];
		if(!vist[v]) maior = max(maior, dfs(v, b, c+1));
		else if(ok[v] and c+1 == minn[v]) maior = 1;
	}
	if(maior) ok[a] = 1;
	return maior;
}	

int main()
{
	cin >> n >> m;
	for(int i = 0 ; i < m ; i++)
	{
		int a, b;
		cin >> a >> b;
		
		grafo[a].pb(b);
		grafo[b].pb(a);
	}
	
	cin >> k;
	
	int maior = 0;
	for(int i = 0 ; i < k ; i++)
	{
		int a, b, total = 0;
		cin >> a >> b;

		memset(sob, 0, sizeof sob);
		memset(des, 0, sizeof des);
		memset(ok, 0, sizeof ok);
		memset(minn, inf, sizeof minn);
		
		menor = bfs(a, b, 1);
		bfs(b, a, 2);
		
		memset(vist, 0, sizeof vist);
		dfs(a, b, 0);
		
		for(int i = 0 ; i < n ; i++)
		{
			if(ok[i]) cont[i] = des[i]*sob[i];
			else cont[i] = 0;
		}
		
		total = cont[a];
		
		for(int i = 0 ; i < n ; i++)
		{
			resp[i] += (double)cont[i]/(double)total;
		
			if(resp[i] > resp[maior]) maior = i;
		}
	}
	cout << maior << endl;	
}
