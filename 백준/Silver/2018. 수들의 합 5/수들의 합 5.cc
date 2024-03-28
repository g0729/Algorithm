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

	int start, end, sum;
	start = end = sum = 0;

	int res = 0;
	while (start <= end && end <= n)
	{
		if (sum < n)
		{
			end++;
			sum += end;
		}
		else
		{
			if (sum == n)
				res++;
			start++;
			sum -= start;
		}
	}

	cout << res;
	return 0;
}