#include<iostream>
using namespace std;

int gcd(int a, int b)
{
	int large = a > b ? a : b;
	int small = a > b ? b : a;
	int temp = large % small;
	while (temp!= 0)
	{
		large = small;
		small =temp;
		temp = large % small;
	}
	return small;
}
int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int a, b;
		cin >> a >> b;
		long long res = a * b / gcd(a, b);
		cout <<res <<endl;
	}
}