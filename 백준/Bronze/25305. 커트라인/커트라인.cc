#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<int>v;

	int n,k;

	cin>>n>>k;

	for (int i = 0; i < n; i++)
	{
		int a;

		cin>>a;

		v.push_back(a);
	}
	
	sort(v.begin(),v.end(),greater<int>());

	cout<<v[k-1];
}