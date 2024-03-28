#include<iostream>
using namespace std;

int main()
{
	int day;
	int count = 0;
	int car;
	cin >> day;
	for (int i = 0; i < 5; i++)
	{
		cin >> car;
		if (day == car)
			count++;
	}
	cout << count;
}