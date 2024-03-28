#include<iostream>
using namespace std;
int** arr;
int** DP;
int min(int a, int b)
{
	return a < b ? a : b;
}
int main()
{
	int n;
	cin >> n;
	arr = new int*[n];
	DP = new int* [n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[3];
		DP[i] = new int[3];
	}
	for(int i = 0 ; i<n;i++)
		for (int q = 0; q < 3; q++)
			cin >> arr[i][q];
	for (int i = 0; i < 3; i++)
		DP[0][i] = arr[0][i];
	for (int i = 1; i < n; i++)
	{
		DP[i][0] = min(DP[i - 1][1], DP[i - 1][2]) + arr[i][0];
		DP[i][1]= min(DP[i - 1][0], DP[i - 1][2]) + arr[i][1];
		DP[i][2]=min(DP[i - 1][1], DP[i - 1][0]) + arr[i][2];
	}
	cout << min(min(DP[n - 1][0], DP[n - 1][1]), DP[n - 1][2]);
}