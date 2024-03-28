#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 200010

vector<ll> Mllree(4 * (MAX + 1));
vector<ll> Sumtree(4 * (MAX + 1));
ll n;

void update(ll start, ll end, ll node, ll idx, ll val)
{
    if (idx < start || idx > end)
        return;

    if (start == end)
    {
        Mllree[node] = val;
        Sumtree[node] = val;
        return;
    }

    ll mid = (start + end) / 2;

    update(start, mid, node * 2, idx, val);
    update(mid + 1, end, node * 2 + 1, idx, val);

    Mllree[node] = min(Mllree[node * 2], Mllree[node * 2 + 1]);
    Sumtree[node] = Sumtree[node * 2] + Sumtree[node * 2 + 1];

    return;
}
ll Min(ll start, ll end, ll node, ll left, ll right)
{
    if (right < start || left > end)
        return 1e9 + 1;
    if (left <= start && end <= right)
        return Mllree[node];

    ll mid = (start + end) / 2;

    return min(Min(start, mid, node * 2, left, right), Min(mid + 1, end, node * 2 + 1, left, right));
}
ll Sum(ll start, ll end, ll node, ll left, ll right)
{
    if (right < start || left > end)
        return 0;
    if (left <= start && end <= right)
        return Sumtree[node];

    ll mid = (start + end) / 2;

    return Sum(start, mid, node * 2, left, right) + Sum(mid + 1, end, node * 2 + 1, left, right);
}
ll Solve(ll i, ll val)
{
    ll l, r;
    ll left, right, mid;

    left = 0;
    right = i;

    while (left + 1 < right)
    {
        mid = (left + right) / 2;
        if (Min(1, n, 1, mid, i) >= val)
            right = mid;
        else
            left = mid;
    }

    l = right;

    left = i;
    right = n+1;

    while (left + 1 < right)
    {
        mid = (left + right) / 2;

        if (Min(1, n, 1, i, mid) >= val)
            left = mid;
        else
            right = mid;
    }

    r = left;

    return Sum(1, n, 1, l, r);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (ll i = 1; i <= n; i++)
    {
        ll a;
        cin >> a;
        update(1, n, 1, i, a);
    }

    ll m;
    cin >> m;

    for (ll i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;

        if (a == 1)
            update(1, n, 1, b, c);
        else
            cout << Solve(b, c) << "\n";
    }

    return 0;
}