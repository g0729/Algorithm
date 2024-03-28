#include <iostream>
#include <cmath>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int arr[3];
	while (1)
	{
		for (int i = 0; i < 3; i++)
		{
			cin>>arr[i];
		}
		sort(arr,arr+3);
		if (arr[0]+arr[1]+arr[2]== 0)
			break;

		int discriminant = pow(arr[0], 2) + pow(arr[1], 2) - pow(arr[2], 2);
		if (discriminant == 0)
			cout << "right" << '\n';
		else cout << "wrong" << "\n";
	}
	return 0;
}