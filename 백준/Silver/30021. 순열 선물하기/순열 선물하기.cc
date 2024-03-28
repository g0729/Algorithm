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

	int n;
	cin >> n;

	if (n == 1)
	{
		cout << "YES\n1";
		return 0;
	}
	if (n == 2)
	{
		cout << "NO";
		return 0;
	}
	if (n == 3)
	{
		cout << "YES\n";
		cout << "1 3 2";
		return 0;
	}

	cout << "YES\n";
	cout << "1 3 2 ";

	for (int i = 4; i <= n; i++)
	{
		cout << i << " ";
	}

	return 0;
}
