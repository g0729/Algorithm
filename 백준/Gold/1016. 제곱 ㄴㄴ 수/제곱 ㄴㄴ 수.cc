#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
#define lint unsigned long long

int main()
{
	lint min, max;
	int cnt = 0;
	cin >> min >> max;
	vector <bool> arr(max - min+1,1);
	for (lint i = 2; i * i <= max; i++)
	{
		lint q;
		if (min % (i * i) == 0)
			q = min / (i * i) * (i * i);
		else
			q = min / (i * i) * (i * i) + (i * i);
		for (q; q <= max; q += i * i)
		{
			if (arr[q - min])
			{
				cnt++;
				arr[q - min] = false;
			}
		}
	}
	cout << max-min-cnt+1;
}