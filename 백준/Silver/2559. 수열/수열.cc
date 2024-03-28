#include<bits/stdc++.h>
using namespace std;
int arr[100000];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	int start=0;
	int res=0;

	for (int i = 0; i < n; i++)
	{
		cin>>arr[i];
	}
	
	for (int i = 0; i < k; i++)
	{
		res+=arr[i];
	}
	int sum=res;
	for (int i = k; i < n; i++)
	{
		sum+=arr[i];
		sum-=arr[i-k];
		res=max(sum,res);
	}
	cout<<res;

}