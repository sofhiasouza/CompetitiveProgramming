
/*

	Author: Sofhia de Souza Gonçalves

	Idea:
		- To every sequence, I saved in a vector all the positions in that the 10 digits appeared.
		- Then, I tested to all the 10^4 possible pins if they could be typed with all the n sequences. 

*/


#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int maxn = 1e3+10, maxt = 1e4+10;

int n;

vector < int > vet[maxn][12];

bool ok(int a, int b, int c, int d)
{
	for(int i = 1 ; i <= n ; i++)
	{
		if(!vet[i][a].size()) return false;
		
		int f = vet[i][a][0];

		if(!vet[i][b].size()) return false;
		
		auto ss = lower_bound(vet[i][b].begin(), vet[i][b].end(), f);
		if(ss == vet[i][b].end()) return false;
		int s = vet[i][b][ss - vet[i][b].begin()];
		
		if(!vet[i][c].size()) return false;
		
		auto tt = lower_bound(vet[i][c].begin(), vet[i][c].end(), s);
		if(tt == vet[i][c].end()) return false;
		int t = vet[i][c][tt - vet[i][c].begin()];

		if(!vet[i][d].size()) return false;
		auto qq = lower_bound(vet[i][d].begin(), vet[i][d].end(), t);
		if(qq == vet[i][d].end()) return false;

	}
	return true;
}

int main()
{
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
	{
		int x;
		cin >> x;

		string s;
		cin >> s;
		
		for(int j = 0 ; j < s.size() ; j++) vet[i][s[j]-'0'].pb(j);
	}


	int resp = 0;
	for(int i = 0 ; i < 10 ; i++)
	{
		for(int j = 0 ; j < 10 ; j++)
		{
			for(int k = 0 ; k < 10 ; k++)
			{
				for(int h = 0 ; h < 10 ; h++)
				{
					if(ok(i, j, k, h)) resp++;
				}
			}
		}
	}

	cout << resp << endl;
}
