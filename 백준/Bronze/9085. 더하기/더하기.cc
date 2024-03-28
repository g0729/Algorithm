#include<iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int sum = 0; 
		int a;;
		cin >> a;
		int k;
		for (int i = 0; i < a; i++)
		{
			cin >> k;
			sum += k;
		}
		cout << sum << endl;
	}
}