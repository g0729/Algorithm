#include<iostream>
using namespace std;

int main()
{
	int sum, a;
	for (int i = 0; i < 10; i++)
	{
		cin >> a;
		if (i == 0)
		{
			sum = a;
			continue;
		}
		sum -= a;
	}
	cout << sum;
}