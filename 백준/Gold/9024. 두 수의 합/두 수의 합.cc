#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		vector<int>v(n);
		for (int i = 0; i < n; i++)
		{
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		int start=0;
		int end=v.size()-1;
		int min=999999999;
		int cnt=0;
		while(start<end)
		{
			int sum=v[start]+v[end];
			if(sum>k)
			end--;
			else
			start++;
			if(abs(k-sum)<min)
			{
				min=abs(k-sum);
				cnt=1;
			}
			else if(abs(k-sum)==min)
			{
				cnt++;
			}
		}
		cout<<cnt<<"\n";
	}
}