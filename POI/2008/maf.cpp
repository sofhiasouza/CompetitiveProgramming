/*

POI 08 - MAFIA
Author: Sofhia de Souza Gonçalves
Idea:

	-To calculate the minimun of deaths, I will always go first to the vertexs that don't have an ancestor alive. When I'm in a vertex,
	I kill its child (if it is alive) and, if the child of my child is alive, wasn't visited yet and don't have an ancestor alive, I 
	put it in the queue of vertexs without an ancestor and visit them. When I don't have a vertex without ancestors, I go to the vertexs
	that don't have been visited yet and do the same thing.

	-To calculate the maximum of deaths, I call a simple dfs to all the vertexs that don't have an ancestor first, and I count the 
	quantity of descendents that don't have been visited yet (all of them will be killed). The cases where a vertex kill himself is 
	trated separately. After, I call the same dfs and do the same thing for the vertexs that don't have been visited until the time it 
	is verificated.

*/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6+10;

int n, grafo[maxn], pai[maxn], p[maxn], vist[maxn], morto[maxn];

int dfs(int u)
{
	vist[u] = 1;

	int v = grafo[u];

	if(vist[v]) return 0;

	return dfs(v) + 1;
}

int main()
{
	cin >> n;

	for(int i = 1 ; i <= n ; i++)
	{
		cin >> grafo[i];
		pai[grafo[i]]++;
		p[grafo[i]] = 1;
	}

	queue < int > fila;

	for(int i = 1 ; i <= n ; i++)
	{
		if(!pai[i]) fila.push(i);
	}

	int cont = 0, r = 1, resp = 0;

	while(cont < n)
	{
		while(fila.size())
		{
			int u = fila.front();
			fila.pop();

			if(vist[u]) continue;

			vist[u] = 1;
			cont++;

			int v = grafo[u];
			if(morto[v]) continue;

			if(!vist[v]) cont++;
			vist[v] = morto[v] = 1;
			resp++;

			pai[grafo[v]]--;
			if(!vist[grafo[v]] and !pai[grafo[v]] and !morto[grafo[v]]) fila.push(grafo[v]);
		}


		for(int i = r ; i <= n ; i++)
		{
			r++;
			if(i == grafo[i] and !vist[i] and !morto[i])
			{
				resp++;
				vist[i] = morto[i] = 1;
				cont++;
				continue;
			}
			if(!vist[i] and !morto[i])
			{
				vist[i] = 1;
				cont++;
				int v = grafo[i];

				if(morto[v]) continue;

				if(!vist[v]) cont++;	
				vist[v] = morto[v] = 1;
				resp++;

				pai[grafo[v]]--;
				if(!vist[grafo[v]] and !pai[grafo[v]] and !morto[grafo[v]])
				{
					fila.push(grafo[v]);
					break;
				}
			}
		}
	}

	cout << resp << " ";

	int resp2 = 0;

	memset(vist, 0, sizeof vist);

	for(int i = 1 ; i <= n ; i++)
	{
		if(!p[i]) resp2 += dfs(i);
	}

	for(int i = 1 ; i <= n ; i++)
	{
		if(!vist[i])
		{
			if(grafo[i] == i)
			{
				vist[i] = 1;
				resp2++;
				continue;
			}
			else resp2 += dfs(i);
		}
	}

	cout << resp2 << "\n";
}
