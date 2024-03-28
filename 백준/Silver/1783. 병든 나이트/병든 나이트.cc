#include<iostream>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int count = 0;
	if (n == 1)
		count = 1;
	else if (n == 2)
		count = min(4, (m - 1 )/ 2 + 1);
	else if (m < 7)
		count = min(4, m);
	else
		count = (2 + m  -5) + 1;
		cout << count;

}