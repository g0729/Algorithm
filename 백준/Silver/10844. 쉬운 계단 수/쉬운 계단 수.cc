#include<iostream>
using namespace std;

int main()
{
	int n; 
	cin >> n;
	long long** DP = new long long*[n];
	for (int i = 0; i < n; i++)
	{
		DP[i] = new long long[10];
	}
	DP[0][0] = 0;
	for (int i = 1; i < 10; i++)
	{
		DP[0][i] = 1;
	}
	for (int i = 1; i < n; i++)
	{
		for (int q = 0; q < 10; q++)
		{
			if (q == 0)
				DP[i][q] = DP[i - 1][1];
			else if (q == 9)
				DP[i][q] = DP[i - 1][8];
			else
			DP[i][q] = DP[i - 1][q + 1] + DP[i - 1][q - 1];
			
			DP[i][q] = DP[i][q] % 1000000000;
		}
	}
	long long res = 0;
	for (int i = 0; i < 10; i++)
	{
		res += DP[n - 1][i] % 1000000000;;
	}
	res = res % 1000000000;
	cout << res;
}