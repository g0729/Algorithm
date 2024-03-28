#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 200000

vector<ll> tree;
bool cmp(pair<pair<ll, ll>, ll> &a, pair<pair<ll, ll>, ll> &b)
{
    if (a.first.first == b.first.first)
        return a.first.second < b.first.second;

    return a.first.first < b.first.first;
}
bool cmp2(pair<pair<ll, ll>, ll> &a, pair<pair<ll, ll>, ll> &b)
{
    if (a.first.first == b.first.first)
        return a.first.second < b.first.second;
    return a.first.first > b.first.first;
}
bool cmp3(pair<pair<ll, ll>, ll> &a, pair<pair<ll, ll>, ll> &b)
{
    return a.first.second < b.first.second;
}
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
    vector<pair<pair<ll, ll>, ll>> v(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> v[i].first.first >> v[i].first.second;
        v[i].second = i;
    }

    sort(v.begin(), v.end(), cmp3);
    ll idx = 0;

    ll cnt[MAX];
    for (ll i = 0; i < n; i++)
    {
        if (i > 0 && v[i].first.second != v[i - 1].first.second)
            idx++;
        cnt[i] = idx;
    }
    for (ll i = 0; i < n; i++)
    {
        v[i].first.second = cnt[i];
    }
    tree = vector<ll>(4 * MAX);

    sort(v.begin(), v.end(), cmp);

    for (ll i = 0; i < n; i++)
    {
        cnt[v[i].second] = sum(0, MAX, 1, v[i].first.second + 1, MAX);
        update(0, MAX, 1, v[i].first.second);
    }
    sort(v.begin(), v.end(), cmp2);

    ll res = 0;
    tree = vector<ll>(4 * MAX);

    for (ll i = 0; i < n; i++)
    {
        res += cnt[v[i].second] * sum(0, MAX, 1, v[i].first.second + 1, MAX);
        res %= MOD;
        update(0, MAX, 1, v[i].first.second);
    }

    cout << res;
    return 0;
}