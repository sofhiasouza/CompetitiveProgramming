/*
      Author: Sofhia de Souza Gonçalves
      
      Idea:
          -I calculated the diferences of the adjacentes values and I added in the variable sum. For each query, only the 
          l-th diference and the r+1-th diference was modificated. So, I atualized this values, removed the old values from
          the sum and added the new values.
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int maxn = 2e5+10;

ll n, q, a[maxn];
ll sum, dif[maxn], s, t;

int main()
{
      ios::sync_with_stdio(false);
      cin.tie(nullptr);

      cin >> n >> q >> s >> t;

      for(int i = 0 ; i <= n ; i++) cin >> a[i];	

      for(int i = 1 ; i <= n ; i++)
      {
              dif[i] = a[i]-a[i-1];
              if(dif[i] <= 0) sum += abs(dif[i]*t);
              else sum -= abs(dif[i]*s);
      }

      dif[0] = dif[n+1] = 0;

      for(int i = 0 ; i < q ; i++)
      {
              int l, r, x;
              cin >> l >> r >> x;

              if(dif[l] <= 0) sum -= abs(dif[l]*t);
              else sum += abs(dif[l]*s);

              if(dif[r+1] <= 0) sum -= abs(dif[r+1]*t);
              else sum += abs(dif[r+1]*s);

              dif[l] += x;
              if(r+1 <= n) dif[r+1] -= x;

              if(dif[l] <= 0) sum += abs(dif[l]*t);
              else sum -= abs(dif[l]*s);

              if(dif[r+1] <= 0) sum += abs(dif[r+1]*t);
              else sum -= abs(dif[r+1]*s);		

              cout << sum << endl;

      }

}
