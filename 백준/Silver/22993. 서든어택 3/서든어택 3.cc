#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<lint> v(n-1);
	lint damage;

	cin>>damage;
	for (int i = 0; i < n-1; i++)
	{
		cin>>v[i];
	}
	
	
	sort(v.begin(),v.end());

	for (int i = 0; i < n-1; i++)
	{
		if(v[i]<damage)
		{
			damage+=v[i];
		}
		else
		{
			cout<<"No";
			return 0;
		}
	}
	
	cout<<"Yes";

	return 0;
}