#include<iostream>
#define lint  unsigned long long
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lint sum = 0;
	lint n;
	cin >> n;
	sum = n * (n - 1) / 2;
	lint count = 0;
	for (lint i = 0; i< n; i++)
	{
		lint a;
		cin >> a;
		count += a;
	}
	cout << count-sum;
}