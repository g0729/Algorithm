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

	int n, m;
	cin >> n >> m;
	if (m <= 2)
		cout << "NEWBIE!";
	else if (m <= n)
		cout << "OLDBIE!";
	else
		cout << "TLE!";

	return 0;
}