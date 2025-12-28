#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100001
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

const int MAX_LEVEL = 18;
int n, m;
vector<pair<int, int>> adj[MAX];
int parent[MAX][MAX_LEVEL + 1];
int level[MAX];
int maxDist[MAX][MAX_LEVEL + 1], minDist[MAX][MAX_LEVEL + 1];
void bfs(int root) {
    queue<int> q;
    q.push(root);
    level[root] = 1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto &edge : adj[cur]) {
            int next = edge.first;
            int cost = edge.second;
            if (level[next] != 0) continue;

            level[next] = level[cur] + 1;
            parent[next][0] = cur;
            maxDist[next][0] = cost, minDist[next][0] = cost;
            q.push(next);
        }
    }
}

void makeSparseTable() {
    for (int i = 1; i <= MAX_LEVEL; i++) {
        for (int j = 1; j <= n; j++) {
            parent[j][i] = parent[parent[j][i - 1]][i - 1];
            maxDist[j][i] = max(maxDist[j][i - 1], maxDist[parent[j][i - 1]][i - 1]);
            minDist[j][i] = min(minDist[j][i - 1], minDist[parent[j][i - 1]][i - 1]);
        }
    }
}

void lca(int a, int b) {
    int resMax = 0, resMin = 1e9;
    if (level[a] < level[b]) swap(a, b);

    int target = a, compare = b;

    if (target != compare) {
        for (int i = MAX_LEVEL; i >= 0; i--) {
            if (level[parent[target][i]] >= level[compare]) {
                resMax = max(resMax, maxDist[target][i]);
                resMin = min(resMin, minDist[target][i]);
                target = parent[target][i];
            }
        }
    }

    if (target != compare) {
        for (int i = MAX_LEVEL; i >= 0; i--) {
            if (parent[target][i] != parent[compare][i]) {
                resMax = max(resMax, max(maxDist[target][i], maxDist[compare][i]));
                resMin = min(resMin, min(minDist[target][i], minDist[compare][i]));
                target = parent[target][i];
                compare = parent[compare][i];
            }
        }
        resMax = max(resMax, max(maxDist[target][0], maxDist[compare][0]));
        resMin = min(resMin, min(minDist[target][0], minDist[compare][0]));
    }

    cout << resMin << " " << resMax << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(minDist, 0x3f, sizeof(minDist));
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    bfs(1);
    makeSparseTable();

    cin >> m;

    while (m--) {
        int a, b;
        cin >> a >> b;

        lca(a, b);
    }
    return 0;
}