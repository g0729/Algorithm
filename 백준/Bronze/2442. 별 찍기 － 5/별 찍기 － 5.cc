#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int q = 0; q < n - i - 1; q++)
			cout << " ";
		for (int q = 0; q < 2 * i + 1; q++)
			cout << "*";
		cout << endl;
	}
}