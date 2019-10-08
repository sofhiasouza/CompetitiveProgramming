/*
	COCI 2006 - BICIKLI
	Author: Sofhia de Souza Gonçalves

	Idea:
		- First, I do a dfs and mark in the array resp all the vertexs that are in some of the routes from 1 to 2.
		- After that, I do a kosaraju algorithm and verify if some of the cycles are made of just vertexs that are in some
		route from 1 to 2. If a cycle like that exists, than the answer is inf.
		- Else, I do a dfs and calculate the quantity of routes from 1 to 2.

*/

#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

const int maxn = 1e4+10, mod = 1e9;

int n, m, vist[maxn], resp[maxn], tempo, f = 0;

vector < int > grafo[maxn], grafo2[maxn], comp[maxn];

stack < int > pilha;

int dfs(int u)
{
	vist[u] = 1;

	if(u == 2) return resp[2] = 1;

	int flag = 0;

	for(int i = 0 ; i < grafo[u].size() ; i++)
	{
		int v = grafo[u][i];
		if(!vist[v])
		{
			int k = dfs(v);
			if(k) flag = 1;
		}
		else if(resp[v]) flag = 1;
	}

	pilha.push(u);

	return resp[u] = flag;
}

void dfs1(int u)
{
	vist[u] = 1;
	comp[tempo].pb(u);

	int flag = 0;

	for(int i = 0 ; i < grafo2[u].size() ; i++)
	{
		int v = grafo2[u][i];

		if(!vist[v]) dfs1(v);
	}
}

int dfs2(int u)
{
	if(u == 2) return 1;

	int cont = 0;

	for(int i = 0 ; i < grafo[u].size() ; i++)
	{
		int v = grafo[u][i];
		//cout << v << ' ' << vist[v] << ' ' << resp[v] << "\n";
		if(!vist[v] and resp[v])
		{
			cont += dfs2(v);
		}
		else if(resp[v]) cont += vist[v];

		if(cont > 1e9)
		{
			//cout << "mano\n";
			f = 1;
			cont %= mod;
			cont += mod;
		}
	}
	
	//cout << u << ' ' << cont << "\n";
	return vist[u] = cont;
}

int32_t main()
{
	cin >> n >> m;

	for(int i = 1 ; i <= m ; i++)
	{
		int a, b;
		cin >> a >> b;

		grafo[a].pb(b);
		grafo2[b].pb(a);	
	}

	dfs(1);

	memset(vist, 0, sizeof vist);

	tempo = 0;
	while(pilha.size())
	{
		int u = pilha.top();
		pilha.pop();

		if(!vist[u])
		{
			tempo++;
			dfs1(u);
		}
	}

	int flag = 0;

	for(int i = 1 ; i <= tempo ; i++)
	{
		int val = 0;
		for(int j = 0 ; j < comp[i].size() ; j++)
		{
			if(resp[comp[i][j]]) val++;
		}

		if(comp[i].size() > 1 and val == comp[i].size()) flag = 1;
	}

	if(flag) 
	{
		cout << "inf\n";
		return 0;
	}

	memset(vist, 0, sizeof vist);

	int t = dfs2(1);

	//cout << t <<' ' << f <<  "\n";

	if(!f) cout << t << "\n";
	else
	{
		t -= mod;

		string s;
		stringstream aux;
		aux << t;
		aux >> s;
	
		for(int i = 9 ; i > s.size() ; i--) cout << "0";
		cout << s << "\n";
	}

}
