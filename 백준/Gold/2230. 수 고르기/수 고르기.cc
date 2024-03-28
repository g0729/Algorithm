	#include<bits/stdc++.h>
	using namespace std;
	long long arr[100000];
	int main()
	{
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		long long n,m;
		cin>>n>>m;

		for (int i = 0; i < n; i++)
		{
			cin>>arr[i];
		}
		int start=0;
		int end=0;
		sort(arr,arr+n);
		long long res=1e10;
		while(end<n)
		{
			int sum=abs(arr[end]-arr[start]);
			if(sum>=m)
			{
				res=min(res,abs(arr[end]-arr[start]));
				start++;
			}
			else
			{
				end++;
			}
		}

		cout<<res;
	}