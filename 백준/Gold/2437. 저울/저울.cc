#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	if (arr[0] != 1)
	{
		cout << "1";
	}
	else
	{
		sum = arr[0];
		for (int i = 1; i < n; i++)
		{
			if (arr[i] > sum+1)
			{
				break;
			}
			sum += arr[i];
		}
		cout << sum + 1;
	}
}