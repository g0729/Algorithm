#include<iostream>
using namespace std;
bool sel[10];
int res;
int cnt;
int combination(int n, int r)
{
	if (n == r || r == 0)
		return 1;
	else
		return combination(n - 1, r - 1) + combination(n - 1, r);
}
void print()
{
	for (int i = 9; i >= 0; i--)
	{
		if (sel[i])
			cout << i;
	}
}
void DFS(int idx,int a,int digit)
{
	if (a == digit)
	{
		cnt++;
		if (cnt == res)
		{
			print();
			exit(0);
		}
		return;
	
	}
	for (int i = 0; i < idx; i++)
	{
		if (a == 0 && i == 0)
			continue;
		if (sel[i])
			continue;
		sel[i] = true;
		DFS(i, a + 1, digit);
		sel[i] = false;
	}
}
int main()
{
	int n;
	cin >> n;
	if (n >= 1023)
	{
		cout << "-1";
		return 0;
	}
	if (n < 10)
	{
		cout << n;
	}
	int arr[10];
	arr[0] = 9;
	for (int i = 1; i < 10; i++)
	{
		arr[i] = arr[i - 1] + combination(10, i + 1);
	}
	int digit = 0;
	while (n > arr[digit])
	{
		digit++;
	}
	res = n - arr[digit-1];

	DFS(10, 0, digit+1);
}