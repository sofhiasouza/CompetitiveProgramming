
	/*
		
		Author: Sofhia de Souza Gonçalves
		
		Idea:
			- To every stick, I change the 'x' that the stick broke, then I do a dfs() and keep the value of its
			component int the array comp[][].
			- After that, I calculate the value of the minimun distance (min_comp[]) from my component to other 
			(or to the ground).
			- I also see if the component is floating in the air. If yes, I change my matrix, and put my component
			p min_comp[p] rows below. 
		
	*/



#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;

int r, c, n, comp[maxn][maxn], cont, vet1[4] = {1, -1, 0, 0}, vet2[4] = {0, 0, 1, -1}, dist[maxn][maxn], min_comp[maxn*maxn];

char mat[maxn][maxn];

void dfs(int i, int j, int ip, int jp)
{
	comp[i][j] = cont;
	
	for(int k = 0 ; k < 4 ; k++)
	{
		if(i + vet1[k] >= 1 and i + vet1[k] <= r and j + vet2[k] >= 1 and j + vet2[k] <= c and mat[i+vet1[k]][j+vet2[k]] == 'x' and !comp[i+vet1[k]][j+vet2[k]])
			dfs(i+vet1[k], j+vet2[k], i, j);
	}
}

void att()
{
	cont = 0;
	memset(comp, 0, sizeof comp);
	
	//calculate the components
	for(int i = r ; i >= 1 ; i--)
	{
		for(int j = 1 ; j <= c ; j++)
		{
			if(!comp[i][j] and mat[i][j] == 'x')
			{
				cont++;
				dfs(i, j, 0, 0);
			}
		}
	}
	
	int aux[maxn], mud = -1;
	
	memset(aux, 0, sizeof aux);
	memset(dist, maxn, sizeof dist);
	memset(min_comp, maxn, sizeof min_comp);
	
	//calculate the minimum distance
	for(int i = 1 ; i <= r ; i++)
	{
		for(int j = 1 ; j <= c ; j++)
		{
			if(comp[aux[j]][j] != comp[i][j]) dist[i][j] = i - aux[j] -1;
			if(mat[i][j] == 'x')
			{
				aux[j] = i;
				min_comp[comp[i][j]] = min(min_comp[comp[i][j]], dist[i][j]);
				if(min_comp[comp[i][j]] != 0) mud = comp[i][j];
			}
		}
	}
	
	int vist[maxn][maxn];
	memset(vist, 0, sizeof vist);
	
	//if some component is floating, I change the matrix
	if(mud != -1)
	{
		for(int i = r ; i >= 1 ; i--)
		{
			for(int j = 1 ; j <= c ; j++)
			{
				if(comp[i][j] == mud)
				{
					if(!vist[i][j]) mat[i][j] = '.';
					mat[i-min_comp[mud]][j] = 'x';
					vist[i-min_comp[mud]][j] = 1;
				}
			}
		}
	}
}


int main()
{
	cin >> r >> c;
	
	for(int i = r ; i >= 1 ; i--)
	{
		for(int j = 1 ; j <= c ; j++)
		{
			cin >> mat[i][j];
		}
	}
	
	cin >> n;
	
	int mod = 0;
	for(int i = 0 ; i < n ; i++)
	{
		int a;
		cin >> a;
		
		int flag = 0;
		// I change the broke 'x':
		if(mod == 0)
		{
			for(int j = 1 ; j <= c ; j++)
			{
				if(mat[a][j] == 'x')
				{
					mat[a][j] = '.';
					flag = 1;
					break;
				}
			}
		}
		else
		{
			for(int j = c ; j >= 1 ; j--)
			{
				if(mat[a][j] == 'x')
				{
					mat[a][j] = '.';
					flag = 1;
					break;
				}
			}
		}

		//If some 'x' broke, I call my function
		if(flag) att();
		
		mod ^= 1;
	}
	
	for(int i = r ; i >= 1 ; i--)
	{
		for(int j = 1 ; j <= c ; j++)
		{
			cout << mat[i][j];
		}
		cout << endl;
	}	
}
