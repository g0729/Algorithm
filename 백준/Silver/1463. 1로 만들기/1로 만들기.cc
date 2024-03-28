#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int* arr = new int[n + 1];
	arr[0] = 0;
	arr[1] = 0;
	arr[2] = arr[3] = 1;

	for (int i = 4; i < n + 1; i++)
	{
		if (i % 2 == 0 && i % 3 == 0)
		{
			arr[i] = min({ arr[i - 1],arr[i / 2],arr[i / 3] }) + 1;
		}
		if (i % 2 == 0 && i % 3 != 0)
		{
			arr[i] = min(arr[i - 1], arr[i / 2]) + 1;
		}
		if (i % 2 != 0 && i % 3 == 0)
		{
			arr[i] = min(arr[i - 1], arr[i / 3]) + 1;
		}
		if (i % 2 != 0 && i % 3 != 0)
		{
			arr[i] = arr[i - 1] + 1;
		}
	}
	cout << arr[n];
}