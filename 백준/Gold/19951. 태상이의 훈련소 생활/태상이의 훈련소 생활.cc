#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100010
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

vector<int> tree(4 * MAX), v(MAX);

void init(int start, int end, int node) {
    if (start == end) {
        tree[node] = v[start];
        return;
    }

    int mid = (start + end) / 2;

    init(start, mid, node * 2);
    init(mid + 1, end, node * 2 + 1);
}

void update(int start, int end, int node, int left, int right, int val) {
    if (right < start || left > end) return;

    if (left <= start && end <= right) {
        tree[node] += val;
        return;
    }

    int mid = (start + end) / 2;

    update(start, mid, node * 2, left, right, val);
    update(mid + 1, end, node * 2 + 1, left, right, val);
}

int query(int start, int end, int node, int idx, int res) {
    if (idx < start || idx > end) return 0;

    res += tree[node];

    if (start == end) return res;

    int mid = (start + end) / 2;

    return query(start, mid, node * 2, idx, res) +
           query(mid + 1, end, node * 2 + 1, idx, res);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) cin >> v[i];

    init(1, n, 1);
    for (int i = 0; i < m; i++) {
        int a, b, k;
        cin >> a >> b >> k;

        update(1, n, 1, a, b, k);
    }

    for (int i = 1; i <= n; i++) cout << query(1, n, 1, i, 0) << " ";
    return 0;
}