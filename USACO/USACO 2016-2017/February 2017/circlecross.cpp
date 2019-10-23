//USACO 2017 - FEBRUARY - GOLD - Why Did the Cow Cross the Road III
//Sofhia de Souza Gonçalves

#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e4+10;

int n, vet[2*maxn], bit[maxn], cont, pos[maxn];
bool vist[maxn];

void updt(int x)
{
	for(int i = x ; i < maxn ; i+= i&(-i)) bit[i] += 1;
}

int query(int x)
{
	int ans = 0;
	for(int i = x ; i > 0 ; i -= i&(-i)) ans += bit[i];
	return ans;
}

int main()
{
	freopen("circlecross.in", "r", stdin);
	freopen("circlecross.out", "w", stdout);

	cin >> n;

	memset(vist, false, sizeof vist);

	for(int i = 1 ; i <= 2*n ; i++)
	{
		cin >> vet[i];
	}

	long long int resp = 0;	

	for(int i = 1 ; i <= 2*n ; i++)
	{
		if(!vist[vet[i]])
		{
			vist[vet[i]] = 1;
			pos[vet[i]] = ++cont;
		}
		else
		{
			resp += cont - pos[vet[i]] - (query(cont) - query(pos[vet[i]]));
			updt(pos[vet[i]]);
		}
	}

	cout << resp << "\n";
}
