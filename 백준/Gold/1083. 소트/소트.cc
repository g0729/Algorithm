#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<pair<int,int>>v;
	int n;
	cin>>n;
	vector<int>cv;
	for(int i = 0;i<n;i++)
	{
		int a;
		cin>>a;
		v.push_back({a,0});
		cv.push_back(a);
	}
	sort(cv.begin(),cv.end());
	cv.erase(unique(cv.begin(),cv.end()),cv.end());
	for(int i = 0 ; i<n;i++)
	{
		for(int j = 0  ; j<n;j++)
		{
			if(v[i].first==cv[j])
			{
				v[i].second=j;
			}
		}
	}
	int s;
	cin>>s;

	for(int i = 0 ; i<n-1;i++)
	{
		int MAX=v[i].second;
		int MAX_i=i;
		for(int j =i+1;j-i<=s&&j<n;j++)
		{
			if(MAX<v[j].second)
			{
				MAX=v[j].second;
				MAX_i=j;
			}
		}
		if(MAX==v[i].second)
		continue;
		auto temp=v[MAX_i];
		v.erase(v.begin()+MAX_i);
		v.insert(v.begin()+i,temp);
		
		s=s-(MAX_i-i);
		if(s==0)
		break;
	}
	for(int i = 0 ; i<n;i++)
	{
		cout<<v[i].first<<" ";
	}
}