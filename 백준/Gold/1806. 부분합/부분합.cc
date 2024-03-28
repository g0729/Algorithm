#include<bits/stdc++.h>
using namespace std;
int arr[100000];
int main()
{
	int n,s;
	cin>>n>>s;
	for (int i = 0; i < n; i++)
	{
		cin>>arr[i];
	}
	int sum,start,end,res;
	start=sum=end=0;
	res=1000000;
	while(end<=n)
	{
		if(sum>=s)
		{
			res=min(res,end-start);
			sum-=arr[start];
			start++;
		}
		else
		{
			sum+=arr[end];
			end++;
		}
	}
	if(res==1000000)
	cout<<"0";
	else
	cout<<res;
}