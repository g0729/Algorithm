#include <bits/stdc++.h>
using namespace std;

int alpha[26];

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		string s;
		cin >> s;
		alpha[s[0] - 'a']++;
	}
	bool check = false;
	for (int i = 0; i < 26; i++)
	{
		if (alpha[i] >= 5)
		{
			char temp=i+'a';
			cout << temp;
			check = true;
		}
	}

	if (!check)
		cout << "PREDAJA";
}