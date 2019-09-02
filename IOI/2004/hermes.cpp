/*
  IOI 2004 Hermes
  Code by Sofhia de Souza
  Idea:
   
    -I did a dp[i][j][k], where i is the god i, k is 0 if I'm in the x-coordenate of god i and is 1 if I'm in the y-coordenate
    of god i, and j is the other coordenate that I'm now (if k = 0, j represents the y coordenate, and if k = 1, j represents
    the x coordenate). With this, I can calculate all the possibilities (using memory trick, because of the memory limit), and
    then I just need to print the best of the last god.
*/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e4+10, maxm = 2e3+10, inf = 0x3f3f3f3f;

int n, x[maxn], y[maxn];
long long int dp[2][maxm][2];

int main()
{
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
	{
		int a, b;
		cin >> a >> b;

		x[i] = a+1000;
		y[i] = b+1000;
	}

	memset(dp, inf, sizeof dp);

	x[0] = y[0] = 1000;

	dp[0][1000][0] = dp[0][1000][1] = 0;

	int mod = 0;
	
	//0 = x fixado, 1 = y fixado
	for(int i = 0 ; i < n ; i++)
	{
		memset(dp[mod^1], inf, sizeof dp[mod^1]);
		for(int j = 0 ; j < maxm ; j++)
		{
			dp[mod^1][j][0] = min(dp[mod^1][j][0], dp[mod][j][0]+abs(x[i]-x[i+1]));
			dp[mod^1][x[i]][1] = min(dp[mod^1][x[i]][1], dp[mod][j][0]+abs(j-y[i+1]));
		
			dp[mod^1][j][1] = min(dp[mod^1][j][1], dp[mod][j][1]+abs(y[i]-y[i+1]));
			dp[mod^1][y[i]][0] = min(dp[mod^1][y[i]][0], dp[mod][j][1]+abs(j-x[i+1]));
		}
		mod ^= 1;
	}


	long long int resp = inf;
	for(int i = 0 ; i < maxm ; i++)
	{
		resp = min(resp, dp[mod][i][0]);
		resp = min(resp, dp[mod][i][1]);
	}

	cout << resp << "\n";
}
