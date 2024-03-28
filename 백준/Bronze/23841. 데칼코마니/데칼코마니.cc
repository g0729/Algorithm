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

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;

		for (int i = 0; i < m / 2; i++)
		{
			if (s[i] == '.' && s[m - i - 1] == '.')
				continue;
			else if (s[i] != '.')
			{
				s[m - i - 1] = s[i];
			}
			else
			{
				s[i] = s[m - i - 1];
			}
		}
		cout<<s<<"\n";
	}

	return 0;
}