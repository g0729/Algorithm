#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
	if(b==0)
	return a;
	else
	return gcd(b,a%b);
}

int main()
{
	int n;
	cin>>n;

	int arr[3];

	for (int i = 0; i < n; i++)
	{
		cin>>arr[i];
	}
	
	int res;

	res=gcd(arr[0],arr[1]);

	if(n==3)
	res=gcd(res,arr[2]);

	for (int i = 1; i <= res; i++)
	{
		if(res%i==0)
		cout<<i<<"\n";
	}
	
}