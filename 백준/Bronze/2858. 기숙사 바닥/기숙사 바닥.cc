#include <bits/stdc++.h>
using namespace std ;

int main()
{
	int a,b;

	cin>>a>>b;

	int lw=a+b;

	for(int i = 1;;i++)
	{
		if(lw%i==0)
		{
			int l=lw/i;
			if(2*l+2*i-4==a&&(l-2)*(i-2)==b)
			{
				cout<<l<<" "<<i;
				return 0;
			}
		}
	}
}