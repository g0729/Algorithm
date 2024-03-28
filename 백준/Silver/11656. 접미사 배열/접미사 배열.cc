#include <bits/stdc++.h>
using namespace std;

int main()
{
	string a;
	vector<string>v;
	cin>>a;
	for (int i = 0; i <a.length(); i++)
	{
		string temp=a.substr(i);
		v.push_back(temp);
	}

	sort(v.begin(),v.end());

	for (int i = 0; i < v.size(); i++)
	{
		cout<<v[i]<<"\n";
	}
	
}