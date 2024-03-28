#include<iostream>
using namespace std;

int main()
{
	long long s;
	cin >> s;
	long long n = 1;
	long long sum = 0;
	while (s - sum >= n)
	{
		sum = n * (n + 1) / 2;
		n++;
	}
	if (s == 1)
		cout << "1";
	else
	cout << n-1;
}