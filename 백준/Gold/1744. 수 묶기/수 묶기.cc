#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int cntmi = 0;
	int cnt0 = 0;
	int cnt1 = 0;
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (arr[i] == 0)
			cnt0++;
		if (arr[i] < 0)
			cntmi++;
		if (arr[i] == 1)
			cnt1++;
	}
	sort(arr, arr + n, cmp);
	int end = cnt0 + cnt1 + cntmi;
	int sum = 0;
	int length = n - end;
	if (cntmi % 2 == 0)
	{
		if (length % 2 == 0)
		{
			for (int i = 0; i < length; i += 2)
			{
				sum += arr[i] * arr[i + 1];
			}
		}
		else
		{
			for (int i = 0; i < length-1; i += 2)
			{
				sum += arr[i] * arr[i + 1];
			}
			sum += arr[length - 1];
		}
		for (int i = 0; i < cntmi; i+=2)
		{
			sum += arr[n - 1 - i] * arr[n - 2 - i];
		}
		sum += cnt1;
	}
	else
	{
		if (length % 2 == 0)
		{
			for (int i = 0; i < length; i += 2)
			{
				sum += arr[i] * arr[i + 1];
			}
		}
		else
		{
			for (int i = 0; i < length - 1; i += 2)
			{
				sum += arr[i] * arr[i + 1];
			}
			sum += arr[length - 1];
		}
		for (int i = 0; i < cntmi-1; i += 2)
		{
			sum += arr[n - 1 - i] * arr[n - 2 - i];
		}
		if (cnt0 == 0)
		{
			sum += arr[n - cntmi];
		}
		sum += cnt1;
	}
	cout << sum;
}