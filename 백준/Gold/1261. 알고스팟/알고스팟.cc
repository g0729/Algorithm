#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

int n, m;
vector<string> MAP;

int dij() {
    priority_queue<pair<int, pair<int, int>>> pq;
    vector<vector<int>> dist(n, vector<int>(m, INF));
    pq.push({0, {0, 0}});
    dist[0][0] = 0;

    while (!pq.empty()) {
        int cost = -pq.top().first;
        pair<int, int> cur = pq.top().second;
        pq.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

            int ncost = cost + (MAP[nx][ny] == '1' ? 1 : 0);

            if (dist[nx][ny] > ncost) {
                dist[nx][ny] = ncost;
                pq.push({-ncost, {nx, ny}});
            }
        }
    }

    return dist[n - 1][m - 1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        MAP.push_back(s);
    }

    cout << dij();
    return 0;
}