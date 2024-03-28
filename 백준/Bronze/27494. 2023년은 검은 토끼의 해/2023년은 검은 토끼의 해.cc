#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

int res = 0;
void check(int num)
{
	string s = to_string(num);

	string year = "2023";

	int cnt = 0;
	for (int i = 0; i < s.length(); (i++))
	{
		if (s[i] == year[cnt])
		{
			cnt++;
		}

		if (cnt >= 4)
		{
			res++;
			return;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 2023; i <= n; i++)
	{
		check(i);
	}

	cout << res;
	return 0;
}