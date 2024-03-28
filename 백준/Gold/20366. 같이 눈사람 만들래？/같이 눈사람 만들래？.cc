#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	int res = 1e9;
	for (int i = 0; i < n - 3; i++)
	{
		for (int j = i + 3; j < n; j++)
		{
			int elsa = v[i] + v[j];
			int start = i + 1;
			int end = j - 1;
			while (start < end)
			{
				int anna = v[start] + v[end];
				res = min(res, abs(anna - elsa));
				if (anna - elsa > 0)
				{
					end--;
				}
				else
				{
					start++;
				}
			}
		}
	}
	cout<<res;
}