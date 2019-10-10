/*
	COI 2006 - Patrik
	Author: Sofhia de Souza Gonçalves

	The solution is the same as in this link: https://github.com/MohamedAhmed04/Competitive-programming/blob/master/COI/COI%202006%20Patrik.cpp


*/

#include <bits/stdc++.h>
using namespace std;
typedef pair < int, int > ii;

int main()
{
	int n;
	cin >> n;

	stack < ii > pilha;

	long long int resp = 0;

	for(int i = 1 ; i <= n ; i++)
	{
		int a;
		cin >> a;
	
		int qtd = 1;

		while(pilha.size() and pilha.top().first <= a)
		{
			resp += pilha.top().second;

			if(pilha.top().first == a) qtd += pilha.top().second;

			pilha.pop();
		}
		if(pilha.size()) resp++;

		pilha.push({a, qtd});
	}

	cout << resp << "\n";
}
