#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	double b, c;
	cin >> b >> c;
	long long res = n;

	for (int i = 0; i < n; i++)
	{
		arr[i] -= b;
		if (arr[i] > 0)
		{
			res += ceil(arr[i] / c);
		}
	}
	cout << res;
}