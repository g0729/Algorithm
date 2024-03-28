#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 1500000

ll dp[MAX+1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;
    vector<pair<ll, ll>> v(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    dp[0] = v[0].second;

    for (ll i = n-1; i>=0; i--)
    {
        if (v[i].first + i > n)
            dp[i]=dp[i+1];
        else
            dp[i]=max(dp[i+1],v[i].second+dp[i+v[i].first]);
    }

    cout << dp[0];

    return 0;
}