#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

int max(int arr[])
{
	int res = max(arr[0], arr[1]);
	res = max(res, arr[2]);

	return res;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int seed, y;
	cin >> seed >> y;

	int arr[11];

	arr[0] = seed;

	for (int i = 1; i <= y; i++)
	{
		int next[3] = {
			0,
		};

		next[0] = arr[i - 1] + arr[i - 1] * 0.05;

		if (i >= 3)
			next[1] = arr[i - 3] + arr[i - 3] * 0.2;
		if (i >= 5)
			next[2] = arr[i - 5] + arr[i - 5] * 0.35;

		arr[i] = max(next);
	}

	cout << arr[y];
	return 0;
}