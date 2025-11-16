#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

int n, m;
pair<int, int> src, dst;

int bfs(vector<string> &MAP) {
    deque<pair<int, int>> q;
    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    q.push_back(src);
    dist[src.first][src.second] = 0;

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop_front();
        for (int i = 0; i < 4; i++) {
            int x = cur.first + dx[i];
            int y = cur.second + dy[i];

            if (x < 0 || x >= n || y < 0 || y >= m) continue;

            if (MAP[x][y] == '#') continue;

            if (MAP[x][y] == '-') {
                if (MAP[cur.first][cur.second] == '-' && dist[x][y] > dist[cur.first][cur.second]) {
                    q.push_front({x, y});
                    dist[x][y] = dist[cur.first][cur.second];
                } else if (MAP[cur.first][cur.second] == '.' && dist[x][y] > dist[cur.first][cur.second] + 1) {
                    q.push_back({x, y});
                    dist[x][y] = dist[cur.first][cur.second] + 1;
                }
            } else if (MAP[x][y] == '.' && dist[x][y] > dist[cur.first][cur.second] + 1) {
                q.push_back({x, y});
                dist[x][y] = dist[cur.first][cur.second] + 1;
            }
        }
    }

    return dist[dst.first][dst.second];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    vector<string> MAP(n);
    for (auto &a : MAP) cin >> a;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (MAP[i][j] == 'S') {
                src = {i, j};
                MAP[i][j] = '.';
            }
            if (MAP[i][j] == 'E') {
                dst = {i, j};
                MAP[i][j] = '.';
            }

            if (MAP[i][j] == '.') {

                bool flag = false;
                for (int k = 0; k < 4; k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];

                    if (x < 0 || x >= n || y < 0 || y >= m) continue;

                    if (MAP[x][y] == '#') flag = true;
                }

                if (flag) MAP[i][j] = '-';
            }
        }
    }

    cout << bfs(MAP);
    return 0;
}