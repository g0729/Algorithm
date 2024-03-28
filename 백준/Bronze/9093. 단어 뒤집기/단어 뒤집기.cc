#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	getchar();
	for (int i = 0; i < t; i++)
	{
		string s;
		getline(cin, s);
		int start = 0;
		int end;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == ' '||i==s.length()-1)
			{
				end = i - 1;
				if (i == s.length() - 1)
				{
					end = i;
				}
				for (int q = start; q <start+ (end - start + 1) / 2; q++)
				{
					char temp = s[q];
					s[q] = s[end-(q-start)];
					s[end-(q-start)] = temp;
				}
				start = end + 2;
			}
		}
		cout << s << endl;
	}
}