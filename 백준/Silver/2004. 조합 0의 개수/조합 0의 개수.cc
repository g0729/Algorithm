#include<iostream>
using namespace std;

long long func(int n, int x)
{
	long long num=0;
	for (long long i = x; n / i >= 1; i *= x)
	{
		num += n / i;
	}
	return num;
}
int main()
{
	int n, m;
	cin >> n>>m;
	long long cnt2, cnt5;
	cnt2 = func(n, 2) - func(m, 2) - func(n - m, 2);
	cnt5 = func(n, 5) - func(m, 5) - func(n - m, 5);
	cout << min(cnt2, cnt5);
}