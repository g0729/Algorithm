#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long
#define MOD 1000000007


int cnt(int n)
{
	string s=to_string(n);

	int res=0;
	for (int i = 0; i < s.length(); i++)
	{
		if(s[i]=='0')
			res++;
	}
	
	return res;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin>>t;

	while(t--)
	{
		int n,m;
		cin>>n>>m;

		int res=0;
		for (int i = n; i <= m; i++)
		{
			res+=cnt(i);
		}
		

		cout<<res<<"\n";
	}
	return 0;
}