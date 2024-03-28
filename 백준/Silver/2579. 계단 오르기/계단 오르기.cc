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
	DP[1] = arr[1]+arr[0];
	DP[2] = max(arr[0],arr[1]) + arr[2];
	for (int i = 3; i < n; i++)
	{
		DP[i] = max(DP[i - 2], arr[i-1] + DP[i - 3])+arr[i];
	}
	cout << DP[n-1];
	
}