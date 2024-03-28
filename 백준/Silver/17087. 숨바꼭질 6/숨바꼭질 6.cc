#include<iostream>
#include<stdlib.h>
using namespace std;

int gcd(int a , int b)
{
	int large = a > b ? a : b;
	int small = a < b ? a : b;
	int temp = large % small;
	while (temp != 0)
	{
		large = small;
		small = temp;
		temp = large % small;
	}
	return small;
}
int main()
{
	int n, s;
	cin >> n >> s;
	int a;
	int* arr = new int[n];
	
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		arr[i] = abs(s - a);
	}
	if (n == 1)
		cout << abs(a - s);
	else

	{
		int res = gcd(arr[0], arr[1]);

		for (int i = 2; i < n - 1; i++)
		{
			res = gcd(res, arr[i]);
		}
		cout << res;
	}
}