//Problem 4sum NOI 2008
//Code by Sofhia de Souza
//Solution is the same as described in this link: https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/Olympiad/NOI/official/2008.pdf


#include <bits/stdc++.h>
using namespace std;

map < int, pair < int, int > > mapa;

int main()
{
	int a, b, c, d, va[510], vb[510], vc[510], vd[510];

	cin >> a >> b >> c >> d;

	for(int i = 1 ; i <= a ; i++) cin >> va[i];

	for(int i = 1 ; i <= b ; i++) cin >> vb[i];

	for(int i = 1 ; i <= c ; i++) cin >> vc[i];

	for(int i = 1 ; i <= d ; i++) cin >> vd[i];

	for(int i = 1 ; i <= a ; i++)
	{
		for(int j = 1 ; j <= b ; j++)
		{
			mapa[va[i]+vb[j]] = {va[i], vb[j]};
		}
	}

	int flag = 0;
	for(int i = 1 ; i <= c ; i++)
	{
		for(int j = 1 ; j <= d ; j++)
		{
			int k = vc[i] + vd[j];
			if(mapa.count(k*(-1)))
			{
				cout << mapa[k*(-1)].first << ' ' << mapa[k*(-1)].second << ' ' << vc[i] << ' ' << vd[j] << "\n";
				flag = 1;
				break; 
			}
		}
		if(flag) break;
	}
}
