#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

ll update(ll start, ll end, ll node, ll idx, vector<ll> &tree)
{
    if (idx < start || idx > end)
        return tree[node];

    if (start == end)
        return tree[node] = 1;

    ll mid = (start + end) / 2;

    return tree[node] = update(start, mid, node * 2, idx, tree) + update(mid + 1, end, node * 2 + 1, idx, tree);
}
ll sum(ll start, ll end, ll node, ll left, ll right, vector<ll> &tree)
{
    if (right < start || left > end)
        return 0;

    if (left <= start && end <= right)
        return tree[node];

    ll mid = (start + end) / 2;

    return sum(start, mid, node * 2, left, right, tree) + sum(mid + 1, end, node * 2 + 1, left, right, tree);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (1)
    {
        ll n;
        cin >> n;
        if (n == 0)
            break;
        map<string, ll> ma;
        vector<ll> tree(4 * (n + 1));

        ll res = 0;
        for (ll i = 1; i <= n; i++)
        {
            string s;
            cin >> s;
            ma[s] = i;
        }

        for (ll i = 1; i <= n; i++)
        {
            string s;
            cin >> s;
            ll now = ma[s];

            res += sum(1, n, 1, now + 1, n, tree);
            update(1, n, 1, now, tree);
        }

        cout << res << "\n";
    }
    return 0;
}