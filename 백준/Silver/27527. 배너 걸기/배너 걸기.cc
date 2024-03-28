#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

int cnt[1000001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> v(n);

	for (int i = 0; i < n; i++)
		cin >> v[i];
	
	int limit=(9*m+9)/10;

	for (int i = 0; i < m; i++)
	{
		cnt[v[i]]++;
		if(cnt[v[i]]>=limit)
		{
			cout<<"YES";
			return 0;
		}
	}
	
	for (int i = m; i < n; i++)
	{
		cnt[v[i]]++;
		cnt[v[i-m]]--;

		if(cnt[v[i]]>=limit)
		{
			cout<<"YES";
			return 0;
		}
	}

	cout<<"NO";

	return 0;
}