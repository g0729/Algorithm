#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first)
		return a.second > b.second;
	return a.first < b.first;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<pair<int, int>>v(n);
	for (int i = 0; i < n; i++)
	{
		int a,b;
		cin>>a>>b;
		v[i]={a,b};
	}
	sort(v.begin(),v.end(),cmp);

	int cur=0;
	priority_queue<int,vector<int>,greater<int>>pq;

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