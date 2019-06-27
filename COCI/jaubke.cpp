
/*
	The solution is the same as in this link: https://github.com/mostafa-saad/MyCompetitiveProgramming/tree/master/Olympiad/COCI/official/2015/contest5_solutions
*/


#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair < int, int > ii;

const int maxn = 510;
const ll inf = 1e9;

int r, s, ult[maxn][maxn][2];
char mat[maxn][maxn];

void update(int x)
{
	int last = 0;
	for(int i = 1 ; i <= s ; i++)
	{
		if(mat[x][i] == 'x') last = i;
		ult[x][i][0] = last;
	}
	last = 0;
	for(int i = s ; i >= 1 ; i--)
	{
		if(mat[x][i] == 'x') last = i;
		ult[x][i][1] = last;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> r >> s;

	for(int i = 1 ; i <= r ; i++)
	{
		for(int j = 1 ; j <= s ; j++)
		{
			cin >> mat[i][j];
		}
	}

	for(int i = 1 ; i <= r ; i++) update(i);

	int g;
	cin >> g;
	for(int i = 0 ; i < g ; i++)
	{
		int a, b;
		ll resp = inf;
		cin >> a >> b;
		for(int k = 1 ; k <= r ; k++)
		{
			ll dir = ult[k][b][1];
			ll esq = ult[k][b][0];
	//		cout << k << ' ' << esq << ' '<< dir << endl;
			if(dir != 0) dir = (dir-b)*(dir-b) + (a-k)*(a-k);
			else dir = inf;
			if(esq != 0) esq = (esq-b)*(esq-b) + (a-k)*(a-k); 
			else esq = inf;
	//		cout << esq << ' ' << dir << endl;
			resp = min({resp, esq, dir});
		}
		cout << resp << endl;
		mat[a][b] = 'x';
		update(a);
	}
}
