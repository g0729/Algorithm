#include <bits/stdc++.h>
using namespace std;
int sum[301][301][11];
int arr[301][301];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int q = 1; q <= n; q++)
		{
			cin >> arr[i][q];
			sum[i][q][arr[i][q]] = 1;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int q = 1; q <= n; q++)
		{
			for (int j = 1; j <= 10; j++)
			{
				sum[i][q][j] = sum[i][q][j] + sum[i - 1][q][j] + sum[i][q - 1][j] - sum[i - 1][q - 1][j];
			}
		}
	}
	int q;
	cin >> q;
	while (q--)
	{
		int x1, x2, y1, y2;
		int cnt = 0;
		cin>>x1>>y1>>x2>>y2;
		for (int i = 1; i <= 10; i++)
		{
			int temp=sum[x2][y2][i]-sum[x1-1][y2][i]-sum[x2][y1-1][i]+sum[x1-1][y1-1][i];
			if(temp>0)
			cnt++;
		}
		cout<<cnt<<"\n"; 
	}
}