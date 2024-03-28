#include<bits/stdc++.h>
using namespace std;
#define MAX 501
#define INF 999999999
int n;
int dp[MAX][MAX];
vector<pair<int,int>>v(MAX);
int main()
{
	cin>>n;
	for (int i = 1; i <= n; i++)
	{
		int a,b;
		cin>>a>>b;
		v[i]={a,b};
	}
	
	for(int d=1;d<=n;d++)
	{
		for(int q = 1;q+d<=n;q++)
		{
			int end=q+d;
			dp[q][end]=INF;
			for(int mid=q;mid<end;mid++)
			{
				dp[q][end]=min(dp[q][end],dp[q][mid]+dp[mid+1][end]+v[q].first*v[mid].second*v[end].second);
			}
		}
	}
	cout<<dp[1][n];
}