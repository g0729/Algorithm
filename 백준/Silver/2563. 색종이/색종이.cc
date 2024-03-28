#include <bits/stdc++.h>
using namespace std;

bool MAP[100][100];

int main()
{
	int n;

	cin>>n;

	for (int i = 0; i < n; i++)
	{
		int x,y;

		cin>>x>>y;
		
		for (int j = x; j < x+10; j++)
		{
			for (int p = y; p < y+10; p++)
			{
				MAP[j][p]=true;
			}
			
		}
		
	}
	
	int res=0;

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if(MAP[i][j])
			res++;
		}
		
	}
	
	cout<<res;
}