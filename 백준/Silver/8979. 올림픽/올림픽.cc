#include <bits/stdc++.h>
using namespace std;

struct country
{
	int num;
	int gold;
	int sliver;
	int bronze;
};
bool cmp(country a, country b)
{
	if (a.gold == b.gold)
	{
		if (a.sliver == b.sliver)
			return a.bronze > b.bronze;
		return a.sliver > b.sliver;
	}
	return a.gold > b.gold;
}
country arr[1000];
int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		arr[i].num = a;
		arr[i].gold = b;
		arr[i].sliver = c;
		arr[i].bronze = d;
	}
	sort(arr, arr + n, cmp);
	int res;
	for (int i = 0; i < n; i++)
	{
		if (arr[i].num == k)
		{
			res = i;
			break;
		}
	}
	int temp = 0;
	for (int i = res - 1; i >= 0; i--)
	{
		if (arr[i].gold != arr[res].gold || arr[i].sliver != arr[res].sliver || arr[i].bronze != arr[res].bronze) {
			break;
		}
		temp++;
	}
	cout << res - temp + 1;
}