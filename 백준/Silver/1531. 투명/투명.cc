	#include <bits/stdc++.h>
	using namespace std;

	int MAP[101][101];

	int main()
	{
		int n, m;
		int res=0;

		cin >> n>>m;

		while(n--)
		{
			int x1,x2,y1,y2;

			cin>>x1>>y1>>x2>>y2;

			for (int i = x1; i <= x2; i++)
			{
				for (int j = y1; j <= y2; j++)
				{
					MAP[i][j]++;
				}
			}
		}	
			for (int i = 1; i <= 100; i++)
			{
				for (int j = 1; j <= 100; j++)
				{
					if(MAP[i][j]>m)
					res++;
				}
				
			}
		cout<<res;
	}