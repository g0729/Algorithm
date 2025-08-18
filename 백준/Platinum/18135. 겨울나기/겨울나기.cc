#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 1000000
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

vector<ll> tree(4 * MAX);
vector<ll> lazy(4 * MAX);

void update_lazy(ll start, ll end, ll node) {

    if (lazy[node] != 0) {
        tree[node] += (end - start + 1) * lazy[node];

        if (start != end) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

ll update(ll start, ll end, ll node, ll left, ll right, ll val) {
    update_lazy(start, end, node);

    if (end < left || start > right) return tree[node];

    if (left <= start && end <= right) {
        if (start != end) {
            lazy[node * 2] += val;
            lazy[node * 2 + 1] += val;
        }

        return tree[node] += (end - start + 1) * val;
    }

    ll mid = (start + end) / 2;
    return tree[node] =
               update(start, mid, node * 2, left, right, val) + update(mid + 1, end, node * 2 + 1, left, right, val);
}
ll sum(ll start, ll end, ll node, ll left, ll right) {
    update_lazy(start, end, node);

    if (left > end || right < start) return 0;

    if (left <= start && end <= right) return tree[node];

    ll mid = (start + end) / 2;

    return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, m;
    cin >> n >> m;

    vector<ll> v(n + 1);

    for (int i = 1; i <= m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;

        for (int j = a; j <= b; j++) {
            v[j] = i;
        }
        update(1, MAX, 1, i, i, c);
    }

    while (true) {
        ll op, a, b, c;
        cin >> op;
        if (op == 0)
            break;
        else if (op == 1) {
            cin >> a >> b;

            if (a <= b) {
                cout << sum(1, MAX, 1, v[a], v[b]);
            } else {
                cout << sum(1, MAX, 1, v[a], m) + sum(1, MAX, 1, 1, v[b]);
            }
            cout << "\n";

        } else if (op == 2) {
            cin >> a >> b >> c;

            if (a <= b) {
                update(1, MAX, 1, v[a], v[b], c);
            } else {
                update(1, MAX, 1, v[a], m, c);
                update(1, MAX, 1, 1, v[b], c);
            }
        }
    }
    return 0;
}