
/*
	The solution is the same as in this link: http://ioi2017.org/contest/practice/
*/


#include <bits/stdc++.h>
#include "mountains.h"
using namespace std;

const int maxn = 2020;

int dp[maxn][maxn], n, y[maxn], x[maxn];

long long int cross(int a, int b, int c)
{
	return (long long int)(x[b]-x[a])*(y[c]-y[a]) - (long long int)(y[b]-y[a])*(x[c]-x[a]);
}

int maximum_deevs(vector < int > vet)
{
	int n = vet.size();
	for(int i = 0 ; i < n ; i++)
	{
		x[i+1] = i+1;
		y[i+1] = vet[i];
	}

	for(int i = 1 ; i <= n ; i++)
	{
		dp[i][i] = dp[i-1][i] = 1;
		int ult = i-1, res = 0;

		for(int j = i-2 ; j > 0 ; j--)
		{
			if(cross(j, ult, i) >= 0)
			{
				res += dp[j+1][ult-1];
				ult = j; 
			}
			dp[j][i] = max(dp[j][i-1], 1+res+dp[j][ult-1]);
		}
	}
	return dp[1][n];
}
