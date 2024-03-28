#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	vector<pair<int,int>>v(n);
	for (int i = 0; i < n; i++)
	{
		cin>>v[i].second>>v[i].first;
	}
	sort(v.begin(),v.end());
	priority_queue<int,vector<int>,greater<int>>pq;
	int cur=0;
	for (int i = 0; i < n; i++)
	{
		if(cur<v[i].first)
		{
			pq.push(v[i].second);
			cur++;
		}
		else
		{
			if(pq.top()<v[i].second)
			{
				pq.pop();
				pq.push(v[i].second);
			}
		}
	}
	int sum=0;
	while(!pq.empty())
	{
		sum+=pq.top();
		pq.pop();
	}
	cout<<sum;
}