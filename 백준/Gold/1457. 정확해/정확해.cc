#include<iostream>
using namespace std;
long long mypow(long long x, long long p)
{
	if (p == 0) 
		return 1;
	if (p == 1)
		return x;
	return x * mypow(x, p - 1);
}
int  main()
{
	long long a, b, n;
	cin >> a >> b >> n;
	long long res = 0;
	for (long long i = 2; i <= a + b; i++)
	{
		res += (a + b)/i;
	}
	for (long long i = 2; i < a; i++)
	{
		res  -= (a-1) / i;
	}
	for (long long i = 2; mypow(i,n)<= a + b; i++)
	{
		res -= (a + b) / mypow(i, n);
	}
	for (long long i = 2; mypow(i, n) < a; i++)
	{

		res += (a - 1) / mypow(i, n);
	}
	if(a==1)
		res =res-b;
	else
	res =res- (b + 1);
	cout << res;
}