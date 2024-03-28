#include<iostream>
using namespace std;

int main()
{
	int n, m;
	int min6, min;
	cin >> n >> m;
	min6 = min = 1000;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		if (a < min6)
			min6 = a;
		if (b < min)
			min = b;
	}
	if (min6 == 0 || min == 0)
	{
		cout << "0";
		return 0;
	}
	if (min6 > 6*min)
	{
		cout << n * min;
	}
	else
	{
		if ((n % 6) * min > min6)
		{
			if (n % 6 == 0)
				cout << (n / 6) * min6;
			else
				cout << ((n / 6) + 1) * min6;
		}
		else
		{
			cout << (n / 6) * min6 + (n % 6) * min;
		}
	}
	
}