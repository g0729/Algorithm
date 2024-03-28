#include <bits/stdc++.h>
using namespace std;
#define MAX 50
vector<int>arr;
int n, m, l;
int ans = 100000;
int cnt(int dis)
{
	int res=0;
	for(int i=1;i<arr.size();i++)
	{
		res+=(arr[i]-arr[i-1])/dis;
		if((arr[i]-arr[i-1])%dis==0)
		res--;
	}
	return res;
}
int binsearch()
{
	int start = 1;
	int end = l ;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		int temp = cnt(mid);
		if (m < temp)
		{
			start = mid+1;

		}
		else
		{
			end = mid-1;
		}
	}
	return start;
}
int main()
{
	cin >> n >> m >> l;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin>>a;
		arr.push_back(a);
	}
	arr.push_back(0);
	arr.push_back(l);
	sort(arr.begin(),arr.end());
	ans=binsearch();
	cout << ans;
}