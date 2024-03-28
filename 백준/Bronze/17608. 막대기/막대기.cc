#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
int arr[MAX];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	stack<int>s;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	s.push(arr[n-1]);
	for(int i=n-2;i>=0;i--)
	{
		if(arr[i]>s.top())
		{
			s.push(arr[i]);
		}
	}
	cout<<s.size();
}