#include <bits/stdc++.h>
using namespace std;

int sum[301][301];
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int q = 1; q <= m; q++)
		{
			int temp;
			cin >> temp;
			sum[i][q] = sum[i - 1][q] + sum[i][q - 1] - sum[i - 1][q - 1] + temp;
		}
	}
	int k;
	cin>>k;
	for (int i = 0; i < k; i++)
	{
		int x1,x2,y1,y2;
		cin>>x1>>y1>>x2>>y2;
		cout<<sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1]<<"\n";
	}
	
}