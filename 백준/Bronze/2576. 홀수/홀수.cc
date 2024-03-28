#include<iostream>
using namespace std;

int main()
{
	int n, min, sum;
	min = 100; sum = 0;
	for (int i = 0; i < 7; i++)
	{
		
		cin >> n;
		if (n % 2 == 0)
			continue;
		if (min > n)
			min = n;
		sum += n;
	}
	if (sum == 0)
		cout << "-1";
	else
	cout << sum << endl << min;
}