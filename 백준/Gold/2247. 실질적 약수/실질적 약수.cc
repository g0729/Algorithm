#include<iostream>
#include<stdlib.h>
#define max 1000000
using namespace std;

int main()
{
	unsigned long long n;
	cin >> n;
	unsigned long long res=0;
	unsigned long long temp;
	for (long long i = 2; i <= n; i++)
	{
		res += (i * (n / i));
	}
	temp = (n * (n + 1) / 2);
	if (res > temp)
		res = (res - temp + 1)%max;
	else
		res = (temp - res - 1)%max;
	cout << res;
}