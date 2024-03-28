#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main()
{
	int n;
	cin >> n;

	int arr[3];
	if (n == 0)
	{
		cout << "0";
		return 0;
	}
	else if (n == 1)
	{
		cout << "1";
		return 0;
	}
	arr[0] = 0;
	arr[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		arr[2] = (arr[0] + arr[1]) % MOD;
		arr[0] = arr[1];
		arr[1] = arr[2];
	}

	cout << arr[2];
}