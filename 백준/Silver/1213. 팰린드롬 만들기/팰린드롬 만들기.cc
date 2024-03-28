#include<iostream>
using namespace std;

int main()
{
	string s;
	int alpha[26] = { 0 };
	cin >> s;
	string res;
	int odd;
	if (s.length() == 1)
	{
		cout << s;
		return 0;
	}
	for (int i = 0; i < s.size(); i++)
	{
		alpha[s[i] - 'A']++;
	}
	if (s.length() % 2 == 0)
	{
		
		for (int i = 0; i < 26; i++)
		{
			if (alpha[i] % 2 == 1)
			{
				cout<< "I\'m Sorry Hansoo";
				return 0;
			}
		}
	}
	else
	{
		int cnt = 0;
		for (int i = 0; i < 26; i++)
		{
			if (alpha[i] % 2 == 1)
			{
				cnt++;
				odd = i;
			}
		}
		if (cnt > 1)
		{
			cout<< "I\'m Sorry Hansoo";
			return 0;
		}
	}
		for (int i = 0; i < 26; i++)
		{
			if (alpha[i])
			{
				for (int j = 0; j < alpha[i] / 2; j++)
				{
					res.push_back(i + 'A');
				}
			}
		}

		if (s.length() % 2 == 1)
		{
			res.push_back(odd + 'A');
			int length = res.length();
			for (int i = 0; i < length - 1; i++)
			{
				res.push_back(res[length - 2 - i]);
			}
		}
		else
		{
			int length = res.length();
			for (int i = 0; i < length; i++)
			{
				res.push_back(res[length - 1 - i]);
			}
		}
		cout << res;

		
	
}