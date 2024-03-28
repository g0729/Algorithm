#include <bits/stdc++.h>
using namespace std;

int main()
{
	int now;

	cin>>now;

	int time=1;

	while(1)
	{
		if(now==1)
		break;
		if(now%2==0)
		{
			now/=2;
		}
		else
		{
			now=now*3+1;
		}
		time++;
	}

	cout<<time;
}