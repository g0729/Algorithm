#include<bits/stdc++.h>
using namespace std;

int sum[100001];
int main()
{
    
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int n;
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
       int a;
       cin>>a;
       sum[i]=sum[i-1]+a;
    }
    int m;
    cin>>m;
    for (int i = 0; i < m; i++)
    {
        int a,b;
        cin>>a>>b;
        cout<<sum[b]-sum[a-1]<<"\n";
    }
    
}

