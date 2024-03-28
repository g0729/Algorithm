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

	int n, a, b;
	cin >> n >> a >> b;

	if (n > b)
		cout << "Bus";
	else
	{
		if (a < b)
			cout << "Bus";
		else if (a > b)
			cout << "Subway";
		else
			cout << "Anything";
	}
	return 0;
}