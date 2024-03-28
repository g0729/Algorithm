#include<iostream>
using namespace std;

int main()
{
	int arr[101];
	arr[0] = 0;
	for (int i = 1; i <= 100; i++)
		arr[i] = i * i;
	int m, n;
	cin >> m >> n;
	int min=0, sum=0;
	for (int i = 1; arr[i] <= n; i++)
	{
		if (arr[i] >= m)
		{
			if (min == 0)
				min = arr[i];
			sum += arr[i];
		}
		
	}
	if (sum == 0)
		cout << "-1";
	else
	cout << sum << endl << min;
	
}