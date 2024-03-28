#include <bits/stdc++.h>
using namespace std;
vector<long long>v;
long long n;
long long p,q,r,s;

long long check(long long num)
{
	long long sum=0;
	for(long long i = 0 ; i<n;i++)
	{
		if(v[i]>num+r)
		sum+=v[i]-p;
		else if(v[i]<num)
		sum+=v[i]+q;
		else
		sum+=v[i];
	}
return sum;
}
long long binsearch()
{
	long long start=1;
	long long end=110000;
	while(start<end)
	{
		long long mid=(start+end)/2;
		long long temp=check(mid);
		if(temp<s)
		{
			start=mid+1;
		}
		else
		{
			end=mid;
		}
	}
	return end;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(long long i = 0 ;i<n;i++)
	{
		long long a;
		cin>>a;
		v.push_back(a);

	}
	cin>>p>>q>>r>>s;
	

	long long res=binsearch();
	if(res==110000)
	cout<<"-1";
	else
	cout<<res;
}