#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> v;
	int n;
	int check = 0;
	cin >> n;
	while (n--)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size() - 1; i++)
	{
		if (v[i] + 1 == v[i + 1])
		{
			auto temp = lower_bound(v.begin() + i, v.end(), v[i] + 2);
			if (temp == v.end())
			{
				auto up = upper_bound(v.begin() + i, v.end(), v[i]);
				auto down = lower_bound(v.begin() + i - check, v.end(), v[i]);
				while (up != v.end())
				{
					swap(*down, *up);
					up++;
					down++;
				}
			}
			else
			{
				swap(*temp, v[i + 1]);
			}
			check = 0;
		}
		else
		{
			if (v[i] == v[i + 1])
				check++;
		}
	}
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
}