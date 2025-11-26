#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 500001
#define INF 987654321
ll dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
ll dy[] = {0, 0, 1, -1, -1, 1, -1, 1};
vector<ll> tree(4 * MAX);
vector<ll> v(MAX);

ll init(ll start, ll end, ll node) {
    if (start == end) return tree[node] = v[start];
    ll mid = (start + end) / 2;

    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

ll sum(ll start, ll end, ll node, ll left, ll right) {

    if (left > right) return 0;
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node];

    ll mid = (start + end) / 2;

    return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

ll update(ll start, ll end, ll node, ll idx) {

    if (idx > end || idx < start) return tree[node];
    if (start == end) return tree[node] = 0;

    ll mid = (start + end) / 2;

    return tree[node] = update(start, mid, node * 2, idx) + update(mid + 1, end, node * 2 + 1, idx);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, m;
    cin >> n >> m;
    for (ll i = 1; i <= n; i++) cin >> v[i];

    init(1, n, 1);

    while (m--) {
        ll a;
        cin >> a;
        cout << sum(1, n, 1, 1, a - 1) + 1 << " ";
        update(1, n, 1, a);
    }
    return 0;
}