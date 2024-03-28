#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while(1)
	{
		string s;

		getline(cin,s);

		if(cin.eof())
			break;

		for (int i = 0; i < s.length(); i++)
		{
			if(s[i]=='e')
				s[i]='i';
			else if(s[i]=='i')
				s[i]='e';
			else if(s[i]=='E')
				s[i]='I';
			else if(s[i]=='I')
				s[i]='E';
		}
		
		cout<<s<<"\n";
	}
	return 0;
}