#include <bits/stdc++.h>
using namespace std;

int mypow(int a)
{
	int b=a;
	for (int i = 0; i <4 ; i++)
	{
		b*=a;
	}
	return b;
}
int main()
{
	string s;
	cin>>s;
	int res=0;
	for (int i = 0; i < 5; i++)
	{
		res+=mypow(s[i]-'0');
	}
	cout<<res;
}