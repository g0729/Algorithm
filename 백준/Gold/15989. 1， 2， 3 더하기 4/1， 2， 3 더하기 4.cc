#include<iostream>
using namespace std;

#define MAX 10001

long long arr[MAX][4];

int main()
{
	arr[1][1] = 1;
	arr[2][1] = 1;
	arr[2][2] = 1;
	arr[3][1] = 1;
	arr[3][2] = 1;
	arr[3][3] = 1;
	for (int i = 4; i < MAX; i++)
	{
		arr[i][1] = 1;
		arr[i][2] = arr[i - 2][2]+1;
		arr[i][3] = arr[i - 3][1] + arr[i - 3][2] + arr[i - 3][3];
	}
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		long long res = arr[n][1] + arr[n][2] + arr[n][3];
		cout <<res<< "\n";
	}
}