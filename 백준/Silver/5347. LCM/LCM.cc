#include <bits/stdc++.h>
using namespace std;

#define lint long long
lint gcd(lint a, lint b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}
int main()
{
	lint n;
	cin>>n;

	while(n--)
	{
		lint a,b;
		cin>>a>>b;
		lint GCD=gcd(a,b);

		cout<<a*b/GCD<<endl;
	}
}