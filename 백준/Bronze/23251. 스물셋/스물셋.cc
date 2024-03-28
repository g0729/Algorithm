#include<iostream>
using namespace std;

int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int k;
		cin >> k;
		long long res;
		res = k * 23;
		cout << res << "\n";
	}
}