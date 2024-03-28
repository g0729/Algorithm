#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		string s;
		cin>>n;
		cin>>s;
		int resLong,resShort;
		int first=-1;

		for (int i = 0; i < s.length(); i++)
		{
			if(s[i]=='?'||s[i]=='1')
			{
				if(first==-1)
				{
					first=i;
					resLong=n+(s.length()-i-1);
				}
				else
				{
					resLong++;
					break;
				}
			}
		}
		if(first==-1)
		{
			resLong=1;
		}
		first=-1;

		for (int i = 0; i < s.length(); i++)
		{
			if(s[i]=='1')
			{
				if(first==-1)
				{
					first=i;
					resShort=n+(s.length()-i-1);
				}
				else
				{
					resShort++;
					break;
				}
			}
		}
		if(first==-1)
		{
			resShort=1;
		}
		cout<<resLong<<" "<<resShort<<"\n";
	}
}