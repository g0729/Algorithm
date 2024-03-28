#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 300000

int sum[26][MAX];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;

	for (int i = 1; i <= s.length(); i++)
	{
		for (int j = 0; j < 26; j++)
		{
			sum[j][i] = sum[j][i - 1];
		}
		sum[s[i - 1] - 'a'][i]++;
	}
	int n;
	cin >> n;
	while (n--)
	{
		char a;
		int b, c;
		cin >> a >> b >> c;
		cout << sum[a - 'a'][c + 1] - sum[a - 'a'][b] << "\n";
	}
	return 0;
}