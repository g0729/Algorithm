#include <bits/stdc++.h>
using namespace std;
bool cmp(int &a,int& b)
{
	return a>b;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<int>v;
	int n;
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin>>a;
		v.push_back(a);
	}
	sort(v.begin(),v.end(),cmp);

	for (int i = 0; i < n-2; i++)
	{
		if(v[i+1]+v[i+2]>v[i])
		{
			cout<<v[i]+v[i+1]+v[i+2];
			return 0;
		}
	}
	cout<<"-1";
	return 0;
}