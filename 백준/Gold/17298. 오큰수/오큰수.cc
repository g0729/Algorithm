#include<iostream>
#include<stack>
using namespace std;

int main()
{
	int n;
	cin >> n;
	stack <int>v;
	int* arr = new int[n];
	int* res = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = n - 1; i >= 0; i--)
	{
		while (!v.empty() && v.top() <= arr[i])
		{
			v.pop();
		}
		if (v.empty())
		{
			res[i] = -1;
		}
		else
		{
			res[i] = v.top();
		}
		v.push(arr[i]);
	}
	for (int i = 0; i < n; i++)
	{
		cout << res[i] << " ";
	}

}