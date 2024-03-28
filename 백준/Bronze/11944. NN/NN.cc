#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	int m;
	cin>>n>>m;
	string s=to_string(n);
	int length=s.length();
	if(length*n<=m)
	{
		for (int i = 0; i < n; i++)
		{
			cout<<s;
		}
	}
	else
	{
		for (int i = 0; i < m; i++)
		{
			cout<<s[i%length];
		}
		
	}

}