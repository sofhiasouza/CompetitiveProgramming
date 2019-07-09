
/*
	The solution is the same as the described in this link: https://www.ceoi2003.de/www/downloads/therace-solution.pdf
*/




#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef pair < pair < double, int >, pair < int, int > > ii;

const int maxn = 250010, mod = 1e6;

int n, x[maxn], v[maxn], qv[110], pos[maxn], vet[maxn];

int main()
{
	cin >> n;

	long long int cont = 0;
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> x[i] >> v[i];
		for(int j = v[i]+1 ; j <= 100 ; j++)
		{
			cont += qv[j];
			cont %= mod;
		}
		cont %= mod;
		qv[v[i]]++;
		pos[i] = i;
		vet[i] = i;
	}

	cout << cont << endl;

	set < pair < int, int > > s;

	priority_queue < ii, vector < ii > , greater < ii > > fila;
	for(int i = 1 ; i < n ; i++)
	{
		if(v[i] > v[i+1])
		{
			double t = (double)(x[i+1] - x[i]) / (double)(v[i] - v[i+1]);
			fila.push(mp(mp(t, pos[i+1]), mp(i, i+1)));
			s.insert({i, i+1});
		}
	}

	int quant = 0;
	while(fila.size())
	{
		ii r = fila.top();
		fila.pop();

		int a = r.second.first;
		int b = r.second.second;

		if(pos[a]+1 != pos[b])
		{
			s.erase(make_pair(a, b));
			continue;
		}
		cout << a << ' ' << b << endl;

		quant++;
		if(quant == 10000) break;
		swap(pos[a], pos[b]);

		vet[pos[a]] = a;
		vet[pos[b]] = b;

		int k = vet[pos[a]+1];
		if(pos[a]+1 <= n and v[k] < v[a] and !s.count(make_pair(a, k)))
		{
			double t = (double)abs(x[k] - x[a]) / (double)abs(v[a] - v[k]);
			fila.push(mp(mp(t, pos[k]), mp(a, k)));
			s.insert({a, k});
		
		}

		int g = vet[pos[b]-1];
		
		if(pos[b]-1 > 0 and v[g] > v[b] and !s.count(make_pair(g, b)))
		{
			double t = (double)abs(x[b] - x[g]) / (double)abs(v[g] - v[b]);
			fila.push(mp(mp(t, pos[b]), mp(g, b)));
			s.insert({g, b});
		}
	}

}

	
