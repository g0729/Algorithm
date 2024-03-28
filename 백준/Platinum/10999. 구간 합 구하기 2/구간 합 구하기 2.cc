#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 1000000

vector<ll> tree(4 * MAX);
vector<ll> v(MAX);
vector<ll> lazy(4 * MAX);
ll init(ll start, ll end, ll node)
{
    if (start == end)
        return tree[node] = v[start];

    ll mid = (start + end) / 2;

    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}
void update_lazy(ll start, ll end, ll node)
{
    if (lazy[node] != 0)
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

    ll n, k, m;
    cin >> n >> m >> k;
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    init(0, n - 1, 1);
    for (ll i = 0; i < m + k; i++)
    {
        ll a, b, c, d;
        cin >> a;
        if (a == 1)
        {
            cin >> b >> c >> d;
            update(0, n - 1, 1, b - 1, c - 1, d);
        }
        else
        {
            cin >> b >> c;
            cout << sum(0, n - 1, 1, b - 1, c - 1) << "\n";
        }
    }

    return 0;
}