
/*
	COI - Task Glasnici
	Same idea of the link: 
	https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/Olympiad/COCI/official/2008/olympiad_solutions/glasnici.cpp
*/



#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+10;

double k, vet[MAXN];

int n;

bool work(double x)
{
	double f = x+vet[0]; 
	for(int i = 1 ; i < n ; i++)
	{
		double v = vet[i] - x;
		if(v-k > f) return false; 
		else f = min(vet[i]+x, f+k); 
	}
	return true;
}

int main()
{
	cin >> k;
	cin >> n;

	for(int i = 0 ; i < n ; i++) cin >> vet[i];

	double ini = 0, fim = 1e9;
	for(int i = 0 ; i <= 100 ; i++)
	{
		double meio = (ini+fim)/2.0;
		if(work(meio)) fim = meio;
		else ini = meio;
	}
	cout << fixed << setprecision(3);
	cout << ini << endl;
}
