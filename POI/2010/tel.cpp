//POI 2010 TELEPORT
//Code by Sofhia Souza
//Solution is the same as in this link: https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/Olympiad/POI/official/2010/editorial/tel.pdf

#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int maxn = 4e4+10, inf = 0x3f3f3f3f;

int n, m;

vector < int > vist1(maxn), vist2(maxn);

vector < int > grafo[maxn];

void bfs(int x, vector < int >  &vist)
{
	for(int i = 0 ; i <= n ; i++) vist[i] = inf;

	stack < int > pilha;
	pilha.push(x);

	vist[x] = 0;

	while(pilha.size())
	{
		int u = pilha.top();
		pilha.pop();

		for(int i = 0 ; i < grafo[u].size() ; i++)
		{
			int v = grafo[u][i];
			if(vist[v] == inf)
			{
				vist[v] = vist[u] + 1;
				if(vist[v] < 2) pilha.push(v);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie();
	
	cin >> n >> m;

	for(int i = 0 ; i < m ; i++)
	{
		int a, b;
		cin >> a >> b;
		grafo[a].pb(b);
		grafo[b].pb(a);
	}

	bfs(1, vist1);
	bfs(2, vist2);

	int a = 0, b = 0, c = 0, d = 0;

	for(int i = 3 ; i <= n ; i++)
	{
		if(vist1[i] == 1) a++;
		else if(vist1[i] == 2) b++;
	}

	for(int i = 3 ; i <= n ; i++)
	{
		if(vist2[i] == 1) c++;
		else if(vist2[i] == 2) d++;
	}

	ll resp = (ll)(n*(n-1))/2 - m - (n - 1 - a) - a*(1 + d + c) - b*(1 + c) - (n - 1 - c - 1 - a - b) - min(a, c) * (n - 1 - a - b - 1 - c - d);
	cout << resp << "\n";
}
