#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int q = 0; q < i; q++)
		{
			cout <<  " ";
		}
		for (int q = 0; q < 2 * n - 2 * i - 1; q++)
		{
			cout << "*";
		}
		cout << endl;
		}
	for (int i = 0; i < n - 1; i++)
	{
		for (int q = 0; q < n - 2 - i; q++)
		{
			cout << " ";
		}
		for (int q = 0; q < i * 2 + 3; q++)
		{
			cout << "*";
		}
		cout << endl;
	}
}