/*
  The solution is the same as in this link: https://github.com/mostafa-saad/MyCompetitiveProgramming/tree/master/Olympiad/COCI/official/2008/contest2_solutions
*/



#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4+10;

int n, A[maxn], B[maxn];
long long int res;

int solve(int val, int v)
{
	int menor = 0;
	int i = v;
	
	int ant = val;
	
	do
	{
		int value = B[(i+1)%n]-B[(i+2)%n];
		int at = -(value-ant);
		
		A[(i+3)%n] = ant = at;
		res += A[(i+3)%n];
		
		menor = min(menor, at);
		i = (i+3)%n;
	}while(i != v);
	
	return menor;
}

void add(int x, int val)
{
	int i = x;
	do
	{
		A[i] += val;
		i = (i+3)%n;
	}while(i != x);
}

int main()
{
	cin >> n;
	long long int sum = 0;
	for(int i = 0 ; i < n ; i++) cin >> B[i], sum += B[i];
	
	if(n%3 != 0)
	{
		solve(1, 0);
		add(0, ((sum/3)-res)/n);
	}
	else
	{
		add(0, 1-solve(0, 0));
		add(1, 1-solve(0, 1));
		solve(0, 2);
		add(2, B[1]-A[0]-A[1]);
	}
	for(int i = 0 ; i < n ; i++) cout << A[i] << endl;
}
