#include<iostream>
using namespace std;
int main()
{
	int n, k;
	cin >> n >> k;
	bool* arr = new bool[n + 1];
	for (int i = 2; i < n + 1; i++)
		arr[i] = true;
	int res;
	for (int i = 2; i <= n; i++)
	{
		if (arr[i])
		{
			for (int q = i; q <= n; q += i)
			{
				if (arr[q] == false)
					continue;
				arr[q] = false;
				k--;
				if (k == 0)
				{
					res = q;
					break;
				}

			}
		}
		if (k == 0)
		{
			break;
		}
	}

	cout << res;
}