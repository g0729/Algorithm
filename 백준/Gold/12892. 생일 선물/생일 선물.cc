#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,d;
	cin>>n>>d;
	vector<pair<long long,long long>>v(n);
	
	for (int i = 0; i < n; i++)
	{
		cin>>v[i].first>>v[i].second;
	}
	sort(v.begin(),v.end());
	long long sum=0;
	int start=0,end=0;
	long long res=0;
	while(end<n)
	{
		if(v[end].first-v[start].first<d)
		{
			sum+=v[end].second;
			end++;
			res=max(res,sum);
		}
		else
		{
			while(v[end].first-v[start].first>=d)
			{
				sum-=v[start].second;
				start++;
			}
		}
	}
	cout<<res;
}