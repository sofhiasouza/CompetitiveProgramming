//USACO 2017 - FEBRUARY - GOLD - Why Did the Cow Cross the Road II
//Sofhia de Souza Gonçalves

#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int maxn = 1e3+10, inf = 1e9;

int n, vet1[maxn], vet2[maxn], pos[maxn];
int dp[maxn][maxn];

vector < int > grafo[maxn];

int solve(int x, int l)
{
	if(x == n+1) return 0;
	if(dp[x][l] != -1) return dp[x][l];
	if(l > n) return dp[x][l] = 0;

	int p = -1, np;

	for(int i = 0 ; i < grafo[vet2[x]].size() ; i++)
	{
		if(grafo[vet2[x]][i] >= l)
		{
			p = solve(x+1, grafo[vet2[x]][i]+1) + 1;
			break;
		}
	}

	np = solve(x+1, l);

	return dp[x][l] = max(p, np);
}

int main()
{
	freopen("nocross.in", "r", stdin);
	freopen("nocross.out", "w", stdout);

	cin >> n;

	for(int i = 1 ; i <= n ; i++)
	{
		cin >> vet1[i];
		pos[vet1[i]] = i;
	}

	memset(dp, -1, sizeof dp);

	for(int i = 1 ; i <= n ; i++)
	{
		cin >> vet2[i];
	
		for(int j = vet2[i] ; j > 0 and j >= vet2[i]-4 ; j--)
		{
			grafo[vet2[i]].pb(pos[j]);
		}
		for(int j = vet2[i]+1 ; j <= n and j <= vet2[i]+4 ; j++)
		{
			grafo[vet2[i]].pb(pos[j]);
		}
	
		sort(grafo[vet2[i]].begin(), grafo[vet2[i]].end());
	}

	cout << solve(1, 1) << "\n";
}
