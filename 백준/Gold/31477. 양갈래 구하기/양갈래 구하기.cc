#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

int n;
vector<vector<pair<int, int>>> edges;

ll dfs(int node, int parent) {
    bool isLeaf = true;

    ll cost = 0;

    for (auto &edge : edges[node]) {
        int next = edge.first;
        ll w = edge.second;

        if (next != parent) {
            isLeaf = false;

            cost += min(w, dfs(next, node));
        }
    }

    if (isLeaf) return INF;
    return cost;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    edges = vector<vector<pair<int, int>>>(n + 1, vector<pair<int, int>>());

    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }

    cout << dfs(1, -1);
    return 0;
}