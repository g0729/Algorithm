#include<iostream>
using namespace std;
int A[50][50];
int B[50][50];
int n, m;
void change(int a, int b)
{
	for (int i = a; i < a + 3; i++)
	{
		for (int q = b; q < b + 3; q++)
		{
			if (A[i][q] == 0)
				A[i][q] = 1;
			else
				A[i][q] = 0;
		}
	}
}
bool check()
{
	for (int i = 0; i < n; i++)
	{
		for (int q = 0; q < m; q++)
			if (A[i][q] != B[i][q])
				return false;
	}
	return true;
}
int main()
{
	
	cin >> n >> m;
	int cnt = 0;
	string s;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int q = 0; q < m; q++)
		{
			A[i][q] = s[q] - '0';
		}
	}
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int q = 0; q < m; q++)
		{
			B[i][q] = s[q] - '0';
		}
	}
	for (int i = 0; i < n - 2; i++)
	{
		for (int q = 0; q < m - 2; q++)
		{
			if (A[i][q] != B[i][q])
			{
				cnt++;
				change(i, q);
			}
		}
	}
	if (check() == false)
		cout << "-1";
	else
		cout << cnt;
}