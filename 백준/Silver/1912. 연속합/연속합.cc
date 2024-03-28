#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int* arr = new int[n + 1];
	int* DP = new int[n + 1];
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	DP[1] =arr[1];
	res = DP[1];
	for (int i = 1; i <= n; i++)
	{
		DP[i] = max(arr[i], DP[i - 1] + arr[i]);
		res = max(res, DP[i]);
	}
	cout << res;
}