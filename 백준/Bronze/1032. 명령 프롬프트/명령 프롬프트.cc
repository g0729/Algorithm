#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<string>v;

	int n;

	cin>>n;

	for (int i = 0; i < n; i++)
	{
		string s;

		cin>>s;

		v.push_back(s);
	}

	string res;

	for (int i = 0; i < v[0].length(); i++)
	{
		bool check=true;

		for (int j = 1; j < n; j++)
		{
			if(v[j][i]!=v[0][i])
			check=false;

			if(!check)
			break;
		}
		if(check)
		res+=v[0][i];
		else
		res+="?";
	}
		
		cout<<res;
}