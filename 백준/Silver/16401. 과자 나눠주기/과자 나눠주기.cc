#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

int n, m;
vector<int> v;

bool check(int target)
{
	int cnt=0;
	for (int i = 0; i < v.size(); i++)
	{
		cnt+=v[i]/target;
	}
	
	if(cnt>=m)
		return true;
	else
		return false;
}
int binSaerch()
{
	int start=0;
	int end=1e9;

	while(start+1<end)
	{
		int mid=(start+end)/2;

		if(check(mid))
			start=mid;
		else
			end=mid;
	}		

	return start;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin>>m>>n;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin>>a;
		v.push_back(a);
	}
	
	cout<<binSaerch();

	return 0;
}