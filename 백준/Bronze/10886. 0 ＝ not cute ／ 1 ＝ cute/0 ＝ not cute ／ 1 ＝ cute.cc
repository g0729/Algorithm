#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int cnt0,cnt1;
	cnt0=cnt1=0;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin>>a;
		if(a)
		cnt1++;
		else
		cnt0++;
	}
	if(cnt1>cnt0)
	cout<<"Junhee is cute!";
	else
	cout<<"Junhee is not cute!";
}