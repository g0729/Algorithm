#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 1000
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

int n;
vector<pair<int, int>> edges[MAX][MAX];
vector<vector<int>> in_degree(MAX, vector<int>(MAX)), res(MAX, vector<int>(MAX));

void get_in_degree() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (auto &edge : edges[i][j]) {
                in_degree[edge.first][edge.second]++;
            }
        }
    }
}

void topo_sort() {
    queue<pair<int, int>> q;
    int idx = 1;

    get_in_degree();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!in_degree[i][j]) q.push({i, j});
        }
    }

    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();

        res[x][y] = idx++;

        for (auto &edge : edges[x][y]) {
            int nx = edge.first, ny = edge.second;

            in_degree[nx][ny]--;

            if (!in_degree[nx][ny]) q.push({nx, ny});
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            char c;
            cin >> c;

            if (c == '<') {
                edges[i][j].push_back({i, j + 1});
            } else if (c == '>') {
                edges[i][j + 1].push_back({i, j});
            }
        }
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;

            if (c == '<') {
                edges[i][j].push_back({i + 1, j});
            } else if (c == '>') {
                edges[i + 1][j].push_back({i, j});
            }
        }
    }

    topo_sort();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << res[i][j] << " ";

        cout << "\n";
    }
    return 0;
}