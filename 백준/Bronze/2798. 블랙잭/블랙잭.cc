#include <iostream>

#include <stdio.h>

using namespace std;

int main()
{

	int n, m, result = 0;

	int arr[101] = {};

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{

		cin >> arr[i];
	}

	for (int i = 0; i < n; i++)
	{

		for (int j = i + 1; j < n; j++)
		{

			for (int k = j + 1; k < n; k++)
			{

				if (arr[i] + arr[j] + arr[k] <= m && arr[i] + arr[j] + arr[k] > result)

					result = arr[i] + arr[j] + arr[k];
			}
		}
	}
	cout << result << endl;
}
