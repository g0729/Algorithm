#include<bits/stdc++.h>
using namespace std;

int main()
{
	int l,k;
	cin>>l;
	vector<int>v(l);
	for (int i = 0; i < l; i++)
	{
		cin>>v[i];
	}
	cin>>k;
	sort(v.begin(),v.end());
	auto it=lower_bound(v.begin(),v.end(),k);
	int start=*(it-1);
	int end=*it;
	if(end==k)
	{
		cout<<"0";
		return 0;
	}
	int temp1=end-k;
	int temp2=k-start;
	int res=0;

	for (int i = 0; i < temp2; i++)
	{
		res+=temp1;
		temp1;
	}
	cout<<res-1;
}