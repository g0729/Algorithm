#include<iostream>
#include<vector>
#define lint long long
#define max 10000011
using namespace std;

bool prime[max + 1];

void eratos()
{
	prime[0] = prime[1] = true;
	for (int i = 2; i * i <= max; i++)
	{
		if (prime[i]==false)
		{
			for (int q = i * i; q <= max; q += i)
			{
				prime[q] = true;
			}
		}
	}
}
lint mypow(lint n, int k)
{
	lint res = 1;
	for (int i = 0; i < k; i++)
	{
		res *= n;
	}
	return res;
}
int f(lint a)
{
	int res = 0;
	
	for (lint i = 2; i * i <= a; i++)
	{

		if (prime[i]==false)
		{
			lint ca = a;
			while (i*i<= ca)
			{
				res++;
				ca /= i;
			}
		}
	}
	return res;
}
int main()
{
	lint a, b;
	cin >> a >> b;
	eratos();
	cout << f(b) - f(a - 1);

}