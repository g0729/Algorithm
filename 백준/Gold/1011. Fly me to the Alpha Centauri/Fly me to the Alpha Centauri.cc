#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int t;
	cin>> t;
	for (int i = 0; i < t; i++)
	{
		long long x, y;
		cin >> x >> y;
		long long dis = y - x;
		long long n = 1;
		int move;
		while (n * n <= dis)
			n++;
		n--;
		dis -= n * n;
		double tem = ceil((double)dis / n);
		n = 2 * n - 1 + tem;
		cout << n<<endl;
	}

}