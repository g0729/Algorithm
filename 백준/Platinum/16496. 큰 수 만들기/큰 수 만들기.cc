#include <bits/stdc++.h>
using namespace std;

bool cmp(string a,string b)
{
	return a+b>b+a;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<string>v;
	int n;
	cin>>n;
	for(int i = 0; i <n;i++)
	{
		string temp;
		cin>>temp;
		v.push_back(temp);
	}
	sort(v.begin(),v.end(),cmp);
	if(v[0]=="0")
	{
		cout<<"0";
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		cout<<v[i];
	}
}