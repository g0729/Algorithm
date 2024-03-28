#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	
	int n,m;

	cin>>n>>m;

	for (int i = 0; i < n; i++)
	{
		cin>>s;

		for (int j = 0; j < s.length(); j++)
		{
			cout<<s[s.length()-j-1];
		}
		cout<<"\n";
	}
	
}