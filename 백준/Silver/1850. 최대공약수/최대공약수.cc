#include <bits/stdc++.h>
using namespace std;
#define lint long long

lint gcd(lint a, lint b)
{
	if(b==0)
	return a;
	else
	return gcd(b,a%b);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lint a,b;
	cin>>a>>b;
	lint temp =gcd(a,b);
	for (int i = 0; i < temp; i++)
	{
		cout<<"1";
	}
	
}