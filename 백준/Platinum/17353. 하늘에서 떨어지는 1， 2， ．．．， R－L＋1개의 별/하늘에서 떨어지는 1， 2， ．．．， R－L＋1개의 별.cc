#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100010

vector<ll> tree(4 * MAX);
vector<ll> lazy(4 * MAX);
vector<ll> v(MAX);

ll init(ll start, ll end, ll node)
{
    if (start == end)
        return tree[node] = v[start] - v[start - 1];

    ll mid = (start + end) / 2;

    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

void update_lazy(ll start, ll end, ll node)
{
    if (lazy[node])
    {
        tree[node] += (end - start + 1) * lazy[node];
        if (start != end)
        {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

ll update(ll start, ll end, ll node, ll left, ll right, ll val)
{
    update_lazy(start, end, node);
    if (left > end || right < start)
        return tree[node];
    if (left <= start && end <= right)
    {
        if (start != end)
        {
            lazy[node * 2] += val;
            lazy[node * 2 + 1] += val;
        }
        return tree[node] += (end - start + 1) * val;
    }

    ll mid = (start + end) / 2;

    return tree[node] = update(start, mid, node * 2, left, right, val) + update(mid + 1, end, node * 2 + 1, left, right, val);
}

ll sum(ll start, ll end, ll node, ll left, ll right)
{
    update_lazy(start, end, node);
    if (left > end || right < start)
        return 0;
    if (left <= start && end <= right)
        return tree[node];

    ll mid = (start + end) / 2;

    return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    init(1, n, 1);

    ll m;
    cin >> m;
    for (ll i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b;
        if (a == 1)
        {
            cin >> c;
            update(1, n, 1, b, c, 1);
            update(1, n, 1, c + 1, c + 1, -(c - b + 1));
        }
        else
        {
            cout << sum(1, n, 1, 1, b) << "\n";
        }
    }

    return 0;
}