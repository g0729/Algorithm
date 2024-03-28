#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long
int arr[4];

bool check(int cnt[])
{
	for (int i = 0; i < 4; i++)
	{
		if (arr[i] > cnt[i])
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

	string s;
	cin >> s;

	for (int i = 0; i < 4; i++)
	{
		cin >> arr[i];
	}

	int cnt[4] = {0};

	int res = 0;
	for (int i = 0; i < m; i++)
	{
		if (s[i] == 'A')
			cnt[0]++;
		else if (s[i] == 'C')
			cnt[1]++;
		else if (s[i] == 'G')
			cnt[2]++;
		else
			cnt[3]++;
	}

	if (check(cnt))
		res++;
	for (int i = m; i < s.length(); i++)
	{
		if (s[i] == 'A')
			cnt[0]++;
		else if (s[i] == 'C')
			cnt[1]++;
		else if (s[i] == 'G')
			cnt[2]++;
		else
			cnt[3]++;
		if (s[i - m] == 'A')
			cnt[0]--;
		else if (s[i - m] == 'C')
			cnt[1]--;
		else if (s[i - m] == 'G')
			cnt[2]--;
		else
			cnt[3]--;

		if (check(cnt))
			res++;
	}

	cout<<res;
	return 0;
}