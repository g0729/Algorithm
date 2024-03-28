#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 200000

vector<ll> tree;
vector<ll> p;
ll init(ll start, ll end, ll node)
{
    if (start == end)
        return tree[node] = p[start];

    ll mid = (start + end) / 2;

    return tree[node] = max(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
}
ll search(ll start, ll end, ll node, ll val)
{
    if (start == end)
        return start;

    ll mid = (start + end) / 2;

    if (tree[node * 2] >= val)
        return search(start, mid, node * 2, val);
    else if (tree[node * 2 + 1] >= val)
        return search(mid + 1, end, node * 2 + 1, val);
    else
        return 0;
}
ll update(ll start, ll end, ll node, ll idx)
{
    if (idx < start || idx > end)
        return tree[node];

    if (start == end)
        return tree[node] = 0;

    ll mid = (start + end) / 2;

    return tree[node] = max(update(start, mid, node * 2, idx), update(mid + 1, end, node * 2 + 1, idx));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin >> t;

    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        tree = vector<ll>(4 * (MAX + 1));
        p = vector<ll>(n + 1);
        for (ll i = 1; i <= n; i++)
            cin >> p[i];

        init(1, n, 1);

        vector<ll> res(n + 1);

        for (ll i = 1; i <= m; i++)
        {
            ll a;
            cin >> a;
            ll temp = search(1, n, 1, a);
            res[temp] = i;
            update(1, n, 1, temp);
        }
        ll ans = 0;
        for (ll i = 1; i <= n; i++)
            ans += res[i] * i;

        cout << ans << "\n";
    }
    return 0;
}