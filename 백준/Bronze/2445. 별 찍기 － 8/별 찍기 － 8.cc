#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int q = 0; q < i ; q++)
		{
			cout << "*";
		}
		for (int q = 0; q < n * 2 - 2 * i; q++)
		{
			cout << " ";
		}
		for (int q = 0; q < i; q++)
		{
			cout << "*";
		}
		cout << endl;
	}
	for (int i = 1; i < n; i++)
	{
		
		for (int q = 0; q < n - i; q++)
			cout << "*";
		for (int q = 0; q < i * 2; q++)
			cout << " ";
		for (int q = 0; q < n - i; q++)
			cout << "*";
		cout << endl;
	}
}