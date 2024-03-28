#include <bits/stdc++.h>
using namespace std;


int main()
{
	map<string, int> m = {{"Mon", 1}, {"Tue", 2},{"Wed", 3}, {"Thu", 4}, {"Fri", 5}};

	int t, n;
	cin >> t >> n;

	int res = 0;
	for (int i = 0; i < n; i++)
	{
		string from_day, from_time;
		string to_day, to_time;

		cin >> from_day >> from_time >> to_day >> to_time;

		int sum = m[to_day] * 24 + stoi(to_time);
		sum -= m[from_day] * 24 + stoi(from_time);

		res += sum;
	}

	res = t - res;

	if (res > 48)
		cout << "-1";
	else if (res <= 0)
		cout << "0";
	else
		cout << res;
}