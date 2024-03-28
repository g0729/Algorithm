#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll a, b;
	cin >> a >> b;

	if(b==1)
		cout<<"-1";
	else
	{
		cout<<((a*b)+(b-2))/(b-1);
	}
	return 0;
}