#include <bits/stdc++.h>
using namespace std;
long long n, b;
vector<pair<long long, long long>> v;

bool cmp(pair<long long,long long>a,pair<long long,long long>b)
{
	return a.first+a.second<b.first+b.second;
}
long long check(long long target)
{
	long long cnt=1;
	long long bud=b-(v[target].first/2+v[target].second);
	if(bud<0)
	return 0;
	for (long long i = 0; i < n; i++)
	{
		if(i==target)
		continue;
		if(bud-(v[i].first+v[i].second)>=0)
		{
			bud=bud-v[i].first-v[i].second;
			cnt++;
		}
	}
	return cnt;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> b;
	for (long long i = 0; i < n; i++)
	{
		long long a, b;
		cin >> a>>b;
		v.push_back({a, b});
	}
	sort(v.begin(),v.end(),cmp);
	long long res=0;
	for (long long i = 0; i < n; i++)
	{
		if(check(i)>res)
		{
			res=check(i);
		}
	}
	cout<<res;
}