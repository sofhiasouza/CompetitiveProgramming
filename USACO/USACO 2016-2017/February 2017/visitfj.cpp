//USACO 2017 - FEBRUARY - GOLD - Why Did the Cow Cross the Road
//Sofhia de Souza Gonçalves

#include <bits/stdc++.h>
#define pb push_back
#define S second
#define F first
using namespace std;
typedef unsigned long long int ll;
typedef pair < ll, int > ii;
typedef pair < ll, ii > iii;

const int maxn = 110;

int n, mat[maxn][maxn];
int vet1[18] = {-3, -2, -1, 0, 1, 2, 3, 2, 1, 0, -1, -2, 1, -1, 0, 0};
int vet2[18] = {0, 1, 2, 3, 2, 1, 0, -1, -2, -3, -2, -1, 0, 0, 1, -1};
int aux1[15] = {-2, -1, -1, 0, 0, 1, 1, 2, 1, 0, 0, -1};
int aux2[15] = {0, 0, 1, 1, 2, 1, 0, 0, -1, -1, -2, -1};

ll t;

ll vist[maxn][maxn];

int dijkstra()
{
	priority_queue < ii , vector < ii >, greater < ii > > fila;
	fila.push({0LL, 0});
	vist[0][0] = 0;

	while(fila.size())
	{
		ii z = fila.top();
		fila.pop();

		ll val = z.F;
		int x = z.S/n;
		int y = z.S%n;

		if(vist[x][y] != val) continue;

		if(x == n-1 and y == n-1) return val;

		for(int i = 0 ; i < 16 ; i++)
		{
			int x1 = x + vet1[i];
			int y1 = y + vet2[i];

			if(x1 >= 0 and x1 < n and y1 >= 0 and y1 < n and vist[x1][y1] > val+(ll)mat[x1][y1]+(3LL*t))
			{
				fila.push({val+(ll)mat[x1][y1]+(3LL*t), x1*n + y1});
				vist[x1][y1] = val+(ll)mat[x1][y1]+(3LL*t);
			}
		}

		for(int i = 0 ; i < 12 ; i++)
		{
			int x1 = x + aux1[i];
			int y1 = y + aux2[i];

			if(x1 == n-1 and y1 == n-1 and vist[n-1][n-1] > val+t*(ll)(abs(x1-x)+abs(y1-y)))
			{
				fila.push({val+t*(ll)(abs(x1-x)+abs(y1-y)), x1*n + y1});
				vist[n-1][n-1] = val+t*(ll)(abs(x1-x)+abs(y1-y));
			}
		}
	}
}

int32_t main()
{
	freopen("visitfj.in", "r", stdin);
	freopen("visitfj.out", "w", stdout);

	cin >> n >> t;

	int cont = 0;
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = 0 ; j < n ; j++)
		{
			cin >> mat[i][j];
			vist[i][j] = 1000000000000000000;
		}
	}

	long long int resp = dijkstra();

	cout << resp << "\n";
}
