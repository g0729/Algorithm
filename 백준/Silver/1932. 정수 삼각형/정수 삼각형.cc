#include<iostream>
using namespace std;
int max(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	short** arr;
	int** DP;
	cin >> n;
	arr = new short* [n];
	DP = new int* [n];
	for (int i = 0; i < n; i++)
	{
		DP[i] = new int[n];
		arr[i] = new short[n];
	}
	for (int i = 0; i < n; i++)
	{
		for (int q = 0; q < i + 1; q++)
			cin >> arr[i][q];
	}
	DP[0][0] = arr[0][0];
	for (int i = 1; i < n; i++)
	{
		DP[i][0] = DP[i - 1][0] + arr[i][0];
		DP[i][i] = DP[i - 1][i - 1] + arr[i][i];
		for (int q = 1; q < i; q++)
		{
			DP[i][q] = max(DP[i - 1][q-1], DP[i - 1][q]) + arr[i][q];
		}
	}	
	int res=0;
	for (int i = 0; i < n; i++)
	{
		if (res < DP[n-1][i])
			res = DP[n-1][i];
	}
	cout << res;
}