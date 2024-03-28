#include<iostream>
using namespace std;

int main()
{
	int sum=0;
	for (int i = 0; i < 5; i++)
	{
		int score;
		cin >> score;
		if (score < 40)
			sum += 40;
		else
			sum += score;
	}
	cout << sum / 5;
}