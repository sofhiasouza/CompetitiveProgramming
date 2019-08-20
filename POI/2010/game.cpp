
//The solution is the same as in this link:
//https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/Olympiad/POI/official/2010/editorial/gra.pdf


#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000000

long long res[MAXN];

int main()
{
    int n, k;
    vector<int> cart;

    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
	   scanf("%d", &k);
	   cart.push_back(k);
    }

    sort(cart.begin(), cart.end());

    res[0] = cart[0];

   // cout << res[0] << ' ';
    for(int i=1; i<n; i++)
	res[i] = max((long long)cart[i] - res[i-1], res[i-1]);//, cout << res[i] << ' ';

    //cout << endl;
    printf("%lld\n", res[n-1]);
}
