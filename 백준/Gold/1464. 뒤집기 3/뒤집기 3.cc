#include<bits/stdc++.h>
using namespace std;

int main()
{
	string res,s;
	cin>>s;
	res+=s[0];
	for (int i = 1; i < s.length(); i++)
	{
		if(res[0]>=s[i])
		{
			reverse(res.begin(),res.end());
			res.push_back(s[i]);
			reverse(res.begin(),res.end());
		}
		else
		{
			res.push_back(s[i]);
		}
	}
	cout<<res;
}