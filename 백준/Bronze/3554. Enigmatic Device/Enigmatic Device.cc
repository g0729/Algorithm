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

	int n;
	cin >> n;

	vector<int> v(n+1);

	for (int i = 1; i <= n; i++)
	{
		cin>>v[i];
	}
	
	int m;
	cin>>m;

	for (int i = 0; i < m; i++)
	{
		int a,b,c;
		cin>>a>>b>>c;

		if(a==1)
		{
			for (int j = b; j <= c; j++)
			{
				v[j]=(v[j]*v[j])%2010;
			}
		}
		else
		{
			int sum=0;
			for (int j = b; j <= c; j++)
			{
				sum+=v[j];
			}
			cout<<sum<<"\n";
		}
		
	}
	
	return 0;
}