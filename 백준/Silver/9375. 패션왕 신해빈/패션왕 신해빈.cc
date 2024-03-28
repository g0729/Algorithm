#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		map<string, int>ma;
		int n;
		cin >> n;
		string name, kind;
		for (int i = 0; i < n; i++)
		{
			cin >> name >> kind;
			if (ma.find(kind) == ma.end())
			{
				ma.insert({ kind,1 });
			}
			else
			{
				ma[kind]++;
			}
		}
		int res = 1;
		for (auto i : ma)
		{
			res *= (i.second + 1);
		}
		cout << res - 1 << "\n";
	}
}