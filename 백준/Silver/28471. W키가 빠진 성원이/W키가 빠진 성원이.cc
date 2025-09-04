#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {-1, -1, -1, 0, 0, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<string> MAP(n);

    for (auto &s : MAP) cin >> s;

    vector<vector<bool>> visited(n, vector<bool>(n));

    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        bool flag = false;
        for (int j = 0; j < n; j++) {
            if (MAP[i][j] == 'F') {
                q.push({i, j});
                visited[i][j] = true;
                flag = true;
                break;
            }
        }
        if (flag) break;
    }

    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();

        for (int i = 0; i < 7; i++) {
            int nx = x + dx[i], ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

            if (MAP[nx][ny] == '#') continue;
            if (visited[nx][ny]) continue;

            q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }

    int res = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j]) res++;
        }
    }

    cout << res;
    return 0;
}