#include <bits/stdc++.h>
using namespace std;
#define MAX 2002
int n, m;
int arr_a[MAX];
int arr_b[MAX];
bool meet[MAX][MAX];
int lis[MAX][MAX];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<pair<int, int>> v;
	vector<int>dp;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		int temp;
		cin >> temp;
		arr_a[temp] = i;
	}
	for (int i = 1; i <= m; i++)
	{
		int temp;
		cin >> temp;
		arr_b[temp] = i;
	}
	int k;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int start, end;
		cin >> start >> end;
		meet[arr_a[start]][arr_b[end]]=true;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int q = 1; q <= m; q++)
		{
			if(meet[i][q])
			{
				lis[i+1][q+1]=lis[i][q]+1;
			}
			else
			{
				lis[i+1][q+1]=max(lis[i+1][q],lis[i][q+1]);
			}
		}
		
	}
	cout<<k-lis[n+1][m+1];

}