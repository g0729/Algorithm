#include<iostream>
#define lint unsigned long long
using namespace std;

lint f(lint n)
{
	lint i, j, ret = 0;
	for ( i = 1; i <= n; i = j + 1)
	{
		j = n / (n / i);
		ret += (n / i) *(j - i + 1)*(i+j)/2;
	}
	return ret;
}
int main()
{
	lint a, b;
	cin >> a >> b;
	cout << f(b) - f(a - 1);
}