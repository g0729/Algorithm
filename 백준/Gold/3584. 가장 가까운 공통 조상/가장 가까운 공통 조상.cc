#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};
int n;
vector<int> parent, level;
vector<vector<int>> edges;

void setTree(int root) {
    parent[root] = 0;
    level[root] = 1;

    queue<int> q;
    q.push(root);

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (auto &next : edges[now]) {
            if (level[next] != 0) continue;

            q.push(next);
            parent[next] = now;
            level[next] = level[now] + 1;
        }
    }
}

int lca(int a, int b) {
    if (level[a] < level[b]) swap(a, b);

    while (level[a] != level[b]) a = parent[a];

    while (a != b) a = parent[a], b = parent[b];

    return a;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n;
        parent = vector<int>(n + 1);
        level = vector<int>(n + 1);
        edges = vector<vector<int>>(n + 1, vector<int>());
        vector<int> inDegree(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            edges[a].push_back(b);
            inDegree[b]++;
        }
        int root = 0;
        for (int i = 1; i <= n; i++) {
            if (inDegree[i] == 0) {
                root = i;
                break;
            }
        }
        setTree(root);
        cin >> a >> b;

        cout << lca(a, b) << "\n";
    }

    return 0;
}