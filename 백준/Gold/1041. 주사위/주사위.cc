#include<bits/stdc++.h>
using namespace std;

#define lint unsigned long long
int max(int a,int  b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
int main()
{
	lint n;
	cin >> n;
	lint n_3 = 4;
	lint n_2 = 8 * n - 12;
	lint n_1 = 5 * n * n - 16 * n + 12;
	lint arr[6];
	for (int i = 0; i < 6; i++)
	{
		cin >> arr[i];
	}
	lint a, b, c;
	a = arr[0] < arr[5] ? arr[0] : arr[5];
	b = arr[1] < arr[4] ? arr[1] : arr[4];
	c = arr[2] < arr[3] ? arr[2] : arr[3];
	lint min_1;
	lint min_2;
	lint min_3;
	min_1 = c < (a < b ? a : b) ? c : (a < b ? a : b);
	min_3 = a + b + c;
	min_2 = b + c < (a + b < a + c ? a + b : a + c) ? b + c : (a + b < a + c ? a + b : a + c);
	lint res = n_3 * min_3 + min_2 * n_2 + n_1 * min_1;
	if (n == 1)
	{
		int ma = 0;
		int sum = 0;
		for (int i = 0; i < 6; i++)
		{
			ma = max(ma, arr[i]);
			sum += arr[i];
		}
		sum -= ma;
		cout << sum;
		return 0;
			
	}
	cout << res;
}