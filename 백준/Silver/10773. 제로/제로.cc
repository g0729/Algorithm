#include<iostream>
#include<stack>
using namespace std;

int main()
{
	
	stack<int>v;
	int n;
	cin >> n;
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		if (a == 0)
		{
			res -= v.top();
			v.pop();
		}
		else
		{
			res += a;
			v.push(a);
		}
	}
	cout << res;
}