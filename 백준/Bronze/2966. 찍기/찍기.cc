#include<bits/stdc++.h>
using namespace std;
string a="ABC";
string b="BABC";
string g="CCAABB";
string ans[]={
	"Adrian","Bruno","Goran"
};
int main()
{
	int n;
	cin>>n;
	string res;
	cin>>res;
	int cnt[3]={0};
	for (int  i = 0; i < n; i++)
	{
		if(res[i]==a[i%3])
		cnt[0]++;
		if(res[i]==b[i%4])
		cnt[1]++;
		if(res[i]==g[i%6])
		cnt[2]++;
	}
	int max=0;
	for (int i = 0; i < 3; i++)
	{
		if(cnt[i]>max)
		max=cnt[i];		
	}
    cout<<max<<endl;
	for (int i = 0; i < 3; i++)
	{
		if(cnt[i]==max)
		cout<<ans[i]<<endl;
	}
	
}