#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	vector<pair<int,int>>v(3);
	
	int sum=0;
	for (int i = 0; i < 3; i++)
	{
		cin>>v[i].first;
		v[i].second=i;
		sum+=v[i].first;
	}
	
	if(sum>=100)
		cout<<"OK";
	else
	{
		sort(v.begin(),v.end());

		int 	temp=v[0].second;

		if(temp==0)
			cout<<"Soongsil";
		else if(temp==1)
			cout<<"Korea";
		else
			cout<<"Hanyang";
	}

	return 0;
}