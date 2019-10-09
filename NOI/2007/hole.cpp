/*
	NOI 2007 - HOLE
	Author: Sofhia de Souza Gonçalves
	Idea:
		-I save int the array mat the values, 1 or 0. Than, I have 3 other arrays: 
			-row[x][y], that keeps the max of 0 that exists starting from (x, y) and go to the right int the same row; 
			-col[x][y], that keeps the max of 0 that exists starting from (x, y) and go to the right int the same colum;
			-dp[x][y], that keeps the bigger rectangle that exists, where the topmost and leftmost vertice is in (x, y) and
			lowermost and rightmost vertex is in (x+dp[x][y].first, y+dp[x][y].second)
		-For each cell:
			-row[i][j] = row[i][j+1]+1;
			-col[i][j] = col[i+1][j]+1;
			-dp[i][j].first = min(col[i+1][j], dp[i+1][j+1].first)+1;
			-dp[i][j].second = min(row[i][j+1], dp[i+1][j+1].second)+1;
		-The answer will be the min of all the dp[i][j].first and dp[i][j].second.


*/

#include <bits/stdc++.h>
using namespace std;
typedef pair < int, int > ii;

const int maxn = 1e3 + 30;

int n, k, mat[maxn][maxn], row[maxn][maxn], col[maxn][maxn];
ii dp[maxn][maxn];

int main()
{
	cin >> n >> k;

	for(int i = 1 ; i <= k ; i++)
	{
		int x, y;
		cin >> x >> y;
		mat[x][y] = 1;
	}

	int resp = 0;
	for(int i = n-1 ; i >= 0 ; i--)
	{
		for(int j = n-1 ; j >= 0 ; j--)
		{
			if(mat[i][j] == 1) dp[i][j].first = dp[i][j].second = row[i][j] = col[i][j] = 0;
			else if(i == n-1 or j == n-1 or mat[i][j+1] == 1 or mat[i+1][j] == 1 or mat[i+1][j+1] == 1) dp[i][j].first = dp[i][j].second = row[i][j] = col[i][j] = 1;
			else
			{
				row[i][j] = row[i][j+1]+1;
				col[i][j] = col[i+1][j]+1;
				dp[i][j].first = min(col[i+1][j], dp[i+1][j+1].first)+1;
				dp[i][j].second = min(row[i][j+1], dp[i+1][j+1].second)+1;
			}
			resp = max(resp, min(dp[i][j].first, dp[i][j].second));
		}
	}

	cout << resp << "\n";
}
