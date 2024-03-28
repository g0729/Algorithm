#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 750000

vector<ll> tree;

int update(int start, int end, int node, int idx)
{
    if (idx < start || idx > end)
        return tree[node];
    if (start == end)
        return tree[node] += 1;

    int mid = (start + end) / 2;

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

bool cmp(pair<ll, ll> &a, pair<ll, ll> &b)
{
    return a.second < b.second;
}

bool cmp2(pair<ll, ll> &a, pair<ll, ll> &b)
{
    if (a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
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
        ll n;
        ll idx = 0;
        cin >> n;

        tree = vector<ll>(4 * MAX);

        vector<pair<ll, ll>> v(n);

        for (ll i = 0; i < n; i++)
        {
            cin >> v[i].first >> v[i].second;
        }
        sort(v.begin(), v.end(), cmp);

        ll Y[MAX];

        for (ll i = 0; i < n; i++)
        {
            if (i > 0 && v[i - 1].second != v[i].second)
                idx++;
            Y[i] = idx;
        }

        for (ll i = 0; i < n; i++)
        {
            v[i].second = Y[i];
        }

        sort(v.begin(), v.end(), cmp2);

        ll res = 0;

        for (ll i = 0; i < n; i++)
        {
            res += sum(0, MAX, 1, v[i].second, MAX);
            update(0, MAX, 1, v[i].second);
        }
        cout << res << "\n";
    }
    return 0;
}