#include<iostream>
using namespace std;
#define max 10000000
bool arr[max];
void eratos()
{
	arr[0] = arr[1] = true;
	for (int i = 2; i * i < max; i++)
	{
		if (arr[i] == false)
		{
			for (int j = i * i; j < max; j += i)
				arr[j] = true;
		}
	}
}
int main()
{
	int t;
	cin >> t;
	eratos();
	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		int cnt = 0;
		for (int q = 2; q <= n / 2; q++)
		{
			if (arr[q] == false && arr[n - q] == false)
				cnt++;
		}
		cout << cnt<<endl;
	}
}