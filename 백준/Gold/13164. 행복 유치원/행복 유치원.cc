#include<iostream>
#include<algorithm>
using namespace std;
int* arr;
int* dis;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	arr = new int[n];
	dis = new int[n];
	cin >> arr[0];
	dis[0] = 0;
	long long res = 0;
	for (int i = 1; i < n; i++)
	{
		cin >> arr[i];
		dis[i] = arr[i] - arr[i - 1];
	}
	sort(dis, dis + n);
	for (int i = 0; i <= n - k; i++)
	{
		res += dis[i];
	}
	cout << res;
}
