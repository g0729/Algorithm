#include <bits/stdc++.h>
using namespace std;

int main()
{
	while (1)
	{
		string s;

		cin >> s;

		if (s == "0")
			break;

		while (1)
		{
			if (s.length() == 1)
			{
				cout << s << "\n";
				break;
			}
			int sum = 0;

			for (int i = 0; i < s.length(); i++)
			{
				sum += s[i] - '0';
			}
			s=to_string(sum);
		}
	}
}