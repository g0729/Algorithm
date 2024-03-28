#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	int* length = new int[n];
	int* backlength = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		length[i] = 1;
		for (int q = 0; q < i; q++)
		{
			if (arr[i] > arr[q])
				length[i] = max(length[i], length[q] + 1);
		}
	}
	for (int i = 0; i < n / 2; i++)
	{
		int temp = arr[i];
		arr[i] = arr[n - i - 1];
		arr[n - 1 - i] = temp;
	}
	for (int i = 0; i < n; i++)
	{
		backlength[i] = 1;
		for (int q = 0; q < i; q++)
		{
			if (arr[i] > arr[q])
				backlength[i] = max(backlength[i], backlength[q] + 1);
		}
	}
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		res = max(res, length[i] + backlength[n - 1 - i]);
	}
	cout << res-1;
}