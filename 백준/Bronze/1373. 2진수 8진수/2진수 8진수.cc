#include<iostream>
using namespace std;

int main()
{
	string s;
	cin >> s;
	string res;

	for (int i = 0; i < s.length() / 2; i++)
	{
		char temp = s[i];
		s[i] = s[s.length() - 1 - i];
		s[s.length() - 1 - i] = temp;
	}
	if (s.length() % 3 != 0)
	{
		s.resize((s.length() / 3) * 3 + 3, '0');
	}
	for (int i = 0; i < s.length(); i += 3)
	{
	
		int sum = s[i] - '0' + (s[i + 1] - '0') * 2 + (s[i + 2] - '0') * 4;
		res.push_back((sum % 8)+'0');
		
	}

		for (int i = 0; i < res.length() / 2; i++)
		{
			char temp = res[i];
			res[i] = res[res.length() - 1 - i];
			res[res.length() - 1 - i] = temp;
		}

		cout << res;
	
}