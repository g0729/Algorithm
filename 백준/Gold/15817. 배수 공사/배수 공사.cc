#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, x;
	cin >> n >> x;
	vector<int> v(x + 1);

	v[0]=1;
	
	for (int i = 0; i < n; i++)
	{
		int l, c;

		cin >> l >> c;

		for (int j = x; j > 0; j--)
		{
			int sum = 0;

			for (int k = 0; k < c; k++)
			{
				sum += l;
				if (j - sum >= 0)
					v[j] += v[j - sum];
				else
					break;
			}
		}
	}

	cout<<v[x];
	return 0;
}