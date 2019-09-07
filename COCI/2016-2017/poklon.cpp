//COCI 17-Poklon
//Code by Sofhia de Souza

#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int maxn = 2e6+10;

int n, cont, qtdz, val[maxn];

vector < int > grafo[1000010];
vector < bool >resp;

void dfs(int u, int niv)
{
	if(u > n or !(int)grafo[u].size())
	{
		vector < bool > aux;

		int flag = 0;
		for(int i = 31 ; i >= 0 ; i--)
		{
			if(val[u]&(1 << i))
			{
				flag = 1;
				aux.pb(1);
			}
			else if(flag) aux.pb(0);
		}

		if((int)aux.size()+niv > (int)resp.size()+qtdz)
		{
			resp.clear();
			qtdz = niv;
			for(int i = 0 ; i < (int)aux.size() ; i++) resp.pb(aux[i]);
		}
		else if((int)aux.size()+niv == (int)resp.size()+qtdz)
		{
			for(int i = 0 ; i < (int)aux.size() and i < (int)resp.size() ; i++)
			{
				if(resp[i] > aux[i]) return;
				else if(resp[i] < aux[i])
				{
					resp.clear();
					qtdz = niv;
					for(int j = 0 ; j < (int)aux.size() ; j++) resp.pb(aux[j]);
					return;
				}
			}
			if((int)aux.size() > (int)resp.size())
			{
				resp.clear();
				qtdz = niv;
				for(int j = 0 ; j < (int)aux.size() ; j++) resp.pb(aux[j]);
				return;
			}
		}

		return;
	}
	for(int i = 0 ; i < (int)grafo[u].size() ; i++)
	{
		dfs(grafo[u][i], niv+1);
	}
	grafo[u].clear();
}

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;

	cont = n;
	for(int i = 1 ; i <= n ; i++)
	{
		int a, b;
		cin >> a >> b;
	
		if(a < 0)
		{
			cont++;
			val[cont] = a*(-1);
			grafo[i].pb(cont);
		}
		else grafo[i].pb(a);

		if(b < 0)
		{
			cont++;
			val[cont] = b*(-1);
			grafo[i].pb(cont);
		}
		else grafo[i].pb(b);
	}

	dfs(1, 0);

	for(int i = 0 ; i < (int)resp.size() ; i++) cout << resp[i];
	for(int i = 0 ; i < qtdz ; i++) cout << 0;
	cout << "\n";
}
