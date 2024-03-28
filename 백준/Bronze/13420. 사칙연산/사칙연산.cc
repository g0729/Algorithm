#include<iostream>
#include<string>
using namespace std;

int main()
{
	
	long long  t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		long long a, b,res;
		char ope, equ;
		cin >> a >> ope >> b >> equ >> res;
		if (ope == '*')
		{
			if (a * b == res)
				cout << "correct" << endl;
			else
				cout << "wrong answer" << endl;
		}
		if (ope == '-')
		{
			if (a - b == res)
				cout << "correct" << endl;
			else
				cout << "wrong answer" << endl;
		}
		if (ope == '/')
		{
			if (a / b == res)
				cout << "correct" << endl;
			else
				cout << "wrong answer" << endl;
		}
		if (ope == '+')
		{
			if (a + b == res)
				cout << "correct" << endl;
			else
				cout << "wrong answer" << endl;
		}
	}
}