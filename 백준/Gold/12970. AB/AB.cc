#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	int a = 0;
	int b = n;
	bool check = false;
	for (; b > 0; b--, a++)
	{
		if (a * b >= k)
		{
			check = true;
			break;
		}
	}
	if (!check)
	{
		cout << "-1";
		return 0;
	}

	string res;

	if (a * b == k)
	{
		for (int i = 0; i < a; i++)
		{
			res += 'A';
		}
		for (int i = 0; i < b; i++)
		{
			res += 'B';
		}
	}

	else
	{
		a--;
		int temp=a*b;
		temp=k-temp;
		for (int i = 0; i < a; i++)
		{
			res+='A';
		}
		for (int i = 0; i < b-temp; i++)
		{
			res+='B';
		}
		res+='A';
		for (int i = 0; i < temp; i++)
		{
			res+='B';
		}
	}
	cout<<res;
}