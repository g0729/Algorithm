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

	string s;
	cin >> s;

	vector<bool> v(26);

	for (int i = 0; i < s.length(); i++)
	{
		v[s[i] - 'A'] = true;
	}

	if (v['M' - 'A'] && v['O' - 'A'] && v['B' - 'A'] && v['I' - 'A'] && v['S' - 'A'])
		cout << "YES";
	else
		cout << "NO";
		
	return 0;
}