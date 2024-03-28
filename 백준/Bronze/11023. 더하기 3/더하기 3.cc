#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	int res=0;
	while(1)
	{
		cin>>n;

		if(cin.eof())
		break;
		res+=n;
	}

	cout<<res;
}