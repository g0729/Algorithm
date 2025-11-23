#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};
int n, m, k;
vector<vector<int>> MAP(1001, vector<int>(1001));

int bfs() {
    vector<vector<bool>> visited(1001, vector<bool>(1001));
    visited[500][500] = true;
    queue<pair<int, int>> q;

    q.push({500, 500});
    int res = 0;
    while (!q.empty()) {
        int size = q.size();

        while (size--) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            if (x == (n + 500) && y == (m + 500)) return res;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];

                if (nx < 0 || nx >= 1001 || y < 0 || y >= 1001) continue;
                if (visited[nx][ny]) continue;
                if (MAP[nx][ny] == 1) continue;
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
        res++;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;

    while (k--) {
        int x, y;
        cin >> x >> y;

        MAP[x + 500][y + 500] = 1;
    }

    cout << bfs();
    return 0;
}