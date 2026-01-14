#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

int n;
vector<string> v(2);

int bfs(int start) {
    if (v[start][0] == '#') return 1e9;

        queue<pair<int, int>> q;
    vector<vector<int>> dist(2, vector<int>(n, 1e9));
    dist[start][0] = 1;
    q.push({start, 0});

    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= 2 || ny < 0 || ny >= n) continue;
            if (dist[nx][ny] != 1e9) continue;
            if (v[nx][ny] == '#') continue;

            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }

    return min(dist[0][n - 1], dist[1][n - 1]);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> v[0] >> v[1];

    int res = n * 2;
    for (auto &s : v) {
        for (auto &c : s) res -= (c == '#' ? 1 : 0);
    }

    res -= min(bfs(0), bfs(1));

    cout << res;
    return 0;
}