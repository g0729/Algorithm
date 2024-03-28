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

	int n;
	cin >> n;

	n = n % 8;

	if (n >= 1 && n <= 5)
		cout << n;
	else if (n == 6)
		cout << "4";
	else if (n == 7)
		cout << "3";
	else if (n == 0)
		cout << "2";
	return 0;
}