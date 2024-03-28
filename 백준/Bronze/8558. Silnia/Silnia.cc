#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	if(n>=5)
	{
		cout<<"0";
	}
	else
	{
		int temp=1;
		for (int i = 1; i <= n; i++)
		{
			temp*=i;
		}
		cout<<temp%10;
	}
}