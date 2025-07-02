#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n, m, a, b, c;

vector<pair<int, int>> edges[100001];
bool dij(int target) {
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>> pq;
    pq.push({0, a});
    dist[a] = 0;

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dist[cur] < cost) continue;
        for (auto &[next, ncost] : edges[cur]) {
            if (ncost <= target && dist[next] > cost + ncost) {
                dist[next] = cost + ncost;
                pq.push({-dist[next], next});
            }
        }
    }

    return dist[b] <= c;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> a >> b >> c;

    for (int i = 0; i < m; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;

        edges[u].push_back({v, cost});
        edges[v].push_back({u, cost});
    }

    for (int i = 1; i <= 20; i++) {
        if (dij(i)) {
            cout << i;
            return 0;
        }
    }

    cout << "-1";
    return 0;
}