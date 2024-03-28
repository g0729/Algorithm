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

	int t;
	cin >> t;

	while (t--)
	{
		int m;
		cin >> m;
		multiset<int> ms;

		while (m--)
		{
			char c;
			int a;
			cin >> c >> a;

			if (c == 'I')
				ms.insert(a);
			else
			{
				if (ms.empty())
					continue;
				if (a == -1)
					ms.erase(ms.begin());
				else
				{
					auto iter = ms.end();
					iter--;
					ms.erase(iter);
				}
			}
		}
		if (ms.empty())
			cout << "EMPTY";
		else
		{
			auto iter = ms.end();
			iter--;

			cout << *iter << " " << *ms.begin();
		}
		cout << "\n";
	}
	return 0;
}