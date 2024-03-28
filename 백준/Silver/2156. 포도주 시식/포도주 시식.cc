#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	int* DP = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	DP[0] = arr[0];
	DP[1] = arr[1] + arr[0];
	
	for (int i = 2; i < n; i++)
	{
		DP[i] = max(DP[i - 2], arr[i - 1] + DP[i - 3]) + arr[i];
		DP[i] = max(DP[i - 1], DP[i]);
	}
	

	cout << DP[n-1];
}