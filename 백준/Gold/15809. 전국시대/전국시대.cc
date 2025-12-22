#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100010
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

int n, m;
vector<int> parent(MAX);
vector<int> cnt(MAX);

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);

    parent[y] = x;
    cnt[x] += cnt[y];
    cnt[y] = 0;
}
void war(int x, int y) {
    x = find(x);
    y = find(y);

    if (cnt[x] == cnt[y]) {
        parent[x] = 0;
        parent[y] = 0;
    } else if (cnt[x] > cnt[y]) {
        cnt[x] -= cnt[y];
        parent[y] = x;
    } else {
        cnt[y] -= cnt[x];
        parent[x] = y;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        cin >> cnt[i];
    }

    while (m--) {
        int op, a, b;
        cin >> op >> a >> b;

        if (op == 1) {
            merge(a, b);
        } else if (op == 2) {
            war(a, b);
        }
    }

    set<int> se;
    vector<int> res;
    for (int i = 1; i <= n; i++) {
        int x = find(i);
        if (x == 0) continue;
        if (se.find(x) != se.end()) continue;

        se.insert(x);
        res.push_back(cnt[x]);
    }

    sort(res.begin(), res.end());

    cout << res.size() << "\n";
    for (auto &a : res) cout << a << " ";

    return 0;
}