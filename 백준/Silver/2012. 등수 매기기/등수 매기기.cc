#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	long long res=0;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++)
	{
		res += abs(arr[i] - (i + 1));
	}
	cout << res;
}