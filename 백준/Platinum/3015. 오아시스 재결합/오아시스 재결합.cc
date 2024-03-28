#include<bits/stdc++.h>
using namespace std;

int main()
{
	stack<pair<int,int>>s;
	int n;
	long long res=0;
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		int now;
		cin>>now;
		while(!s.empty()&&s.top().first<now)
		{
			res+=s.top().second;
			s.pop();
		}
		if(s.empty())
		{
			s.push({now,1});
		}
		else
		{
			if(s.top().first==now)
			{
				pair<int,int>temp=s.top();
				s.pop();
				res+=temp.second;
				if(!s.empty())
					res++;
				temp.second++;
				s.push(temp);
			}
			else
			{
				s.push({now,1});
				res++;
			}
		}
	}
	cout<<res;
}