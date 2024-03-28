#include<iostream>
using namespace std;
#define MOD 1000000009
#define MAX 1000001
long long arr[MAX];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	for (int i = 4; i < MAX; i++)
	{
		arr[i] = (arr[i - 1] + arr[i - 2] + arr[i - 3])%MOD;
	}
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		cout << arr[n] << "\n";
	}
}