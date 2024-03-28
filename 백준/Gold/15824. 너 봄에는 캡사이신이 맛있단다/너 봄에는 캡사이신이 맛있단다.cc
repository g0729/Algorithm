#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

ll myPow(ll a, ll b)
{
    if (b == 0)
        return 1;

    ll temp = myPow(a, b / 2);
    ll ans = temp * temp % MOD;

    if (b % 2 == 1)
        ans = (ans * a) % MOD;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        cin>>v[i];
    
    sort(v.begin(),v.end());
    ll ans=0;
    for(int i = 0; i < n; i++)
    {
        ans= ans+((v[i]*(myPow(2,i)-myPow(2,n-i-1))%MOD+MOD))%MOD;
        ans%=MOD;
    }
    cout<<ans;
    return 0;
}