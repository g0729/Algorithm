#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	int arr[10];
	for (int i = 0; i < t; i++)
	{
		for (int i = 0; i < 10; i++)
		{
			cin >> arr[i];
		}
		sort(arr, arr + 10);
		cout << arr[7] << "\n";

	}
}