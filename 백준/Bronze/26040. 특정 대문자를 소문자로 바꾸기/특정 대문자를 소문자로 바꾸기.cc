#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

bool alpha[26];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;

	while (1)
	{
		char c;
		cin >> c;
		if(cin.eof())
			break;

		alpha[c-'A']=true;
	}

	for (int i = 0; i < s.length(); i++)
	{
		if(alpha[s[i]-'A'])
			s[i]=tolower(s[i]);
	}
	
	cout<<s;
	return 0;
}