#include<iostream>
using namespace std;

int main()
{
	int n;
	long long k;
	cin >> n >> k;
	int* arr = new int[n];
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = n - 1; i >= 0; i--)
	{
		res += k / arr[i];
		k = k % arr[i];
	}
	cout << res;
}