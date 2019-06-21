
	/*
		The solution is the same of this link: https://github.com/mostafa-saad/MyCompetitiveProgramming/tree/master/Olympiad/COCI/official/2008/contest6_solutions
	*/


#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main()
{
	int n, vet[110];
	cin >> n;
	
	vector < int > difs;
	
	for(int i = 0 ; i < n ; i++)
	{
		cin >> vet[i];
	}
	
	sort(vet, vet+n);
	
	for(int i = 1 ; i < n ; i++) difs.pb(vet[i]-vet[i-1]);
	
	int mdc;
	
	for(int i = 0 ; i < difs.size() ; i++)
	{
		if(i == 0) mdc = difs[i];
		else mdc = __gcd(difs[i], mdc);
	}
	vector < int > resp;
	
	for(int i = 2 ; i <= sqrt(mdc) ; i++)
	{
		if(!(mdc%i))
		{
			resp.pb(i);
			if(i != sqrt(mdc))resp.pb(mdc/i);
		}
	}
	resp.pb(mdc);
	
	sort(resp.begin(), resp.end());
	
	for(int i = 0 ; i < resp.size() ; i++)
	{
		if(i != 0) cout << ' ';
		cout << resp[i];
	}
	cout << endl;
}
