#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	stack<pair<char,int>>st;

	cin>>s;

	int res=0;

	for(int i = 0 ; i<s.length();i++)
	{
		if(s[i]==')')
		{
			int length=0;
			while(st.top().first!='(')
			{
				length+=st.top().second;
				st.pop();
			}
			st.pop();
			int multi=st.top().first-'0';
			st.pop();
			st.push({'1',length*multi});
			continue;
		}
		st.push({s[i],1});
	}
	while(!st.empty())
	{
		res+=st.top().second;
		st.pop();
	}

	cout<<res;
}