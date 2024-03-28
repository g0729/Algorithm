#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

vector<int> cnt(26);
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		cnt[s[0] - 'a']++;
	}

	int t = *max_element(cnt.begin(), cnt.end());

	if (n == t)
		cout << "1";
	else
		cout << "0";
	return 0;
}