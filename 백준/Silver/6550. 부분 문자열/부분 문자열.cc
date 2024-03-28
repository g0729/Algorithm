#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s, t;
	while (1)
	{
		cin >> s >> t;
		if (cin.eof())
			break;
		int idx = 0;
		bool flag = false;
		for (int i = 0; i < t.length(); i++)
		{
			if (t[i] == s[idx])
				idx++;
			if (idx == s.length())
			{
				flag = true;
				break;
			}
		}
		if (flag)
			cout << "Yes";
		else
			cout << "No";

		cout << "\n";
	}
	return 0;
}