#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
int arr[MAX];

int main()
{
	int n,m;
	int res=0;
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		cin>>arr[i];
	}
	cin>>m;
	sort(arr,arr+n);
	int start=0;
	int end=n-1;
	while(start<end)
	{
		int sum=arr[start]+arr[end];
		if(sum==m)
		res++;
		if(sum>=m)
		{
			end--;
		}
		else
		{
			start++;
		}
	}	
	cout<<res;
	
}