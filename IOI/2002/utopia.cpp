/*
	Author: Sofhia de Souza Gonçalves
	
	Idea:
	
	-For this solution, positions x are independent of positions y and vice versa.
	First, I kept what signals each coordinate should have. After that, I checked which of these signs had changed
	and which had remained since the last location. For those positions that had changed, I put the highest values
	from the last coordinate to the first. 
	
	-For the intervals between these coordinates, I found the largest value I could add that would not exceed the 
	range limit (this limit is the distance from the coordinate to point 0 of its axis and the absolute value of the 
	amount that it will walk in the next coordinate that change of sign). That's because no matter what I do in this 
	interval, if it doesn't exceed this limit, the next value that needs to change signal can change its signal.

*/

#include <iostream>
#include <math.h>
#include <set>
#include <algorithm>
using namespace std;

const int maxn = 1e4+10, MAXN = 2e4+10;

int n, sin1[maxn], sin2[maxn], resp1[maxn], resp2[maxn], vet[MAXN], prox[MAXN];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	scanf("%d", &n);

	for(int i = 0 ; i < 2*n ; i++) scanf("%d", &vet[i]);

	sort(vet, vet+(2*n));

	for(int i = 1 ; i <= n ; i++)
	{
		int a;
		scanf("%d", &a);
	
		if(a == 1 or a == 4) sin1[i] = 1;
		else sin1[i] = -1;

		if(a == 1 or a == 2) sin2[i] = 1;
		else sin2[i] = -1;
	
	}

	int cont = 2*n-1;
	for(int i = n ; i >= 1 ; i--)
	{
		if(i == 1 or sin1[i] != sin1[i-1]) resp1[i] = vet[cont--];
		if(i == 1 or sin2[i] != sin2[i-1]) resp2[i] = vet[cont--]; 
	}

	
	set < int > s;
	for(int i = 0 ; i <= cont ; i++) s.insert(vet[i]*-1);

	int prox1 = 0, prox2 = 0;
	resp1[0] = resp2[0] = 1e6;
	for(int i = n ; i >= 1 ; i--)
	{
		if(!resp1[i]) prox[i] = resp1[prox1];
		else prox1 = i;

		if(!resp2[i]) prox[i+n] = resp2[prox2];
		else prox2 = i;
	}

	int r = 0, flag = 1; 
	for(int i = 1 ; i <= n ; i++)
	{
		if(resp1[i])
		{
			resp1[i] *= sin1[i];
			r += resp1[i];
		}
		else
		{
			int sinal = -1;
			if(r < 0) sinal = 1;
			int l1 = abs(r)-1 ;
			int l2 = abs((prox[i]*sin1[i])-r)-1;

			int pos = 1, aux = 1;

			if(!s.size())
			{
				flag = 0;
				break;
			}
			set<int>::iterator v1 = s.lower_bound(-l1), v2 = s.lower_bound(-l2);
			if(l1 != 0 and v1 != s.end()) pos = *(v1);
			if(l2 != 0 and v2 != s.end()) aux = *(v2);


			if(pos == 1) pos = aux, sinal *= -1;
			else if(pos > aux and aux != 1) pos = aux, sinal *= -1;

			if(pos == 1)
			{
				flag = 0;
				break;
			}
			else
			{
				resp1[i] = -pos*sinal;
				s.erase(pos);
			}
			r += resp1[i];
		}
	}

	r = 0; 
	for(int i = 1 ; i <= n ; i++)
	{
		if(resp2[i])
		{
			resp2[i] *= sin2[i];
			r += resp2[i];
		}
		else
		{
			int sinal = -1;
			if(r < 0) sinal = 1;
			int l1 = abs(r)-1;
			int l2 = abs((prox[i+n]*sin2[i])-r)-1;

			int pos = 1, aux = 1;

			if(!s.size())
			{
				flag = 0;
				break;
			}

			set<int>::iterator v1 = s.lower_bound(-l1), v2 = s.lower_bound(-l2);
			if(l1 != 0 and v1 != s.end()) pos = *(v1);
			if(l2 != 0 and v2 != s.end()) aux = *(v2);

			if(pos == 1) pos = aux, sinal *= -1;
			else if(pos > aux and aux != 1) pos = aux, sinal *= -1;

			if(pos == 1)
			{
				flag = 0;
				break;
			}
			else
			{
				resp2[i] = -pos*sinal;
				s.erase(pos);
			}
			r += resp2[i];
		}
	}

	if(flag)
	{	
		for(int i = 1 ; i <= n ; i++)
		{
			if(resp1[i] > 0) printf("+");
			printf("%d ", resp1[i]);
			if(resp2[i] > 0) printf("+");
			printf("%d\n", resp2[i]);
		}
	}
	else cout << 0 << endl;
}
