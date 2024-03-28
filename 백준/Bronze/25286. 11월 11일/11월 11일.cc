#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long
#define MOD 1000000007

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	int t;
	cin >> t;

	while (t--)
	{
		int a, b;
		cin >> a >> b;

		if (b == 1)
			cout << a - 1 << " 12 31";
		else
		{
			cout << a << " " << b - 1 << " ";
			if (b == 3 && ((a % 100 != 0 && a % 4 == 0) || a % 400 == 0))
				cout << "29";
			else
			{
				cout << month[b - 1];
			}
		}
		cout << "\n";
	}
	return 0;
}