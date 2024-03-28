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

	stack<int> s;

	int n;
	cin >> n;

	while (n--)
	{
		int a;
		cin >> a;

		if (a == 1)
		{
			int b;
			cin >> b;
			s.push(b);
		}
		else if (a == 2)
		{
			if (s.empty())
				cout << "-1\n";
			else
			{
				cout << s.top() << "\n";
				s.pop();
			}
		}
		else if (a == 3)
		{
			cout << s.size() << "\n";
		}
		else if (a == 4)
		{
			cout << s.empty() << "\n";
		}
		else if (a == 5)
		{
			if (s.empty())
				cout << "-1\n";
			else
				cout << s.top() << "\n";
		}
	}
	return 0;
}