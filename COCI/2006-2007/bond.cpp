/*

	COCI 2006 - BOND
	Author: Sofhia de Souza Gonçalves
	Idea: https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/Olympiad/COCI/official/2007/contest1_solutions/solutions.pdf

*/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 22;
const double inf = 1e9;

int n;
double mat[maxn][maxn], dp[2][(1 << 20)+10];

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;

	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = 1 ; j <= n ; j++)
		{
			cin >> mat[i][j];
			mat[i][j] /= 100.0;
		}
	}

	int mod = 1;
	
	for(int i = 0 ; i < (1 << 19)+1 ; i++) dp[0][i] = dp[1][i] = inf;

	dp[1][0] = 1;
	
	for(int i = 1 ; i <= n ; i++)
	{
		mod ^= 1;
		for(int j = 0 ; j < (1 << n) ; j++)
		{
			int w =  __builtin_popcount(j);
			if(w >= i) continue;

			for(int k = 0 ; k < n ; k++)
			{
				if(dp[mod^1][j] != inf and ((1 << k)&j) == 0)
				{
					if(dp[mod][j|(1 << k)] == inf) dp[mod][j|(1 << k)] = dp[mod^1][j]*mat[i][k+1]; 
					else dp[mod][j|(1 << k)] = max(dp[mod][j|(1 << k)], dp[mod^1][j]*mat[i][k+1]);
				}
			}
		}
	}

	if(dp[mod][(1 << (n)) - 1] == inf) cout << 0 << "\n";
	else printf("%.6lf\n", (double)dp[mod][(1 << (n)) - 1]*100.0);
}
