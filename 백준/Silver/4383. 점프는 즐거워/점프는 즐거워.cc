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

	while (1)
	{
		int n;
		cin >> n;

		if (cin.eof())
			break;

		vector<int> v(n);
		vector<bool> check(n);

		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}

		for (int i = 0; i < n - 1; i++)
		{
			check[abs(v[i] - v[i + 1])] = true;
		}
		bool flag = true;
		for (int i = 1; i < n; i++)
		{
			if (!check[i])
			{
				cout << "Not jolly" ;
				flag = false;
				break;
			}
		}

		if (flag)
			cout << "Jolly";
		cout << "\n";
	}
	return 0;
}