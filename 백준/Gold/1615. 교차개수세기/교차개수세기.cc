#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 2000
#define INF 987654321

vector<ll> tree(4 * MAX);
vector<pair<ll, ll>> edges;

ll update(ll start, ll end, ll node, ll idx)
{
    if (start > idx || idx > end)
        return tree[node];
    if (start == end)
        return tree[node] += 1;

    ll mid = (start + end) / 2;

    return tree[node] = update(start, mid, node * 2, idx) + update(mid + 1, end, node * 2 + 1, idx);
}

ll sum(ll start, ll end, ll node, ll left, ll right)
{
    if (right < start or left > end)
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
    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i < m; i++)
    {
        pair<ll, ll> a;
        cin >> a.first >> a.second;
        edges.push_back(a);
    }

    sort(edges.begin(), edges.end());

    ll answer = 0;
    for (auto it : edges)
    {
        update(1, n, 1, it.second);
        answer += sum(1, n, 1, it.second + 1, n);
    }

    cout << answer;

    return 0;
}