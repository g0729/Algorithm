#include <bits/stdc++.h>
using namespace std;
int arr[100000][2];
int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i][0] >> arr[i][1];
	}

	int now = 0, MAX = 0;
	long long sum = 0;
	for (; now < n; now++)
	{
		if (sum > arr[now][0])
		{

			if (MAX > arr[now][1])
			{
				if(sum-MAX<=arr[now][0])
				sum = sum + arr[now][1] - MAX;
			}
			now++;
			break;
		}
		sum += arr[now][1];
		MAX = max(MAX, arr[now][1]);
	}
	for (; now < n; now++)
	{
		if (sum > arr[now][0])
			break;
		sum += arr[now][1];
	}
	if (now == n)
		cout << "Kkeo-eok";
	else
		cout << "Zzz";
}