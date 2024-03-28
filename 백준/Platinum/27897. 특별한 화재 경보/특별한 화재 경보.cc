#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 500000

vector<ll> tree(4 * (MAX + 1));

ll update(ll start, ll end, ll node, ll idx)
{
    if (idx < start || idx > end)
        return tree[node];

    if (start == end)
        return tree[node] += 1;

    ll mid = (start + end) / 2;

    return tree[node] = update(start, mid, node * 2, idx) + update(mid + 1, end, node * 2 + 1, idx);
}

ll sum(ll start, ll end, ll node, ll left, ll right)
{
    if (right < start || left > end)
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

    ll n, l;
    cin >> n >> l;

    ll res = 0;
    for (ll i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        update(1, n, 1, a);
        res += sum(1, n, 1, a + 1, n);
    }

    cout << min(res + l, (n * (n - 1) / 2));
    return 0;
}