#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	priority_queue<int,vector<int>,greater<int>>pq;
	int n,k;
	cin>>n>>k;
	vector<int>v(n);

	for (int i = 0; i < n; i++)
	{
		cin>>v[i];
	}
	if(k>=n)
	{
		int ans=0;
		for (int i = 0; i < n; i++)
		{
			ans=max(ans,v[i]);
		}
		cout<<ans;
		return 0;
	}
	sort(v.begin(),v.end(),cmp);

	for (int i = 0; i < k; i++)
	{
		pq.push(v[i]);
	}

	for (int i = k; i < n; i++)
	{
		int temp=pq.top()+v[i];
		pq.pop();
		pq.push(temp);
	}
	int temp=pq.size();
	for (int i = 0; i <temp-1; i++)
	{
		pq.pop();
	}
	
	cout<<pq.top();
}