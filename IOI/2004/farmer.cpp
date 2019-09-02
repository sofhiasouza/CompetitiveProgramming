//IOI 2004 Farmer
//Code by Sofhia de Souza
//Solution is the same as described in this link: https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/Olympiad/IOI/official/2004/farmer-sol.pdf

#include <bits/stdc++.h>
using namespace std;

const int maxm = 2010, maxq = 2e5, inf = 0x3f3f3f3f;

int q, m, k, fiel[maxm], strip[maxm], dp[2][maxq];

int main()
{
	cin >> q >> m >> k;

	for(int i = 1 ; i <= m ; i++)
	{
		cin >> fiel[i];
	}

	for(int i = 1 ; i <= k ; i++)
	{
		cin >> strip[i];
	}

	sort(strip+1, strip+k+1);
	reverse(strip+1, strip+k+1);

	memset(dp, -1, sizeof dp);

	dp[0][0] = dp[1][0] = 1;

	int mod = 0;
	for(int i = 1 ; i <= m ; i++)
	{
		mod ^= 1;
	  for(int j = 1 ; j <= q ; j++)
		{
			int pego, npego = dp[mod^1][j];
			
			if(fiel[i] <= j) pego = dp[mod^1][j-fiel[i]];
			else pego = 0;

			dp[mod][j] = max(pego, npego);  
		}
	}

	if(dp[mod][q] == 1) cout << q << "\n";
	else if(dp[mod][q] == 0) cout << q-1 << "\n";
	else
	{
		int fc = 0;
		for(int i = 1 ; i < q ; i++) if(dp[mod][i] == 1) fc = i;

		fc = q-fc;

		int cont = 0;
		for(int i = 1 ; i <= k ; i++)
		{
			if(fc > 0)
			{
				cont++;
				fc -= strip[i];
			}
		}

		cout << q-cont << "\n";
	}
}
