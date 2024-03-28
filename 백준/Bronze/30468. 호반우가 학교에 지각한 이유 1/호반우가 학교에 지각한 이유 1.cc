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

	int sum = 0;
	for (int i = 0; i < 4; i++)
	{
		int a;
		cin >> a;
		sum += a;
	}
	int n;
	cin >> n;

	cout << max(0, n * 4 - sum);

	return 0;
}