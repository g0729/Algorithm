#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cout.precision(10);
	int n;
	cin>>n;
	vector<double>v(n);
	double res=0;
	for (int i = 0; i < n; i++)
	{
		cin>>v[i];
		res+=v[i];
	}
	
	for (int i = 0; i < n-1; i++)
	{
		res+=v[i]*(1-v[i+1])+(1-v[i])*v[i+1];
	}
	
	cout<<res;
	return 0;
}