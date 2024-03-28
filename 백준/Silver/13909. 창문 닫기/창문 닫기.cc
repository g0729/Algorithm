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
	cin >> n;

	ll now = 1;
	ll res = 0;
	while (now * now <= n)
	{
		res++;
		now++;
	}

	cout << res;
	return 0;
}