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

	int n, k;
	string s;
	cin >> n >> s >> k;

	if (s == "annyong")
	{
		if (k % 2 == 1)
			cout << k;
		else
		{
			cout << k - 1;
		}
	}
	else
	{
		if (k % 2 == 0)
			cout << k;
		else
		{
			if (k == 1)
			{
				cout << "2";
			}
			else
			{
				cout << k - 1;
			}
		}
	}
	return 0;
}