#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100001
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

int n, m, maxLevel;
vector<int> level(MAX);
vector<vector<int>> parent(MAX, vector<int>(18)), adj(MAX, vector<int>());

void setTree(int node, int pnode, int lv) {
    level[node] = lv;
    parent[node][0] = pnode;

    for (int i = 1; i <= maxLevel; i++) {
        parent[node][i] = parent[parent[node][i - 1]][i - 1];
    }

    for (auto next : adj[node]) {
        if (next == pnode) continue;
        setTree(next, node, lv + 1);
    }
}

int lca(int a, int b) {
    if (a == 1 || b == 1) return 1;

    int tar = a, cmp = b;

    if (level[a] < level[b]) swap(tar, cmp);

    if (level[tar] != level[cmp]) {
        for (int i = maxLevel; i >= 0; i--) {
            if (level[parent[tar][i]] >= level[cmp]) {
                tar = parent[tar][i];
            }
        }
    }

    int ret = tar;

    if (tar != cmp) {
        for (int i = maxLevel; i >= 0; i--) {
            if (parent[tar][i] != parent[cmp][i]) {
                tar = parent[tar][i];
                cmp = parent[cmp][i];
            }

            ret = parent[tar][i];
        }
    }

    return ret;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    maxLevel = (int)floor(log2(MAX));

    setTree(1, 0, 1);

    cin >> m;

    while (m--) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << "\n";
    }
    return 0;
}