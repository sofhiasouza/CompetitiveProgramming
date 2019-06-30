
	/*
		The solution is the same as in this link: https://github.com/mostafa-saad/MyCompetitiveProgramming/tree/master/Olympiad/POI/official/2016
	*/


#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3+10;

int n, m, vist[maxn][maxn];
int hor[maxn][maxn], vert[maxn][maxn], comp[maxn][maxn], ini[maxn][maxn], li[maxn*maxn], col[maxn*maxn];

bool ok(int i, int j, int pi, int pj)
{
	if(i > 0 and i <= n and j > 0 and j <= m and (i != pi or j != pj)) return true;
	return false;
}

void dfs(int i, int j, int pi, int pj)
{
	vist[i][j] = 1;
	comp[i][j] = comp[pi][pj];
	
	if(!hor[i-1][j] and ok(i-1, j, pi, pj))
	{
		if(vist[i-1][j]) hor[i-1][j] = 1;
		else dfs(i-1, j, i, j);
	}
	if(!hor[i][j] and ok(i+1, j, pi, pj))
	{
		if(vist[i+1][j]) hor[i][j] = 1;
		else dfs(i+1, j, i, j);
	}
	if(!vert[i][j] and ok(i, j+1, pi, pj))
	{
		if(vist[i][j+1]) vert[i][j] = 1;
		else dfs(i, j+1, i, j);
	}
	if(!vert[i][j-1] and ok(i, j-1, pi, pj))
	{
		if(vist[i][j-1]) vert[i][j-1] = 1;
		else dfs(i, j-1, i, j);
	}
}

int busca(int x)
{
	int i = li[x], j = col[x];
	if(comp[i][j] == ini[i][j]) return comp[i][j];
	return comp[i][j] = busca(comp[i][j]);
}

bool compara(int i, int j, int pi, int pj)
{
	if(busca(ini[i][j]) == busca(ini[pi][pj])) return true;
	return false;
}

void join(int i, int j, int pi, int pj)
{
	if(busca(ini[i][j]) > busca(ini[pi][pj]))
	{
		swap(i, pi);
		swap(j, pj);
	}
	int k = busca(ini[pi][pj]);
	comp[li[k]][col[k]] = busca(ini[i][j]);
}

void dfs2(int i, int j)
{
	vist[i][j] = 1;

	busca(ini[i][j]);

	if(hor[i-1][j] and ok(i-1, j, 0, 0))
	{
		if(!compara(i, j, i-1, j))
		{
			join(i, j, i-1, j);
			hor[i-1][j] = 0;
			dfs2(i-1, j);
		}
	}
	if(hor[i][j] and ok(i+1, j, 0, 0))
	{
		if(!compara(i, j, i+1, j))
		{
			join(i, j, i+1, j);
			hor[i][j] = 0;
			dfs2(i+1, j);
		}
	}
	if(vert[i][j] and ok(i, j+1, 0, 0))
	{
		if(!compara(i, j, i, j+1))
		{
			join(i, j, i, j+1);
			vert[i][j] = 0;
			dfs2(i, j+1);
		}
	}
	if(vert[i][j-1] and ok(i, j-1, 0, 0))
	{
		if(!compara(i, j, i, j-1))
		{
			join(i, j, i, j-1);
			vert[i][j-1] = 0;
			dfs2(i, j-1);
		}
	}
}

int main()
{
	cin >> n >> m;

	char mat[maxn][maxn], mat2[maxn][maxn];

	int cont = 0;
	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = 1 ; j <= m ; j++)
		{
			comp[i][j] = ini[i][j] = ++cont;
			li[cont] = i;
			col[cont] = j;
		}
	}

	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = 1 ; j < m ; j++)
		{
			char c;
			cin >> mat[i][j];

			c = mat[i][j];

			if(c == 'T') vert[i][j] = 0;
			else vert[i][j] = 1;
		}
	}

	for(int i = 1 ; i < n ; i++)
	{
		for(int j = 1 ; j <= m ; j++)
		{
			char c;
			cin >> mat2[i][j];

			c = mat2[i][j];

			if(c == 'T') hor[i][j] = 0;
			else hor[i][j] = 1;
		}
	}

	int quant = 0;
	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = 1 ; j <= m ; j++)
		{
			if(!vist[i][j])
			{
				dfs(i, j, i, j);
				quant++;
			}
		}
	}

	if(quant != 1)
	{
		memset(vist, 0, sizeof vist);
		for(int i = 1 ; i <= n ; i++)
		{
			for(int j = 1 ; j <= m ; j++)
			{
				if(!vist[i][j]) dfs2(i, j);
			}
		}
	}
	
	int c1 = 0, c2 = 0;
	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = 1 ; j < m ; j++)
		{
			if(vert[i][j] == 1)
			{
				c1++;
				if(mat[i][j] == 'C') c2++;
			}
		}
	}
	
	for(int i = 1 ; i < n ; i++)
	{
		for(int j = 1 ; j <= m ; j++)
		{
			if(hor[i][j] == 1)
			{
				c1++;
				if(mat2[i][j] == 'C') c2++;
			}
		}
	}

	cout << c1 << ' ' << c2 << endl; 
	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = 1 ; j < m ; j++)
		{
			if(vert[i][j] == 1) cout << 'Z';
			else cout << '.';
		}
		cout << endl;
	}
	for(int i = 1 ; i < n ; i++)
	{
		for(int j = 1 ; j <= m ; j++)
		{
			if(hor[i][j] == 1) cout << 'Z';
			else cout << '.';
		}
		cout << endl;
	}
}

