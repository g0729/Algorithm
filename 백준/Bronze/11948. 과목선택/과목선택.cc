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
	vector<int> v(4);
	vector<int> v2(2);

	for (int i = 0; i < 4; i ++)
	{
		cin >> v[i];
	}

	for (int i = 0; i < 2; i++)
	{
		cin >> v2[i];
	}

	sort(v.begin(),v.end());
	sort(v2.begin(),v2.end());

	cout<<v[1]+v[2]+v[3]+v2[1];
	return 0;
}