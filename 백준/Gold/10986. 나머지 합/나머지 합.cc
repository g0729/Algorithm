#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

int cnt[1001];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<lint> v(n+1);
	vector<lint> sum(n+1);

	for (int i = 1; i <= n; i++)
	{
		cin>>v[i];
		sum[i]=sum[i-1]+v[i];
	}
	cnt[0]=1;
	lint res=0;

	for (int i = 1; i <= n; i++)
	{
		lint temp=sum[i]%m;

		res+=cnt[temp];
		cnt[temp]++;
	}

	cout<<res;
		
	return 0;
}