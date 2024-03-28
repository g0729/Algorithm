#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

lint gcd(lint a, lint b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<lint> v;

	while (1)
	{

		lint a;
		cin >> a;
		if(cin.eof())
		break;
		v.push_back(a);
	}

	lint res = 0;
	for (int i = 0; i < v.size() - 1; i++)
	{
		for (int j = i + 1; j < v.size(); j++)
		{
			lint temp = gcd(v[i], v[j]);

			res = max(temp, res);
		}
	}

	cout << res;

	return 0;
}