
/*

	Author: Sofhia de Souza Gonçalves
	
	Idea:
		- I do a dfs and I keep, for each vertex k, its moment of entrance and exit of the dfs, and I calculte how many roads I walk to go to
		vertex 1 in cont[k].
		- Then, for each A question, I update my BIT of range, where the subtree of vertex x is all the values between the entry and
		the exit of x. I subtract a road in my entry and add it to my exit time (I add so that this subtraction don't be counted in other 			vertices that are not in my subtree)
		- For each W k question, I verify how many roads in the way of k were removed, and I subtract this of cont[k].


*/

#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn = 3e5;

int n, m, pai[maxn], cont[maxn], ent[maxn], sai[maxn], bit[maxn*2];

vector < int > grafo[maxn];
vector < int > vet;

void dfs(int u, int p, int q)
{
	pai[u] = p;
	cont[u] = q;
	
	vet.pb(u);
	ent[u] = vet.size()-1;
	
	for(int i = 0 ; i < grafo[u].size() ; i++)
	{
		int v = grafo[u][i];
		if(v == p) continue;
		
		dfs(v, u, q+1);
	}
	
	vet.pb(u);
	sai[u] = vet.size()-1;
}	

void update(int k, int val)
{
	for(int i = k ; i <= 2*maxn ; i += i & -i) bit[i] += val;
}

int query(int k)
{
	int ans = 0;
	for(int i = k ; i > 0 ; i -= i & -i) ans += bit[i];
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	
	for(int i = 1 ; i <= n-1 ; i++)
	{
		int a, b;
		cin >> a >> b;
		grafo[a].pb(b);
		grafo[b].pb(a);
	}

	dfs(1, 0, 0);
	
	cin >> m;
	
	for(int i = 0 ; i < n+m-1 ; i++)
	{
		char c;
		int a, b;
		cin >> c;
		
		if(c == 'A')
		{
			cin >> a >> b;
			if(pai[a] != b) swap(a, b);
			update(ent[a], -1);
			update(sai[a], 1);					
		}
		else
		{
			cin >> a;
			cout << cont[a] + query(ent[a]) << endl;			
		}
	}
}	
