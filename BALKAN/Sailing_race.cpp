
/*
	Author: Sofhia de Souza Gonçalves
	
	Idea:
		- Let vet[] be my array with the sequence of signs.
		- I made a dp with 3 parameters: my actual position on array, the first sign in my left and the first sign in my 
		right that I didn't visit yet.
		- dist(a, b) = the distance between a and b.
		- dp[x][y][z] = (min(dp[y][y-1][z]+dist(x, y), dp[z][y][z+1]+dist(x, z)))*(y+l-z+1), that is, dp[x][y][z] equals to the
		sum of the distances of the less path from x, where x can go to y or z.
*/




#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const ll inf = 1e17;

int l, vet[210];

ll dp[210][210][210]; 

ll solve(int pos, int i, int j)
{
	if(dp[pos][i][j]) return dp[pos][i][j];

	if(i == 0 and j == l+1) return 0;

	ll p1 = inf, p2 = inf;

	if(i != 0) p1 = solve(i, i-1, j)+(abs(vet[pos]-vet[i])*(i+l-j+1));
	if(j != l+1) p2 = solve(j, i, j+1)+(abs(vet[pos]-vet[j])*(i+l-j+1));

	return dp[pos][i][j] = min(p1, p2);
}

int main()
{
	cin >> l;

	int k1, k2 = -1;

	for(int i = 1 ; i <= l ; i++)
	{
		cin >> vet[i];
		if(vet[i] < 0) k1 = i;		//k1 is the first negative value before 0
		else if(k2 == -1) k2 = i;	//k2 is the first positive value after 0
	}

	ll resp = solve(0, k1, k2);

	cout << resp << endl;
}
