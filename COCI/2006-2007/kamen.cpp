
//My solution is the same as in this link: 
//https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/Olympiad/COCI/official/2007/contest6_solutions/solutions.pdf

#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef pair < int, int > ii;

const int maxr = 30010, maxn = 1e5+10, inf = 1e9;

int r, c, n;
char mat[maxr][35];

vector < ii > path[35];

void dfs(int row, int col, int p, int mod)
{
	if(mod) path[p].pb({row, col});

	if(row == r or mat[row+1][col] == 'X') return;
	
	if(mat[row+1][col] == '.')
	{
		dfs(row+1, col, p, 1);
		return;
	}

	if(col != 1 and mat[row][col-1] == '.' and mat[row+1][col-1] == '.')
	{
		dfs(row+1, col-1, p, 1);
		return;
	}

	if(col != c and mat[row][col+1] == '.' and mat[row+1][col+1] == '.')
	{
		dfs(row+1, col+1, p, 1);
		return;	
	}
	return;
}

int main()
{
	cin >> r >> c;

	for(int i = 1 ; i <= r ; i++)
	{
		for(int j = 1 ; j <= c ; j++)
		{
			cin >> mat[i][j];
		}
	}

	for(int i = 1 ; i <= c ; i++)
	{
		dfs(1, i, i, 1);
	}

	cin >> n;

	for(int i = 0 ; i < n ; i++)
	{
		int a;
		cin >> a;

		ii ult = path[a][path[a].size()-1];
		//cout << ult.first << ' ' << ult.second << endl;
		mat[ult.first][ult.second] = 'O';
		
		for(int j = 1 ; j <= c ; j++)
		{
			ii k = path[j][path[j].size()-1];
			
			if(ult == k)
			{
				path[j].pop_back();

				ii aux = path[j][path[j].size()-1];

				dfs(aux.first, aux.second, j, 0);
			}
		}

	}

	for(int i = 1 ; i <= r ; i++)
	{
		for(int j = 1 ; j <= c ; j++)
		{
			cout << mat[i][j];
		}
		cout << "\n";
	}
}
