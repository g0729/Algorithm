#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	n = 1000 - n;
	int res = 0;
	int arr[6] = { 500,100,50,10,5,1 };
	int i = 0;
	for (;i < 6; i++)
	{
		res += n / arr[i];
		n = n % arr[i];
	}
	cout << res;
}