#include<iostream>
#define lint long long
using namespace std;

lint f(lint n)
{
	lint i, j, ret = 0;
	for ( i = 1; i <= n; i=j+1)
	{
		j = n / (n / i);
		ret += (n / i) * (j - i + 1);
	}
	return ret;
}

int main()
{
	lint n;
	cin >> n;
	cout << f(n-1)+n;
}