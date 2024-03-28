#include<bits/stdc++.h>
using namespace std;
#define lint long long
#define MOD 1000000007
lint n;
lint mypow(int base,lint a)
{
	if(a==0)
		return 1;
	lint temp = mypow(base,a/2);
	lint ans =(temp*temp)%MOD;
	if(a%2==0)
	{
		return ans;
	}
	else
	{
		return (base*ans)%MOD;
	}
}
int main()
{
	cin>>n;
	if(n==0)
	{
		cout<<"1";
		return 0;
	}

	lint res= mypow(2,n-1);
	cout<<res;
}