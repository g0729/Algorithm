#include <bits/stdc++.h>
using namespace std;
#define MAX 40001
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};
int n, maxLevel = 17;
vector<vector<pair<int, int>>> adj(MAX, vector<pair<int, int>>());
vector<vector<int>> parent(MAX, vector<int>(maxLevel));
vector<int> level(MAX), dist(MAX, -1);
void setTree(int node, int pnode, int lv) {
    level[node] = lv;
    parent[node][0] = pnode;

    for (int i = 1; i <= maxLevel; i++) parent[node][i] = parent[parent[node][i - 1]][i - 1];

    for (auto next : adj[node]) {
        if (next.first == pnode) continue;
        setTree(next.first, node, lv + 1);
    }

    return;
}
void bfs(int root) {
    queue<int> q;
    q.push(root);
    dist[root] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto next : adj[cur]) {
            if (dist[next.first] != -1) continue;
            dist[next.first] = dist[cur] + next.second;
            q.push(next.first);
        }
    }

    return;
}

int lca(int a, int b) {
    int target = a, compare = b;

    if (level[target] < level[compare]) swap(target, compare);
    if (target != compare) {
        for (int i = maxLevel; i >= 0; i--) {
            if (level[parent[target][i]] >= level[compare]) {
                target = parent[target][i];
            }
        }
    }

    int ret = target;

    if (target != compare) {
        for (int i = maxLevel; i >= 0; i--) {
            if (parent[target][i] != parent[compare][i]) {
                target = parent[target][i];
                compare = parent[compare][i];
            }

            ret = parent[target][i];
        }
    }

    return (dist[a] + dist[b] - 2 * dist[ret]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    setTree(1, 0, 1);
    bfs(1);

    int m;
    cin >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;

        cout << lca(a, b) << "\n";
    }
    return 0;
}