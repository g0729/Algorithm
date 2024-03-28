#include<iostream>
using namespace std;
int f(int a, int k)
{
	int ca = 0;
	int n = 1;

	if (k == 5)
	{
		while (a > 0)
		{
			if (a % 10 == 5)
			{
				ca += 6 * n;
			}
			else
			{
				ca += (a % 10) * n;
			}
			a = a / 10;
			n = n * 10;
		}
	}
	else
	{
		while (a > 0)
		{
			if (a % 10 == 6)
			{
				ca += 5 * n;
			}
			else
			{
				ca += (a % 10) * n;
			}
			a = a / 10;
			n = n * 10;
		}
	}
	return ca;
}
int main()
{
	int a, b;
	cin >> a >> b;
	int min, max;
	min = f(a, 6) + f(b, 6);
	max = f(a, 5) + f(b, 5);
	cout << min << " " << max;
}