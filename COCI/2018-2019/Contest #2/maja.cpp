
/*
	Author: Sofhia de Souza Gonçalves

	Idea:
		- I did a dp with 3 parameters: my row, my colum and the quantity of steps I already walked (quantity of steps <= 10^4).
		
		- This dp can give me a memory limit, so I optmizated, using just two colums for the third parameter (because to calculate
		dp[i][j][x], I just need values with the third parameter = x-1). 
		
		- If my k is smaller or equal to 10^4, I can just do my dp, traversing the matrix and returning the greater sum
		
		- If my k is greater than 10^4, I need to know what is the greater pair of fields that I visited in my path, and 
		then I will go and back between both of them until my k be just the enough to come back to the hive. So, I can do
		my dp normally, and after that I calculete how much times I will go and back in this pair, multiply this by the value
		of the pair and sum this to my answer.
		
		- dp[i][j][x] is a struct, where I have f = the sum of the fields and sf = value of the greater pair of fields that I
		visited until now.

*/



#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int maxn = 110, maxs = 1e4+10;

ll n, m, a, b, mat[maxn][maxn], k;

struct pt
{
	ll f;
	ll sf;

	bool operator > (const pt &k) const{
		if(f != k.f) return f > k.f;
		return sf >= k.sf;
	}	

}dp[maxn][maxn][2];

pt solve()
{
	int mod = 0;
	for(int t = 1 ; t <= min(k, (ll)10000) ; t++)
	{	
		mod ^= 1;
		for(int i = 1 ; i <= n ; i++)
		{
			for(int j = 1 ; j <= m ; j++)
			{
				if(dp[i-1][j][mod^1] > dp[i+1][j][mod^1] and dp[i-1][j][mod^1] > dp[i][j-1][mod^1] and dp[i-1][j][mod^1] > dp[i][j+1][mod^1])
				{
					dp[i][j][mod] = dp[i-1][j][mod^1];
					if(mat[i][j]+mat[i-1][j] > dp[i-1][j][mod^1].sf) dp[i][j][mod].sf = mat[i][j]+mat[i-1][j];
				}
				else if(dp[i+1][j][mod^1] > dp[i-1][j][mod^1] and dp[i+1][j][mod^1] > dp[i][j-1][mod^1] and dp[i+1][j][mod^1] > dp[i][j+1][mod^1])
				{
					dp[i][j][mod] = dp[i+1][j][mod^1];
					if(mat[i][j]+mat[i+1][j] > dp[i+1][j][mod^1].sf) dp[i][j][mod].sf = mat[i][j]+mat[i+1][j];
				}
				else if(dp[i][j-1][mod^1] > dp[i-1][j][mod^1] and dp[i][j-1][mod^1] > dp[i+1][j][mod^1] and dp[i][j-1][mod^1] > dp[i][j+1][mod^1])
				{
					dp[i][j][mod] = dp[i][j-1][mod^1];
					if(mat[i][j]+mat[i][j-1] > dp[i][j-1][mod^1].sf) dp[i][j][mod].sf = mat[i][j]+mat[i][j-1];
				}
				else
				{
					dp[i][j][mod] = dp[i][j+1][mod^1];
					if(mat[i][j]+mat[i][j+1] > dp[i][j+1][mod^1].sf) dp[i][j][mod].sf = mat[i][j]+mat[i][j+1];
				}

				if(dp[i][j][mod].f != -1) dp[i][j][mod].f += mat[i][j];
			}
		}
	}
	return dp[a][b][mod];
}

int main()
{
	cin >> n >> m >> a >> b >> k;

	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = 1 ; j <= m ; j++)
		{
			cin >> mat[i][j];
		}
	}

	memset(dp, -1, sizeof dp);
	dp[a][b][0].f = 0;

	pt resp = solve();
	//cout << resp.f << endl;
	if(k <= 10000) cout << resp.f << endl;
	else cout << (ll)resp.f + (ll)(resp.sf)*((ll)k-10000)/2 << endl;
}
