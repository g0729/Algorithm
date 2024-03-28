#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

lint n, k;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;

	vector<lint> v(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	lint res=k;
	for (int i = 0; i < n - 1; i++)
	{
		lint teamA, teamB;

		teamA = v[0] * (i + 1);
		teamB = v[i + 1] * (n - i - 1);

		lint teamSum=teamA+teamB;

		res=min(res,(k+teamSum-1)/teamSum);
	}

	cout<<res;

	return 0;
}