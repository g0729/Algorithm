#include <bits/stdc++.h>
using namespace std;

int main()
{
	int arr[41];

	int n;
	
	arr[1]=arr[2]=1;

	for (int i = 3; i <= 40; i++)
	{
		arr[i]=arr[i-1]+arr[i-2];
	}
	
	cin>>n;

	cout<<arr[n]<<" "<<n-2;
}