
//The solution is the same as in this link:https://github.com/mostafa-saad/MyCompetitiveProgramming/tree/master/Olympiad/COCI/official/2014/contest1_solutions


#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m;
	
	cin >> n >> m;
	
	int cont = 0;
	for(int i = 1 ; i < m ; i++)
	{
		if((i*n)%m == 0) cont++;
	}		
	
	cout << m-1-cont << endl;
}
