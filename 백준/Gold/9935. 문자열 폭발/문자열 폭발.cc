#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	string boom;
	string res;
	cin >> s;
	cin >> boom;
	char check = boom.back();
	int boomlength = boom.length();

	for (int i = 0; i < s.length(); i++)
	{
		res += s[i];
		if (s[i] == check&&res.length()>=boom.length())
		{
			bool fa = true;
			for (int q = 0; q < boom.length(); q++)
			{
				if (res[res.length() - 1 - q] != boom[boom.length() - 1 - q])
				{
					fa = false;
					break;
				}
			}
			if (fa)
			{
				for (int j = 0; j < boom.length(); j++)
					res.pop_back();
			}
		}
	}
	if(res.empty())
	cout<<"FRULA";
	else
	cout << res;
}