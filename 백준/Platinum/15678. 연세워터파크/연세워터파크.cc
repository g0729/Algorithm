#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

vector<ll> tree(4 * (MAX + 1));
vector<ll>dp(MAX+1);
vector<ll>v(MAX+1);
ll update(ll start, ll end, ll node, ll idx, ll val)
{
    if (idx < start || idx > end)
        return tree[node];
    if (start == end)
        return tree[node] = val;

    ll mid = (start + end) / 2;

    return tree[node] = max(update(start, mid, node * 2, idx, val), update(mid + 1, end, node * 2 + 1, idx, val));
}

ll Max(ll start, ll end, ll node, ll left, ll right)
{
    if (right < start || left > end)
        return -1e10;
    if (left <= start && end <= right)
        return tree[node];

    ll mid = (start + end) / 2;

    return max(Max(start, mid, node * 2, left, right), Max(mid + 1, end, node * 2 + 1, left, right));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n,d;
    cin>>n>>d;

    for (ll i = 1; i <= n; i++)
        cin>>v[i];

    dp[1]=v[1];

    update(1,n,1,1,dp[1]);

    for (ll i = 2; i <= n; i++)
    {
        dp[i]=v[i];

        ll left=max((ll)1,i-d);

        dp[i]=max(dp[i],Max(1,n,1,left,i-1)+v[i]);

        update(1,n,1,i,dp[i]);
    }
    
    ll res=-1e10;

    for (ll i = 1; i <= n; i++)
        res=max(res,dp[i]);

    cout<<res;
    return 0;
}