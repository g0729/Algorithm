#include<iostream>
#include<cstdlib>
using namespace std;
bool sel[20];
int n;
int** arr;
int mi=100000;
void DFS(int idx,int a)
{
	if (a == n /2)
	{
		
		int sum_a, sum_b;
		sum_a = sum_b = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				if (sel[i] && sel[j])
					sum_a+= arr[i][j];
				if (sel[i] == false && sel[j] == false)
					sum_b += arr[i][j];
			}
		if (mi > abs(sum_a - sum_b))
		{
			mi = abs(sum_a - sum_b);
		}
	}
	for (int i = idx; i < n; i++)
	{
		if (sel[i] == true)
		continue;
		sel[i] = true;
		DFS(i, a + 1);
		sel[i] = false;
	}
}
int main()
{
	
	cin >> n;
	arr = new int*[n];
	
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
	DFS(0, 0);
	cout << mi;
}