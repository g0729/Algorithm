#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	string a, b;
	cin >> a >> b;
	int A = a.length(), B = b.length();

	while (1)
	{
		if (A == B)
		{
			break;
		}
		if (b[b.size()-1] == 'A')
		{
			b.pop_back();
			B--;
		}
		else if (b[b.size()-1] == 'B')
		{
			b.pop_back();
			reverse(b.begin(), b.end());
			B--;
		}
	}
	if (a == b)
		cout << "1";
	else
		cout << "0";
}