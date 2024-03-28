#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;

	cin>>n;

	for (int i = 1; i <= n; i++)
	{
		int t;
		cin>>t;
		vector<int>v(t);

		for (int j = 0; j < t; j++)
		{
			cin>>v[j];
		}
		
		sort(v.begin(),v.end());
		
		int gap=0;
		for (int j = 0; j < t-1; j++)
		{
			gap=max(gap,v[j+1]-v[j]);
		}
		
		cout<<"Class "<<i<<endl;
		cout<<"Max "<<v[t-1]<<", Min "<<v[0]<<", Largest gap "<<gap<<endl;
	}
	
}