#include<iostream>
using namespace std;

int main()
{
	long long arr[40];
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i < 40; i++)
		arr[i] = arr[i - 1] + arr[i - 2];

	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		if (n == 0)
			cout << "1 0" << endl;
		else if (n == 1)
			cout << "0 1" << endl;
		else
		cout << arr[n - 2] << " " << arr[n - 1] << endl;
	}


}