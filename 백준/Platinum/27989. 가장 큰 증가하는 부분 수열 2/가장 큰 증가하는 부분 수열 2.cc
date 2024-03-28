#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 310000

vector<ll> tree(4 * MAX);

ll update(ll start, ll end, ll node, ll idx, ll val)
{
    if (idx < start || idx > end)
        return tree[node];
    if (start == end)
        return tree[node] = val;

    ll mid = (start + end) / 2;

    return tree[node] = max(update(start, mid, node * 2, idx, val), update(mid + 1, end, node * 2 + 1, idx, val));
}
ll Search(ll start, ll end, ll node, ll left, ll right)
{
    if (left > end || right < start)
        return 0;
    if (left <= start && end <= right)
        return tree[node];

    ll mid = (start + end) / 2;

    return max(Search(start, mid, node * 2, left, right), Search(mid + 1, end, node * 2 + 1, left, right));
}

bool cmp(pair<ll, ll> &a, pair<ll, ll> &b)
{
    return a.second < b.second;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;
    vector<pair<ll, ll>> v(n);
    vector<ll> v2(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i].first;
        v[i].second = i;
        v2[i] = v[i].first;
    }

    sort(v.begin(), v.end());

    ll Y[MAX];
    ll idx = 0;
    for (ll i = 0; i < n; i++)
    {
        if (i > 0 && v[i - 1].first != v[i].first)
            idx++;
        Y[i] = idx;
    }

    for (ll i = 0; i < n; i++)
    {
        v[i].first = Y[i];
    }

    sort(v.begin(), v.end(), cmp);

    for (ll i = 0; i < n; i++)
    {
        ll temp = Search(0, MAX, 1, 0, v[i].first - 1);
        ll next = temp + v2[i];
        update(0, MAX, 1, v[i].first, next);
    }

    cout << Search(0, MAX, 1, 0, MAX);

    return 0;
}