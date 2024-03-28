	#include<bits/stdc++.h>
	using namespace std;
	#define MAX 1000000
	int pp[MAX];
	stack<int>ans;
	int main()
	{
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
		int n;
		cin>>n;
		vector<int>dp;
		vector<int>v;
		for (int i = 0; i < n; i++)
		{
			int a;
			cin>>a;
			v.push_back(a);
		}
		dp.push_back(v[0]);
		for(int i = 1 ;i<v.size();i++)
		{
			if(dp.back()<v[i])
			{
				dp.push_back(v[i]);
				pp[i]=dp.size()-1;
				continue;
			}
			auto temp=lower_bound(dp.begin(),dp.end(),v[i]);
			*temp=v[i];
			pp[i]=temp-dp.begin();
		}
		int cnt=dp.size()-1;
		for(int i=n-1;i>=0;i--)
		{
			if(cnt==pp[i])
			{
				ans.push(v[i]);
				cnt--;
			}
		}
		cout<<dp.size()<<"\n";
		while(!ans.empty())
		{
			cout<<ans.top()<<" ";
			ans.pop();
		}
	}