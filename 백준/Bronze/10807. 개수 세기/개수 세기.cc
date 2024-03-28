#include <bits/stdc++.h>
using namespace std;

int main()
{
	int arr[100];
	int n;
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		cin>>arr[i];
	}
	int v;
	int res=0;
	cin>>v;
	for (int i = 0; i < n; i++)
	{
		if(arr[i]==v)
		res++;
	}
	cout<<res;
}