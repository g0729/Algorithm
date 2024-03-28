#include<iostream>
using namespace std;

int main()
{
	char a[4];
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		cout << a[0] - '0' + a[2] - '0' << endl;
	}
	

}