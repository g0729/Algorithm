#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 1000001
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

int n, m, k;
vector<ll> tree(4 * MAX);
vector<ll> v(MAX);

ll init(int start, int end, int node) {
    if (start == end) return tree[node] = v[start];

    int mid = (start + end) / 2;

    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

ll sum(int start, int end, int node, int left, int right) {

    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;

    return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

ll update(int start, int end, int node, int idx, ll val) {

    if (idx < start || idx > end) return tree[node];

    if (start == end) return tree[node] = val;

    int mid = (start + end) / 2;

    return tree[node] = update(start, mid, node * 2, idx, val) + update(mid + 1, end, node * 2 + 1, idx, val);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) cin >> v[i];

    init(1, n, 1);
    for (int i = 0; i < m + k; i++) {
        ll a, b, c;
        cin >> a >> b >> c;

        if (a == 1) {
            update(1, n, 1, b, c);
        } else if (a == 2) {
            cout << sum(1, n, 1, b, c) << "\n";
        }
    }
    return 0;
}