#include <bits/stdc++.h>
using namespace std;

int main()
{
	int cnt[10]={};

	string s;

	cin>>s;

	for (int i = 0; i < s.length(); i++)
	{
		cnt[s[i]-'0']++;
	}

	for(int i = 0 ; i<10;i++)
	{
		if(i!=2&&i!=0&&i!=1&&i!=8)
		{
			if(cnt[i]>=1)
			{
				cout<<"0";
				return 0;
			}
		}
	}
	if(cnt[2]>=1&&cnt[0]>=1&&cnt[1]>=1&&cnt[8]>=1)
	{
		if(cnt[2]==cnt[0]&&cnt[2]==cnt[1]&&cnt[2]==cnt[8])
		{
			cout<<"8";
		}
		else
		{
			cout<<"2";
		}
	}
	else
	{
		cout<<"1";
		return 0;
	}


}