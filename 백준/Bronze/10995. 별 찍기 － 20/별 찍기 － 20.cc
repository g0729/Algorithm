#include<iostream>
using namespace std;
void odd()
{
	cout << "*" << " ";
}
void even()
{
	cout << " " << "*";
}
int main()
{
	int n; 
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
			for (int q = 0; q < n; q++)
				odd();
		else
			for (int q = 0; q < n; q++)
				even();
		cout << endl;
	}
}
