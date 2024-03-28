#include <bits/stdc++.h>
using namespace std;
int arr[1400];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int m, n;
	cin >> m >> n;
	for (int i = 0; i < 2 * m - 1; i++)
	{
		arr[i] = 1;
	}
	for (int i = 0; i < n; i++)
	{
		int cnt0, cnt1, cnt2;
		cin >> cnt0 >> cnt1 >> cnt2;

		for (int j = cnt0; j < cnt0 + cnt1; j++)
		{
			arr[j]++;
		}
		for (int j = cnt0 + cnt1; j < 2 * m - 1; j++)
		{
			arr[j] += 2;
		}
	}
	for (int i = m-1; i >= 0; i--)
	{
		cout<<arr[i]<<" ";
		for (int q = m; q < 2*m-1; q++)
		{
			cout<<arr[q]<<" ";
		}
		cout<<"\n";
	}
	
}