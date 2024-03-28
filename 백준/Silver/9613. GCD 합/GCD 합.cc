#include<iostream>
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
	int t;
	cin >> t;
	int* arr;
	for (int i = 0; i < t; i++)
	{
		int n;
		long long sum = 0;
		cin >> n;
		arr = new int[n];
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				sum += gcd(arr[i], arr[j]);
			}
		}
		cout << sum << endl;
	}
}