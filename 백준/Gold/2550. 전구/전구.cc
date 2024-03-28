#include <bits/stdc++.h>
using namespace std;
#define MAX 10001
int arr_a[MAX];
int arr_b[MAX];
int d[MAX];
vector<int> v;
vector<int> dp;
vector<int>ans;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr_a[i];
	}

	for (int i = 1; i <= n; i++)
	{
		cin >> arr_b[i];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int q = 1; q <= n; q++)
		{
			if (arr_a[i] == arr_b[q])
			{
				v.push_back(q);
				continue;
			}
		}
	}
	dp.push_back(v[0]);
	for(int i=1;i<v.size();i++)
	{
		if(dp.back()<v[i])
		{
			dp.push_back(v[i]);
			d[i]=dp.size()-1;
			continue;
		}
		auto temp =lower_bound(dp.begin(),dp.end(),v[i]);
		*temp=v[i];
		d[i]=temp-dp.begin();
	}
	int cnt=dp.size()-1;
	for(int i=n-1;i>=0;i--)
	{
		if(cnt==d[i])
		{
			ans.push_back(arr_a[i+1]);
			cnt--;
		}
	}
	cout<<dp.size()<<"\n";
	sort(ans.begin(),ans.end());
	for (int i = 0; i < ans.size(); i++)
	{
		cout<<ans[i]<<" ";
	}
	
}