#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n, v, e;
int dst1, dst2;

vector<pair<int, int>> edges[1001];

int dij(int start) {
    vector<int> dist(v + 1, INF);
    priority_queue<pair<int, int>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (cost > dist[cur]) continue;

        for (auto &[next, ncost] : edges[cur]) {
            if (dist[next] > cost + ncost) {
                dist[next] = cost + ncost;
                pq.push({-dist[next], next});
            }
        }
    }

    return (dist[dst1] == INF ? -1 : dist[dst1]) + (dist[dst2] == INF ? -1 : dist[dst2]);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> v >> e;
    cin >> dst1 >> dst2;

    vector<int> kist(n);
    for (auto &a : kist) cin >> a;

    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }

    int res = 0;

    for (auto a : kist) {
        res += dij(a);
    }

    cout << res;
    return 0;
}