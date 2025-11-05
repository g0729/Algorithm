#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100010
#define INF 987654321
ll dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
ll dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

ll n;
vector<ll> tree(4 * MAX);
vector<ll> v(MAX);

struct query2 {
    ll a, b, c, d;
    query2(ll a, ll b, ll c, ll d) : a(a), b(b), c(c), d(d) {};
    query2() : a(0), b(0), c(0), d(0) {};
};
ll init(ll start, ll end, ll node) {
    if (start == end) {
        return tree[node] = v[start];
    }

    ll mid = (start + end) / 2;

    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

ll update(ll start, ll end, ll node, ll idx, ll val) {
    if (idx < start || idx > end) return tree[node];
    if (start == end) return tree[node] = val;

    ll mid = (start + end) / 2;

    return tree[node] = update(start, mid, node * 2, idx, val) + update(mid + 1, end, node * 2 + 1, idx, val);
}

ll sum(ll start, ll end, ll node, ll left, ll right) {
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node];

    ll mid = (start + end) / 2;

    return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> v[i];
    }
    init(1, n, 1);

    ll m;
    cin >> m;
    vector<pair<ll, ll>> query_1;
    vector<query2> query_2;
    ll idx = 0;
    while (m--) {
        ll op;
        cin >> op;
        if (op == 1) {
            pair<ll, ll> a;
            cin >> a.first >> a.second;
            query_1.push_back(a);
        } else if (op == 2) {
            query2 a;
            cin >> a.a >> a.b >> a.c;
            a.d = idx++;
            query_2.push_back(a);
        }
    }

    sort(query_2.begin(), query_2.end(), [](query2 &a, query2 &b) { return a.a < b.a; });
    ll cur = 0;
    vector<ll> res(query_2.size());

    for (auto &a : query_2) {
        while (cur < a.a) {
            update(1, n, 1, query_1[cur].first, query_1[cur].second);
            cur++;
        }
        res[a.d] = sum(1, n, 1, a.b, a.c);
    }

    for (ll i = 0; i < res.size(); i++) {
        cout << res[i] << "\n";
    }

    return 0;
}