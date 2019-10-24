//COI 2015 - Final Exam 2 - Task Nafta
//Sofhia de Souza Gonçalves

#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int maxn = 2e3+10, inf = 0x3f3f3f3f;

int r, s, val[maxn], cst[2000010], vet1[4] = {0, 0, 1, -1}, vet2[4] = {1, -1, 0, 0};
int dentro[maxn][maxn], fora[maxn][maxn];
int dp[maxn][maxn], opt[maxn], resp, ini[maxn], fim[maxn];

bool vist[maxn][maxn];

char mat[maxn][maxn];

vector < int > c[2000010];

void dfs(int x, int y, int comp)
{
	ini[comp] = min(ini[comp], y);
	fim[comp] = max(fim[comp], y);
	
	if(val[y] < comp)
	{
		val[y] = comp;
		c[comp].pb(y);
	}

	vist[x][y] = 1;

	cst[comp] += mat[x][y] - '0';

	for(int i = 0 ; i < 4 ; i++)
	{
		int x1 = x+vet1[i];
		int y1 = y+vet2[i];
		if(x1 > 0 and x1 <= r and y1 > 0 and y1 <= s and !vist[x1][y1] and mat[x1][y1] != '.') dfs(x1, y1, comp);
	}
}

void solve(int qtd, int l, int r)
{
	if(l > r) return;

	int meio = (l+r) >> 1;

	for(int i = opt[l-1] ; i <= min(meio-1, opt[r+1]) ; i++)
	{
		if(dp[qtd][meio] < dp[qtd-1][i] + fora[i][meio])
		{
			dp[qtd][meio] = dp[qtd-1][i] + fora[i][meio];	
			opt[meio] = i;
		}
	}

	resp = max(resp, dp[qtd][meio]);

	solve(qtd, l, meio-1);
	solve(qtd, meio+1, r);
}

int main()
{
	cin >> r >> s;

	memset(vist, false, sizeof vist);

	for(int i = 1 ; i <= r ; i++)
	{
		for(int j = 1 ; j <= s ; j++)
		{
			cin >> mat[i][j];
		}
	}

	int cont = 0;
	for(int j = 1 ; j <= s ; j++)
	{
		for(int i = 1 ; i <= r ; i++)
		{
			if(mat[i][j] != '.' and !vist[i][j])
			{
				ini[++cont] = inf, fim[cont] = 0;
				dfs(i, j, cont);
			}
		}
	}

	for(int i = 1 ; i <= cont ; i++)
	{
		for(int j = ini[i] ; j <= fim[i] ; j++)
		{
			dentro[ini[i]][j] += cst[i];
			dp[1][j] += cst[i];
			resp = max(resp, dp[1][j]);
		}
	}

	for(int j = 1 ; j <= s ; j++)
	{
		for(int i = j-1 ; i > 0 ; i--)
		{
			fora[i][j] = fora[i+1][j] + dentro[i+1][j];
		}
	}
		
	cout << resp << "\n";

	opt[0] = 1;
	opt[s+1] = s;

	for(int qtd = 2 ; qtd <= s ; qtd++)
	{
		resp = 0;
		solve(qtd, 1, s);
		cout << resp << "\n";
	}	
}
