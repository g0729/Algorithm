#include<iostream>
#define max 10001
using namespace std;
bool arr[max];
int main()
{
	int n;
	cin >> n;
	int a, b;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		for (int i = a; i < b; i++)
		{
			if (arr[i] == false)
			{
				cnt++;
				arr[i] = true;
			}
		}
	}
	cout << cnt;
	
}