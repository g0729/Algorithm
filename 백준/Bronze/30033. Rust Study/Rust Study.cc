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
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int res = 0;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		if (v[i] <= a)
			res++;
	}

	cout << res;

	return 0;
}