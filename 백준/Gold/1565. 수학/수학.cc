#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
int gcd(int n, int m)
{
	int a, b, c;
	a = max(n, m);
	b = min(n, m);
	c = a % b;
	while (c != 0)
	{
		a = b;
		b = c;
		c = a % b;
	}
	return b;
}
int main()
{
	int a, b;
	cin >> a >> b;
	int* arrd;
	int* arrm;
	arrd = new int[a];
	arrm = new int[b];
	for (int i = 0; i < a; i++)
		cin >> arrd[i];
	for (int i = 0; i < b; i++)
		cin >> arrm[i];
	long long multiple=arrd[0];
	long long factor=arrm[0];
	sort(arrd, arrd + a);
	
	for (int i = 1; i < a;i++)
	{
		multiple = multiple * arrd[i] / gcd(multiple, arrd[i]);
	}
	for (int i = 1; i < b; i++)
	{
		factor = gcd(factor, arrm[i]);
	}
	vector <int> v;
	int q;
	for ( q = 1; q * q < factor; q++)
	{
		if (factor % q == 0)
		{
			v.push_back(q);
			v.push_back(factor / q);
		}
	}
	if (q * q == factor)
		v.push_back(q);
	int cnt = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] % multiple == 0)
			cnt++;
	}
	cout << cnt;
}