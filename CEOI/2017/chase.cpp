/*

	Author: Sofhia de Souza Gonçalves

	Ideia:
		- I did a dp with two parameters x and y, the vertex and how many breadcrumbs I have. It keeps the biggest difference of 
		pigeons between Jerry and Tom from this vertex x to its children having y breadcrumbs. 
		- Do a dfs and calculate this dp for root = 1.
		- We need to do this for all the possible roots. However, it will give us a time limit. So, I do a spin trick, where I 
		change my root for one of my children and then I just have to change the dp of me and my child.
*/

#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long int ll;
 
const int maxn = 1e5+10;
 
vector < int > grafo[maxn];
 
int n, v, vet[maxn];
ll soma[maxn], dp[maxn][110], dp2[maxn][110], resp;
 
void dfs(int u, int pai)
{
	for(int i = 0 ; i < grafo[u].size() ; i++)
	{
		int k = grafo[u][i];
		if(k == pai) continue;
 
		dfs(k, u);
		for(int j = 1 ; j <= v ; j++)
		{
			ll val = max(dp[k][j-1] + soma[k] - vet[u], dp[k][j]);
 
			if(dp[u][j] < val) 
			{
				dp2[u][j] = dp[u][j];
				dp[u][j] = val;
			}
			else dp2[u][j] = max(dp2[u][j], val);
		}
	}
}
 
void rotate(int u, int pai)
{
	for(int i = 1 ; i <= v ; i++) resp = max({resp, dp[u][i-1] + soma[u], dp[u][i]});
 
	for(auto k : grafo[u])
	{
		ll d1[110];
 
		if(k == pai) continue;
		for(int i = 1 ; i <= v ; i++)
		{
			d1[i] = dp[u][i];
			
			if(dp[u][i] == dp[k][i] or dp[u][i] == dp[k][i-1] + soma[k] - vet[u]) dp[u][i] = dp2[u][i];
		}
 
		for(int i = 1 ; i <= v ; i++)
		{
			ll val = max(dp[u][i-1] + soma[u] - vet[k], dp[u][i]);
 
			if(dp[k][i] < val) 
			{
				dp2[k][i] = dp[k][i];
				dp[k][i] = val;
			}
			else dp2[k][i] = max(dp2[k][i], val);
		}
 
		rotate(k, u);
 
		for(int i = 1 ; i <= v ; i++) dp[u][i] = d1[i];
	}
}
 
int main()
{
	cin >> n >> v;
 
	for(int i = 1 ; i <= n ; i++) cin >> vet[i];
 
	for(int i = 0 ; i < n-1 ; i++)
	{
		int a, b;
 
		cin >> a >> b;
 
		grafo[a].pb(b);
		grafo[b].pb(a);
	}
 
	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = 0 ; j < grafo[i].size() ; j++)
		{
			soma[i] += vet[grafo[i][j]];
		}
	}
 
 
	dfs(1, 0);
	rotate(1, 0);
 
	cout << resp << endl;
}
