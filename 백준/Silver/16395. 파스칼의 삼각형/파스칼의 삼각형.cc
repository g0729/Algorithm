#include<iostream>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	n = n - 1;
	k = k - 1;
	if (n / 2 < k)
		k = n - k;
	long long res = 1;
	for (int i = n; i > n - k; i--)
	{
		res = res * i / (n + 1 - i);
	}
	cout << res;
}