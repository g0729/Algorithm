#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

int n, m;

void bfs(vector<vector<int>> &moves, pair<int, int> p) {
    queue<pair<int, int>> q;
    q.push(p);
    moves[p.first][p.second] = 0;
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (moves[nx][ny] != -1) continue;

            moves[nx][ny] = moves[cur.first][cur.second] + 1;
            q.push({nx, ny});
        }
    }
}

void acc_cnt(vector<vector<int>> &res, vector<vector<int>> &cnt, int val) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            if (res[i][j] == -2) continue;

            if (cnt[i][j] == -1) {
                res[i][j] = -2;
                continue;
            }

            if (res[i][j] == -1) {
                res[i][j] = (cnt[i][j] + val - 1) / val;
                continue;
            }

            res[i][j] += (cnt[i][j] + val - 1) / val;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    vector<string> MAP(n);
    for (auto &a : MAP) cin >> a;

    vector<vector<int>> res(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            if (MAP[i][j] == '.') continue;

            vector<vector<int>> moves(n, vector<int>(m, -1));
            bfs(moves, {i, j});
            acc_cnt(res, moves, MAP[i][j] - '0');
        }
    }

    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (res[i][j] < 0) continue;

            ans = min(ans, res[i][j]);
        }
    }
    if (ans == 1e9)
        cout << -1;
    else
        cout << ans;
    return 0;
}