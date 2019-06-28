
/*

	Author: Sofhia de Souza Gonçalves

	Idea:
		- First, we see that, for two pieces a and b, the distance between them is 
			- abs(colum[a] -  colum[b]) if abs(colum[a] -  colum[b]) >= abs(row[a] -  row[b])
			- abs(row[a] -  row[b]) if abs(colum[a] -  colum[b]) < abs(row[a] -  row[b])

		-After we know that, we just need to know how many times -row[a], row[a], -colum[a] and colum[a] appear in the sum. To
		do that, we do a dp, where 
			-mat[i][j] = a
			-dp[i][j][0] = number of pieces b where (abs(colum[a] -  colum[b]) < abs(row[a] -  row[b])) and row[a] > row[b].
			-dp[i][j][1] = number of pieces b where (abs(colum[a] -  colum[b]) >= abs(row[a] -  row[b])) and colum[a] < colum[b].
			-dp[i][j][2] = number of pieces b where (abs(colum[a] -  colum[b]) < abs(row[a] -  row[b])) and row[a] < row[b].
			-dp[i][j][3] = number of pieces b where (abs(colum[a] -  colum[b]) >= abs(row[a] -  row[b])) and row[a] < row[b].

		-To calculate the dp, we need to use the 4 diagonals of each piece. E.g.,
			-dp[i][j][0] = dp[i-1][j][0] + diag[i][j][2] + diag[i+1][j+1][3] 

*/


#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int maxn = 1e3+10;

ll respm, resps;

int r, c, diag[maxn][maxn][6], dp[maxn][maxn][6];
char mat[maxn][maxn];

ll func(char x)
{
	for(int i = 1 ; i <= r ; i++)
	{
		for(int j = 1 ; j <= c ; j++)
		{
			diag[i][j][0] = diag[i-1][j-1][0];
			diag[i][j][1] = diag[i-1][j+1][1];
			
			if(mat[i][j] == x)
			{
				diag[i][j][0]++;
				diag[i][j][1]++;
			}
		}
	}

	for(int i = r ; i >= 1 ; i--)
	{
		for(int j = 1 ; j <= c ; j++)
		{
			diag[i][j][2] = diag[i+1][j-1][2];
			diag[i][j][3] = diag[i+1][j+1][3];
			if(mat[i][j] == x)
			{
				diag[i][j][2]++;
				diag[i][j][3]++;
			}
		}
	}

	for(int i = 1 ; i <= r ; i++)
	{
		for(int j = 1 ; j <= c ; j++)
		{
			dp[i][j][0] = dp[i-1][j][0];
			dp[i][j][0] += diag[i][j][0] + diag[i-1][j+1][1];
		}
	}

	for(int i = r ; i >= 1 ; i--)
	{
		for(int j = 1 ; j <= c ; j++)
		{
			dp[i][j][2] = dp[i+1][j][2];
			dp[i][j][2] += diag[i][j][2] + diag[i+1][j+1][3];
		}
	}

	for(int j = c ; j >= 1 ; j--)
	{
		for(int i = 1 ; i <= r ; i++)
		{
			dp[i][j][1] = dp[i][j+1][1];
			dp[i][j][1] += diag[i][j][1] + diag[i+1][j+1][3];
		}
	}

	for(int j = 1 ; j <= c ; j++)
	{
		for(int i = 1 ; i <= r ; i++)
		{
			dp[i][j][3] = dp[i][j-1][3];
			dp[i][j][3] += diag[i][j][0] + diag[i+1][j-1][2];
		}
	}

	ll resp = 0;
	for(int i = 1 ; i <= r ; i++)
	{
		for(int j = 1 ; j <= c ; j++)
		{
			if(mat[i][j] == x)
			{
				resp += i*dp[i-1][j][0];
				resp -= i*dp[i+1][j][2];
				resp -= j*dp[i][j][1];
				resp += j*dp[i][j][3];
			}
		}
	}
	return resp;
}

int main()
{
	cin >> r >> c;

	for(int i = 1 ; i <= r ; i++)
		for(int j = 1 ; j <= c ; j++) cin >> mat[i][j];

	respm = func('M');

	memset(dp, 0, sizeof dp);
	memset(diag, 0, sizeof diag);

	resps = func('S');

	cout << respm << ' ' << resps << endl;
}
