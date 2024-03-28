#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	stack<pair<int,int>>s;
	for(int i = 0 ; i<n;i++)
	{
		int now;
		cin>>now;
		while(!s.empty()&&s.top().first<now)
		{
			s.pop();
		}
		if(s.empty())
		{
			s.push({now,i+1});
			cout<<"0 ";
		}
		else
		{
			cout<<s.top().second<<" ";
			s.push({now,i+1});
		}
	}
}