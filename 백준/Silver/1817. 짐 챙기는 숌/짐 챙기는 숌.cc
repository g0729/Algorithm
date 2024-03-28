#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m;

	cin >> n >> m;

	int now = 0;
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;

		if (now + a <= m)
		{
			now += a;
		}
		else
		{

			now = a;
			res++;
		}
	}

	if(now>0)
	res++;
	cout << res;
}