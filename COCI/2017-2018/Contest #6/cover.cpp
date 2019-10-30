//COCI 2017-2018 - Cover
//Sofhia de Souza Gonçalves

//Solution: https://codeforces.com/blog/entry/57508?#comment-411980https://codeforces.com/blog/entry/57508?#comment-411980

#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define F first
#define S second
using namespace std;
typedef pair < int, int > ii;

const int maxn = 5e3+10, inf = 2e18+10;

int n, dp[maxn];

map < int, int > mapa;

int32_t main()
{
	scanf("%lld", &n);

	for(int i = 1 ; i <= n ; i++)
	{
		int x, y;

    scanf("%lld %lld", &x, &y);

		x = abs(x);
		y = abs(y);

		if(!mapa.count(x)) mapa[x] = y;
		else mapa[x] = max(mapa[x], y);
	}

	vector < ii > aux;

	for(auto v : mapa)
	{
		while(1)
		{
			if(!aux.size() or aux[aux.size()-1].S > v.S)
			{
				aux.pb(v);
				break;
			}
			else if(aux.size()) aux.pop_back();			
		}
		
	}

	dp[1] = 0;

	for(int i = 1 ; i < aux.size() ; i++)
	{
		dp[i+1] = inf;
	
		for(int j = 0 ; j < i ; j++)
		{
			dp[i+1] = min(dp[i+1], dp[j+1] + 4ll*aux[j].S*aux[i-1].F);
		}
	}

	int resp = inf;
  
	for(int i = 0 ; i < aux.size() ; i++)
	{
		resp = min(resp, dp[i+1] + 4ll*aux[i].S*aux[aux.size()-1].F);
	}

	printf("%lld\n", resp);
}
