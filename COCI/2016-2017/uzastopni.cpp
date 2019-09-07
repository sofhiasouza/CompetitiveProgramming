//COCI 17 - Uzastopni
//Code by Sofhia de Souza

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int maxi = 2e5;

int main()
{
	ll n;

	cin >> n;

	for(int i = 2 ; i <= maxi and i <= n ; i++)
	{
		ll ini = i, fim = n;
		while(ini <= fim)
		{
			ll meio = (ini+fim)/2;
			double r = (meio+(meio-i+1))*i/2;
			if(r == n)
			{
				cout << meio-i+1 << ' ' << meio << "\n";
				break;
			}
			else if(r < n) ini = meio+1;
			else fim = meio-1;
		} 
	}	
}
