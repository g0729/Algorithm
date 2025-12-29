#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100001
#define INF 987654321
ll dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
ll dy[] = {0, 0, 1, -1, -1, 1, -1, 1};
ll n, maxLevel = 17;
vector<pair<ll, ll>> adj[MAX];
ll dist[MAX], level[MAX], parent[MAX][18];

void bfs(ll root) {
    queue<ll> q;
    q.push(root);
    level[root] = 1;

    while (!q.empty()) {
        ll cur = q.front();
        q.pop();

        for (auto &edge : adj[cur]) {
            ll next = edge.first;
            ll cost = edge.second;

            if (level[next] != 0) continue;

            level[next] = level[cur] + 1;
            dist[next] = dist[cur] + cost;
            parent[next][0] = cur;
            q.push(next);
        }
    }
}

void makeSparseTable() {
    for (ll i = 1; i <= maxLevel; i++) {
        for (ll j = 1; j <= n; j++) {
            if (parent[j][i - 1] != 0) {
                parent[j][i] = parent[parent[j][i - 1]][i - 1];
            }
        }
    }
}

ll lca(ll a, ll b) {
    if (level[a] < level[b]) swap(a, b);

    ll target = a, compare = b;

    if (level[target] != level[compare]) {
        for (ll i = maxLevel; i >= 0; i--) {
            if (level[parent[target][i]] >= level[compare]) {
                target = parent[target][i];
            }
        }
    }
    ll ret = target;
    if (target != compare) {
        for (ll i = maxLevel; i >= 0; i--) {
            if (parent[target][i] != parent[compare][i]) {
                target = parent[target][i];
                compare = parent[compare][i];
            }
            ret = parent[target][i];
        }
    }

    return ret;
}
ll curDist(ll a, ll b) {
    ll LCA = lca(a, b);
    return (dist[a] + dist[b] - dist[LCA] * 2);
}

ll getKthAncestor(int node, int diff) {
    for (int i = 0; i <= maxLevel; i++) {
        if (diff & (1 << i)) {
            node = parent[node][i];
        }
    }

    return node;
}

ll getKthNode(int a, int b, int k) {
    int LCA = lca(a, b);
    int distA = level[a] - level[LCA];

    if (k <= distA + 1) {
        return getKthAncestor(a, k - 1);
    } else {
        int distB = level[b] - level[LCA];
        int kFromB = distA + distB + 1 - k + 1;

        return getKthAncestor(b, kFromB - 1);
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (ll i = 0; i < n - 1; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    bfs(1);
    makeSparseTable();

    ll m;
    cin >> m;

    while (m--) {
        ll op, a, b, k;
        cin >> op >> a >> b;

        if (op == 1) {
            cout << curDist(a, b);
        } else if (op == 2) {
            cin >> k;
            cout << getKthNode(a, b, k);
        }

        cout << "\n";
    }
    return 0;
}