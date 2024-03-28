#include<iostream>
#include<vector>
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
	vector<int>a;
	vector<int>b;
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		a.push_back(k);
	}
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		b.push_back(k);
	}
	sort(a.begin(), a.end());
	sort(b.begin(),b.end(), cmp);
	for (int i = 0; i < n; i++)
		res += a[i] * b[i];
	cout << res;
}