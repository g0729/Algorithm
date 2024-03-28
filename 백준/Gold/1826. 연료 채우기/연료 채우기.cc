#include<bits/stdc++.h>
using namespace std;

int main()
{
	priority_queue<int>pq;
	int n;
	cin>>n;
	vector<pair<int,int>>v(n);
	for (int i = 0; i < n; i++)
	{
		cin>>v[i].first>>v[i].second;
	}
	sort(v.begin(),v.end());
	int loc,fuel;
	cin>>loc>>fuel;
	int now=0;
	int cnt=0;
	while(loc>fuel)
	{
		while(v[now].first<=fuel&&now<n)
		{
			pq.push(v[now].second);
			now++;
		}
		if(!pq.empty())
		{
			fuel+=pq.top();
			pq.pop();
			cnt++;
		}
		else if(v[now].first>fuel||now==n)
		{
			cout<<"-1";
			return 0;
		}
	}
	cout<<cnt;	
}