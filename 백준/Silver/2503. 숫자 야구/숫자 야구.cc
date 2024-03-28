#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

struct Int3
{
	int a, b, c;
	Int3(int a, int b, int c) : a(a), b(b), c(c){};
};
vector<Int3> v;
bool check[1000];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		Int3 temp(a, b, c);

		v.push_back(temp);
	}

	for (int i = 123; i < 1000; i++)
	{
		string temp = to_string(i);

		if (temp[0] == temp[1] || temp[0] == temp[2] || temp[1] == temp[2])
			check[i] = true;
		if (temp[1] == '0' || temp[2] == '0')
			check[i] = true;
	}

	for (int i = 0; i < n; i++)
	{
		string num = to_string(v[i].a);
		int s = v[i].b;
		int b = v[i].c;

		for (int j = 123; j < 1000; j++)
		{
			int tempS = 0;
			int tempB = 0;

			if (check[j])
				continue;

			string temp = to_string(j);
			for (int p = 0; p < 3; p++)
			{
				for (int q = 0; q < 3; q++)
				{
					if (num[p] == temp[q])
					{
						if (p == q)
							tempS++;
						else
							tempB++;
					}
				}
			}

			if (tempS != s || tempB != b)
				check[j] = true;
		}
	}

	int res = 0;

	for (int i = 123; i < 1000; i++)
	{
		if (!check[i])
			res++;
	}

	cout << res;

	return 0;
}