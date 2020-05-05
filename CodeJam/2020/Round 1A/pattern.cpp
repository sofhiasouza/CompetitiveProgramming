//CodeJam 2020 - Round 1A - Pattern Matching
//Sofhia de Souza Gonçalves

#include <bits/stdc++.h>
using namespace std;

bool cmp(string a, string b)
{
	return a.size() < b.size();
}

int main()
{
	int t, p = 0;
	cin >> t;

	while(t--)
	{
		int n, q = 1;
		cin >> n;
		p++;

		vector < string > b, e;
		string meio = "";

		for(int i = 0 ; i < n ; i++)
		{
			string s;
			cin >> s;

			string ini = "";
			int f = -1, l = -1;
			for(int j = 0 ; j < s.size() ; j++)
			{
				if(s[j] == '*')
				{
					if(ini.size()) b.push_back(ini);
					f = j;
					break;
				}
				else ini.push_back(s[j]);
			}

			string fim = "";
			for(int j = s.size()-1 ; j >= 0 ; j--)
			{
				if(s[j] == '*')
				{
					if(fim.size()) e.push_back(fim);
					l = j;
					break;
				}
				else fim.push_back(s[j]);
			}

			if(f < l)
			{
				for(int j = f+1 ; j < l ; j++)
				{
					if(s[j] != '*') meio.push_back(s[j]);
				}
			}
		}

		cout << "Case #" << p << ": ";
		
		sort(b.begin(), b.end(), cmp);
		sort(e.begin(), e.end(), cmp);
	
		for(int i = 1 ; i < b.size() ; i++)
		{
			for(int j = 0 ; j < b[i-1].size() ; j++)
			{
				if(b[i][j] != b[i-1][j]) q = 0;
			}
		}

		for(int i = 1 ; i < e.size() ; i++)
		{
			for(int j = 0 ; j < e[i-1].size() ; j++)
			{
				if(e[i][j] != e[i-1][j]) q = 0;
			}
		}

		if(!q)
		{
			cout << "*";
		}
		else
		{
			if(b.size())cout << b[b.size()-1];
			if(meio.size())cout << meio;
			if(e.size())
			{
				string x = e[e.size()-1];
				reverse(x.begin(), x.end());
				cout<< x;
			}
		}
		cout << "\n";
	}
}
