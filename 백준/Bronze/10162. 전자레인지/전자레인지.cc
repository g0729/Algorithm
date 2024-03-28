#include<iostream>
using namespace std;

int main()
{
	int count[3] = { 0 };
	int arr[] = { 300,60,10 };
	int n;
	cin >> n;
	for (int i = 0; i < 3; i++)
	{
		count[i] = n / arr[i];
		n = n % arr[i];
	}
	if (n != 0)
	{
		cout << "-1";
	}
	else
	{
		cout << count[0] << " " << count[1] << " " << count[2];
	}
}