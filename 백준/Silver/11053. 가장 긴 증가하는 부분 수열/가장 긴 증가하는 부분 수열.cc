#include<iostream>
using namespace std;

int main()
{
	int n;
	int res = 0;
	cin >> n;
	int* dp = new int[n];
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin>>arr[i];
	}
	if (n == 1)
	{
		cout << "1";
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;
		for (int q = 0; q < i; q++)
		{
			if (arr[i] > arr[q])
			{
				dp[i] = max(dp[i], dp[q]+1);
			}
			res = max(res, dp[i]);
		}
	}
	cout << res;
}