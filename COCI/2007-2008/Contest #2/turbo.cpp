
//My solution is the same as in this link:https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/Olympiad/COCI/official/2008/contest2_solutions/solutions.pdf

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6+10;

int n, vet[maxn], pos[maxn], dir[maxn], esq[maxn];

int query(int p, int mod)
{
	int r = 0;
	if(mod)
	{
		for(int i = p ; i < maxn ; i += i&-i) r += dir[i];
	}
	else
	{
		for(int i = p ; i > 0 ; i -= i&-i) r += esq[i];
	}
	return r;
}

void updt(int p, int mod)
{
	if(mod)
	{
		for(int i = p ; i > 0 ; i -= i&-i) dir[i]++;
	}
	else
	{
		for(int i = p ; i < maxn ; i += i&-i) esq[i]++;
	}
}

int main()
{
	cin >> n;

	for(int i = 1 ; i <= n ; i++)
	{
		cin >> vet[i];
		pos[vet[i]] = i;
	}

	for(int i = 1 ; i <= n/2+1 ; i++)
	{
		if(i == n/2+1 and n%2 == 0) continue;

		int p = pos[i];

		p += query(pos[i], 1);
		p -= query(pos[i], 0);

		cout << abs(i - p) << "\n";

		updt(pos[i], 1);

		if(i == n/2+1) continue;
	
		int k = n-i+1;

		p = pos[k];

		p += query(pos[k], 1);
		p -= query(pos[k], 0);

		cout << abs(k - p) << "\n";

		updt(pos[k], 0);
	}
}
