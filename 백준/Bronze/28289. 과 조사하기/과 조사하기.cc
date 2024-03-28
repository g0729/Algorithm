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

	vector<int> v(4);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 1)
			v[3]++;
		else if (b == 1 || b == 2)
			v[0]++;
		else if (b == 3)
			v[1]++;
		else if (b == 4)
			v[2]++;
	}

	for (int i = 0; i < 4; i++)
	{
		cout << v[i] << "\n";
	}

	return 0;
}