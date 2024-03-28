#include<bits/stdc++.h>
using namespace std;
int arr[100];
int gcd(int a, int b)
{
	int large = a > b ? a : b;
	int small = a < b ? a : b;
	int c = large % small;
	while (c != 0)
	{
		large = small;
		small = c;
		c = large % small;
	}
	return small;
}
int main()
{
	int first;
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	first = arr[0];
	for (int i = 1; i < n; i++)
	{
		int a, b;
		int temp = gcd(first, arr[i]);
		temp=first*arr[i]/temp;
		b = temp / first;
		a = temp / arr[i];
		printf("%d/%d\n", a, b);
	}
}