#include<bits/stdc++.h>
using namespace std;
#define lint long long
int main()
{
	int n,t;
	cin>>n>>t;
	vector<lint>v;
	vector<lint>dp;
	for (int i = 0; i < n; i++)
	{
		lint x,s;
		cin>>x>>s;
		x=-(x+s*t);
		v.push_back(x);
	}
	dp.push_back(v[0]);
	for (int i = 1; i < n; i++)
	{
		if(dp.back()<=v[i])
		{
			dp.push_back(v[i]);
			continue;
		}
		auto temp=upper_bound(dp.begin(),dp.end(),v[i]);
		*temp=v[i];
	}
	cout<<dp.size();
}