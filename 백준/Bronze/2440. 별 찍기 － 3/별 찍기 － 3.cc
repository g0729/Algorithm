#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = n; i > 0; i--)
	{
		for (int q = 0; q < i; q++)
			cout << "*";
		cout << endl;
	}
}