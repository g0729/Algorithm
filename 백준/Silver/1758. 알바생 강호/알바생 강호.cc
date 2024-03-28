#include<iostream>
#include<algorithm>
using namespace std;

bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	int n;
	cin >> n;
	long long res = 0;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n, cmp);
	for (int i = 0; i < n; i++)
	{
		if (arr[i] - i<=0)
		{
			break;
		}
		res += arr[i] - i;
	}
	cout << res;
}