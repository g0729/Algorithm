#include<iostream>
#include<stack>
using namespace std;
int arr[100000];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	stack<int>v;
	string res;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++)
	{
		v.push(i);
		res += '+';
		while (!v.empty()&& arr[cnt] == v.top())
		{
			v.pop();
			res += '-';
			cnt++;
		}
	}
	if (!v.empty())
	{
		cout << "NO";
		return 0;
	}
	else
	{
		for (int i = 0; i < res.size(); i++)
		{
			cout << res[i] << "\n";
		}
	}
}