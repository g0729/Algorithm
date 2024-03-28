#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;

	for (int i = 0; i < s.length(); i++)
	{
		if(s[i]!=s[s.length()-i-1])
		{
			cout<<"0";
			return 0;
		}
	}
	
	cout<<"1";

	 
	return 0;
}