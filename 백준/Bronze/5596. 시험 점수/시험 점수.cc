#include <bits/stdc++.h>
using namespace std;

int main()
{
	int s,t;
	s=t=0;

	for (int i = 0; i < 4; i++)
	{
		int a;
		cin>>a;
		s+=a;
	}

	for (int i = 0; i < 4; i++)
	{
		int a;
		cin>>a;
		t+=a;
	}
	
	cout<<max(s,t);
	
}