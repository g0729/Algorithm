#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;

	int res=0;
	int MIN=1e9;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin>>a;

		if(a<MIN)
		MIN=a;
		if(a-MIN>res)
		res=a-MIN;
	}
	
	cout<<res;
}