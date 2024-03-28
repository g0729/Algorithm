#include<bits/stdc++.h>
using namespace std;
map<string,int>name;
map<int,string>num;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n,m;
	cin>>n>>m;
	for (int i = 1; i <= n; i++)
	{
		string s;
		cin>>s;
		name.insert({s,i});
		num.insert({i,s});
	}
	while(m--)
	{
		string s;
		cin>>s;
		if(isdigit(s[0]))
		{
			int a=stoi(s);
			cout<<num[a]<<"\n";
		}
		else
		{
			cout<<name[s]<<"\n";
		}
	}
}