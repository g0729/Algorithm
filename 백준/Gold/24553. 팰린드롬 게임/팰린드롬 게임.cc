#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin>>t;

	while(t--)
	{
		lint n;
		cin>>n;

		if(n%10==0)
			cout<<"1";
		else
			cout<<"0";

		cout<<"\n";
	}
	return 0;
}