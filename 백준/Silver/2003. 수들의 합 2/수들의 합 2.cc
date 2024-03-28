#include <bits/stdc++.h>
using namespace std;
#define MAX 10000
int arr[MAX];
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int start, end, sum, res;
	start = end = sum = res = 0;
	while (end <= n)
	{
		if (sum >= m)
		{
			sum -= arr[start];
			start++;
		}
		else if (sum < m)
		{
			sum += arr[end];
			end++;
		}
		if (sum == m)
			res++;
	}
	cout << res;
}