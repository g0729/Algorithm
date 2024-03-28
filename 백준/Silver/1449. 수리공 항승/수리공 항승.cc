#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n, k;
	int cnt = 1;
	cout.precision(4);
	cin >> n >> k;
	int* arr = new int[n];

	
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}	
	sort(arr, arr + n);
	double sum = arr[0] - 0.5 + k;
	for (int i = 1; i < n; i++)
	{
		if (arr[i] < sum)
			continue;
		else
		{
			sum = arr[i] - 0.5 + k;
			cnt++;
		}
	}
	cout << cnt;
}