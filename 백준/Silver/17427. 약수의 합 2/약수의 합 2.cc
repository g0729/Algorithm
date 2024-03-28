#include<bits/stdc++.h>
using namespace std;

#define lint long long

int main()
{
	int n;
	lint res=0;

	cin>>n;

	for (int i = 1; i <= n; i++)
	{
		res+=(lint)(n/i)*i;
	}
	
	cout<<res;
}