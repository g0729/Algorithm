#include<iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;

	
	for (int i = 0; i < t; i++)
	{
		int sum;
		cin >> sum;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int multi;
			cin >> multi;
			int cost;
			cin >> cost;
			sum += multi * cost;
		}
		cout << sum<<endl;
	}
}