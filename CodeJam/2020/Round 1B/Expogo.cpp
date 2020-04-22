//Expogo - CodeJam 2020 Round 1B
//Sofhia de Souza Gonçalves

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t, q = 0;

	cin >> t;

	while(t--)
	{
		q++;

		int x, y, i = 0, j = 0, flag = 1;
		cin >> x >> y;
	
		vector < char > resp;

		while(x != 0 or y != 0)
		{
			if((x%2 and y%2) or (x%2 == 0 and y%2 == 0))
			{
				flag = 0;
				break;
			}

			if(x != 0 and x%2)
			{
				if(y == 0 and x == 1) i += 1, resp.push_back('E');
				else if(y == 0 and x == -1) i -= 1, resp.push_back('W');
				else if(y/2%2)
				{
					if((x+1)/2%2 == 0) i -= 1, resp.push_back('W');
					else if((x-1)/2%2 == 0) i += 1, resp.push_back('E');
					else flag = 0;
				}
				else
				{
					if((x+1)/2%2) i -= 1, resp.push_back('W');
					else if((x-1)/2%2) i += 1, resp.push_back('E');
					else flag = 0;
				}
			}
			else
			{
				if(x == 0 and y == 1) j += 1, resp.push_back('N');
				else if(x == 0 and y == -1) j -= 1, resp.push_back('S');
				else if(x/2%2)
				{
					if((y+1)/2%2 == 0) j -= 1, resp.push_back('S');
					else if((y-1)/2%2 == 0)j += 1, resp.push_back('N');
					else flag = 0;
				}
				else
				{
					if((y+1)/2%2) j -= 1, resp.push_back('S');
					else if((y-1)/2%2)j += 1, resp.push_back('N');
					else flag = 0;
				}
			}

			x -= i;
			y -= j;
			x /= 2;
			y /= 2;
			i = 0;
			j = 0;
		}

		cout << "Case #" << q << ": ";

		if(flag)
		{
			for(int i = 0 ; i < resp.size() ; i++) cout << resp[i];
			cout << "\n";
		}
		else cout << "IMPOSSIBLE\n";
	}
}
