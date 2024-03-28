#include<bits/stdc++.h>
using namespace std;
int arr[200000];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int min=2000000000;
	int n;
	int ans[2];
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
	int start=0;
	int end=n-1;
	while(start<end)
	{
		int sum=arr[start]+arr[end];
		if(abs(sum)<min)
		{
			min=abs(sum);
			ans[0]=arr[start];
			ans[1]=arr[end];
		}
		if(sum<0)
		{
			start++;
		}
		else
		{
			end--;
		}
	}
	cout<<ans[0]<<" "<<ans[1];
}