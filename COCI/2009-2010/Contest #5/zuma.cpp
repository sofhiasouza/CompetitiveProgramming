/*
	COCI 2009/2010 - Contest #5 - ZUMA
	Author: Sofhia de Souza Gonçalves
	Idea: https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/Olympiad/COCI/official/2010/contest5_solutions/solutions.pdf
	
*/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 110, inf = 0x3f3f3f3f;

int n, k, vet[maxn], dp[maxn][maxn][6];

int solve(int l, int r, int c)
{
	if(l > r) return 0;
	if(l == r) return k-1-c;

	if(dp[l][r][c] != -1) return dp[l][r][c]; 
	dp[l][r][c] = inf;

	if(c < k-1) dp[l][r][c] = solve(l, r, c+1) + 1;
	if(c == k-1) dp[l][r][c] = solve(l+1, r, 0);

	for(int i = l+1 ; i <= r ; i++)
	{
		if(vet[l] != vet[i]) continue;

		dp[l][r][c] = min(dp[l][r][c], solve(l+1, i-1, 0) + solve(i, r, min(c+1, k-1)));
	}

	return dp[l][r][c];
}

int main()
{
	cin >> n >> k;

	for(int i = 1 ; i <= n ; i++) cin >> vet[i];

	memset(dp, -1, sizeof dp);

	cout << solve(1, n, 0) << "\n";
}
