//IOI 2004 PHIDIAS
//Code by Sofhia de Souza
//The solution is the same as in this link: https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/Olympiad/IOI/official/2004/phidias-sol.pdf

#include <bits/stdc++.h>
using namespace std;

const int maxn = 610, inf = 0x3f3f3f3f;

int w, h, n, dp[maxn][maxn];

int main()
{
	cin >> w >> h >> n;

	memset(dp, inf, sizeof dp);

	for(int i = 1 ; i <= n ; i++)
	{
		int a, b;
		cin >> a >> b;
		dp[a][b] = 0;
	}

	for(int i = 0 ; i <= w ; i++)
	{
		for(int j = 0 ; j <= h ; j++)
		{
			if(dp[i][j] == inf) dp[i][j] = i*j;
			for(int k = 1 ; k < i ; k++)
			{
				dp[i][j] = min(dp[i][j], dp[k][j]+dp[i-k][j]);
			}

			for(int k = 1 ; k < j ; k++)
			{
				dp[i][j] = min(dp[i][j], dp[i][k]+dp[i][j-k]);
			}
		}
	}

	cout << dp[w][h] << "\n";
}
