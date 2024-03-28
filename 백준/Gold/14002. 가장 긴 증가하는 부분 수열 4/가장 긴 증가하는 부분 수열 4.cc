#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int arr[MAX];
int n;
int dp[MAX];
int max_i;
stack <int>res;
int main()
{
	int cnt=0;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		cin>>arr[i];
	}
	for(int i = 0 ; i<n;i++)
	{
		dp[i]=1;
		for(int q = 0;q<i;q++)
		{
			if(arr[i]>arr[q])
			{
				dp[i]=max(dp[i],dp[q]+1);
			}
		}
		if(cnt<dp[i])
		{
		cnt=dp[i];
		max_i=i;
		}
	}
	int ccnt=cnt;
	res.push(arr[max_i]);
	cnt--;
	for(int i = max_i-1;i>=0;i--)
	{
		if(cnt==dp[i])
		{
			res.push(arr[i]);
			cnt--;
		}
		if(cnt==0)
		{
			break;
		}
	}
	cout<<ccnt<<"\n";
	while(!res.empty())
	{
		cout<<res.top()<<" ";
		res.pop();
	}
}
