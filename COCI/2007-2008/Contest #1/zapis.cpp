

//My solution is the same as in this link:https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/Olympiad/COCI/official/2008/contest1_solutions/solutions.pdf


#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;

const int maxn = 210, mod = 1e5;

int n, flag;
ll dp[maxn][maxn];
string s;

ll solve(int ini, int fim)
{
	if(ini > fim) return 1;
	if(ini == fim) return 0;
	if(dp[ini][fim] != -1) return dp[ini][fim];

	ll resp = 0;

	if(s[ini] == ')' or s[ini] == '}' or s[ini] == ']')
	{
		return dp[ini][fim] = 0;
	}
	if(s[ini] == '(' or s[ini] == '?')
	{
		for(int i = ini+1 ; i <= fim ; i++)
		{
			if(s[i] == '?' or s[i] == ')')
			{
				resp += (ll)(solve(ini+1, i-1)*solve(i+1, fim));
				if(resp >= mod)
				{
					flag = 1;
					resp %= mod;
					resp += mod;
				}
			}
		}
	}
	if(s[ini] == '{' or s[ini] == '?')
	{
		for(int i = ini+1 ; i <= fim ; i++)
		{
			if(s[i] == '?' or s[i] == '}')
			{
				resp += (ll)(solve(ini+1, i-1)*solve(i+1, fim));
				if(resp >= mod)
				{
					flag = 1;
					resp %= mod;
					resp += mod;
				}
			}
		}
	}
	if(s[ini] == '[' or s[ini] == '?')
	{
		for(int i = ini+1 ; i <= fim ; i++)
		{
			if(s[i] == '?' or s[i] == ']')
			{
				resp += (ll)(solve(ini+1, i-1)*solve(i+1, fim));
				if(resp >= mod)
				{
					flag = 1;
					resp %= mod;
					resp += mod;
				}
			}
		}
	}
	if(resp >= mod)
	{
		flag = 1;
		resp %= mod;
		resp += mod;
	}
	return dp[ini][fim] = resp;
}

int32_t main()
{
	cin >> n;
	cin >> s;

	memset(dp, -1, sizeof dp);

	ll resp = solve(0, n-1);

	if(resp < mod) cout << resp << "\n";
	else
	{
		stringstream aux;
		string k;
		aux << resp;
		aux >> k;
		for(int i = 1 ; i < k.size() ; i++) cout << k[i];
		cout << "\n";
	} 
}
