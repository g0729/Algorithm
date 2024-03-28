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

	if (a % 2 == 0 || b % 2 == 0)
		cout << "0";
	else
		cout << min(a, b);
	return 0;
}