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
	ll n;
	ll now = 1;
	int res = 1;
	cin >> n;

	if (n == 0)
	{
		cout << "0";
		return 0;
	}
	while (now < n)
	{
		now *= 2;
		res += 1;
	}

	cout<<res;
	return 0;
}