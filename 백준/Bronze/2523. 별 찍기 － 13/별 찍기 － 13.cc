#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n-1; i++)
	{
		for (int q = 0; q < i +1; q++)
			cout << "*";
		cout << endl;
	}
	for (int i = n; i > 0; i--)
	{
		for (int q = 0; q < i; q++)
			cout << "*";
		cout << endl;
	}
}