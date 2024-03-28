#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

bool check(int n)
{
	string s = to_string(n);

	for (int i = 0; i < s.length() / 2 + 1; i++)
	{
		int opposite = s.length() - i - 1;
		if (s[i] == '1' || s[i] == '8' || s[i] == '0')
		{
			if (s[i] != s[opposite])
				return false;
		}
		else if (s[i] == '6')
		{
			if (s[opposite] != '9')
				return false;
		}
		else if (s[i] == '9')
		{
			if (s[opposite] != '6')
				return false;
		}
		else
			return false;
	}

	return true;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	int res = 0;
	for (int i = n; i <= m; i++)
	{
		if (check(i))
		{
			res++;
		}
	}

	cout << res;
	return 0;
}