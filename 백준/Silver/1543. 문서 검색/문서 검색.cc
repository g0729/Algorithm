#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s;
	string a;
	getline(cin, s);
	getline(cin, a);
	int cnt = 0; int start = 0;
	while (1)
	{
		if (s.find(a, start) == string::npos)
			break;
		else
		{
			start = s.find(a, start) + a.length();
			cnt++;
			
		}
	}
	cout << cnt;
}