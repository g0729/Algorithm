#include <bits/stdc++.h>
using namespace std;
#define lint long long
#define MAX 1000001
lint f[MAX];
lint g[MAX];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for (int i = 1; i < MAX; i++)
	{
		for(int j=i; j<MAX;j+=i)
		{
			f[j]+=i;
		}
	}
	for (int i = 1; i < MAX; i++)
	{
		g[i]=g[i-1]+f[i];
	}
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		cout<<g[n]<<"\n";
	}
}