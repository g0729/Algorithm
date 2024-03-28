#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin>>s;
	int cnt_0=0;
	int cnt_1=0;
	for(auto i:s)
	{
		if(i=='0')
		cnt_0++;
		if(i=='1')
		cnt_1++;
	}
	cnt_0/=2;
	cnt_1/=2;
	
	for(int i = 0 ; i<s.length();i++)
	{
		if(s[i]=='1'&&cnt_1)
		{
			s[i]=2;;
			cnt_1--;
		}
	}
	for(int i = s.length()-1 ; i>=0;i--)
	{
		if(s[i]=='0'&&cnt_0)
		{
			s[i]=2;;
			cnt_0--;
		}
	}
	for (int i = 0; i < s.length(); i++)
	{
		if(s[i]!=2)
		cout<<s[i];
	}
	
}