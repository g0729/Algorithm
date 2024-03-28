#include <bits/stdc++.h>
using namespace std;

int main()
{
	while (1)
	{
		string s;

		cin >> s;

		if (s == "#")
			break;

		int cnt_1 = 0;

		for (int i = 0; i < s.length() - 1; i++)
		{
			if (s[i] == '1')
			cnt_1++;
		}

		string temp = s;
		temp.pop_back();
		cout << temp;

		if (s[s.length() - 1] == 'e')
		{
			if (cnt_1 % 2 == 0)
			{
				cout << "0";
			}
			else
			{
				cout << "1";
			}
		}
		else
		{
			if (cnt_1 % 2 == 0)
			{
				cout << "1";
			}
			else
			{
				cout << "0";
			}
		}
		cout << endl;
	}
}