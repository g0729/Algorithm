#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

int cnt;
int recursion(string& s, int l, int r)
{	
	cnt++;
	if (l >= r)
		return 1;
	else if (s[l] != s[r])
		return 0;
	else
		return recursion(s, l + 1, r - 1);
}

int isPalindrome(string& s)
{
	return recursion(s, 0, s.length() - 1);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin>>t;

	while(t--)
	{
		string s;
		cin>>s;
		int res=isPalindrome(s);

		cout<<res<<" "<<cnt<<"\n";

		cnt=0;
	}
	return 0;
}