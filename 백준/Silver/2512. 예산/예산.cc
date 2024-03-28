#include <bits/stdc++.h>
using namespace std;
int arr[10000];
int n, m;

bool check(int target)
{
	int res=0;
	for (int i = 0; i < n; i++)
	{
		if(arr[i]<=target)
		{
			res+=arr[i];
		}
		else
		{
			res+=target;
		}
	}
	if(res<=m)
	return true;
	else
	return false;
}
int binsearch(int temp)
{
	int left,right;
	left=0;
	right=temp+1;
	while(left+1<right)
	{
		int mid=(left+right)/2;
		if(check(mid))
		{
			left=mid;
		}
		else
		{
			right=mid;
		}
	}
	return left;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	int temp=0;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		temp=max(temp,arr[i]);
	}
	cin >> m;
	int ans=binsearch(temp);
	cout<<ans;
}