#include <bits/stdc++.h>
using namespace std;

int main()
{
	int k;
	cin >> k;

	vector<int> v;
	int a, len2,len0;
	cin >> a >> len2;
	len0=len2;
	for (int i = 1; i < 6; i++)
	{
		int len;
		cin >> a >> len;
		v.push_back(len*len2);
		len2=len;
	}
	v.push_back(len2*len0);
	int MAX=0;
	int MAX_i;
	for (int i = 0; i <6; i++)
	{
		if(MAX<v[i])
		{
			MAX=v[i];
			MAX_i=i;
		}
	}

	int res=MAX-v[(MAX_i+3)%6];

	cout<<res*k;
	
}