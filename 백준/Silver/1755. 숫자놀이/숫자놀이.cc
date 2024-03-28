#include <bits/stdc++.h>
using namespace std;

int main()
{
	string number[10]={"zero","one","two","three","four","five","size","seven","eight","nine"};
	int n,m;
	cin>>n>>m;
	vector<pair<string,int>>v;

	for (int i = n; i <= m; i++)
	{
		string temp;
		string temp2;
		temp2=to_string(i);
		for (int j = 0; j < temp2.length(); j++)
		{
			temp+=number[temp2[j]-'0'];
		}
		v.push_back({temp,i});
	}
	
	sort(v.begin(),v.end());

	for (int i = 0; i < v.size(); i++)
	{
		cout<<v[i].second<<" ";
		if(i%10==9)
		{
			cout<<endl;
		}
	}
	
}