#include<bits/stdc++.h>
using namespace std;
int sum[100000];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int n,m;
    cin>>n>>m;
    cin>>sum[1];
    for (int i = 2; i <= n; i++)
    {
        int a;
        cin>>a;
        sum[i]=sum[i-1]+a;
    }
    for (int i = 0; i < m; i++)
    {
        int a,b;
        cin>>a>>b;
        cout<<sum[b]-sum[a-1]<<"\n";
    }
}
