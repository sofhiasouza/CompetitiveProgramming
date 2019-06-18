
/*
	Author: Sofhia de Souza Gonçalves
	
	Idea: 
		- I did a binary search in the time. For all the values that I choose for middle,  I tested and made a verification to
		see if that value for the time was ok, and after all the binary search I printed the result.
*/



#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+10;

double k, vet[MAXN];

int n;

bool work(double x)
{
	double f = x+vet[0]; //walked with the first messenger to as right as possible(f is the closest messenger of my actual messenger)
	for(int i = 1 ; i < n ; i++)
	{
		double v = vet[i] - x;
		if(v-k > f) return false; //if the i messenger can't hear the closest messenger, I return false
		else f = min(vet[i]+x, f+k); //else, I change my f to the messenger that is more closer to the next (me)
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
