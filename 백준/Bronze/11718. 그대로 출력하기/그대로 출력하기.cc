#include<iostream>
#include<string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	while (1)
	{
		getline(cin, s);
		if (s == "")
			break;
		cout << s << "\n";
	}
}