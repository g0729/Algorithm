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
	int cnt[2] = {0};

	string s;
	cin >> s;

	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'A')
			cnt[0]++;
		else
			cnt[1]++;
	}

	if (cnt[0] > cnt[1])
		cout << "A";
	else if (cnt[0] < cnt[1])
		cout << "B";
	else
		cout << "Tie";

	return 0;
}