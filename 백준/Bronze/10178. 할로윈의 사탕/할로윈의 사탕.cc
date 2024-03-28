#include<iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n,v;
		cin >> n>>v;
		cout << "You get " << n / v << " piece(s) and your dad gets " << n % v << " piece(s)." << endl;

	}
}