#include <bits/stdc++.h>
using namespace std;
int arr[10000];
int dis[10000];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr,arr+n);
	for (int i = 0; i < n-1; i++)
	{
		dis[i]=arr[i+1]-arr[i];
	}
	sort(dis,dis+n-1);
	int sum=0;
	for (int i = 0; i < n-k; i++)
	{
		sum+=dis[i];
	}
	cout<<sum;
}