#include<bits/stdc++.h>
using namespace std;
#define MOD 10007
int main()
{
	int n;
	cin>>n;
	
	if(n<=4)
	{
		cout<<n;
		return 0;
	}
	int cnt3=n/3-1;
	int temp=n%3+3;
	if(temp==5)
	{
		cnt3++;
		temp=2;
	}
	int res=1;
	for (int i = 0; i < cnt3; i++)
	{
		res=(res*3)%MOD;
	}
	cout<<(res*temp)%MOD;
}