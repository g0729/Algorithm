#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m;
vector<pair<int, int>> switches[101][101];
bool is_lighted[101][101];
int bfs()
{
    int res = 0;
    queue<pair<int, int>> q;
    vector<vector<int>> visited(n + 1, vector<int>(n + 1));
    q.push({1, 1});
    visited[1][1] = true;

    while (!q.empty())
    {
        pair<int, int> now = q.front();
        q.pop();

        for (int i = 0; i < switches[now.first][now.second].size(); i++)
        {
            pair<int, int> p = switches[now.first][now.second][i];
            is_lighted[p.first][p.second] = true;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];

            if (nx < 1 || nx > n || ny < 1 || ny > n)
                continue;
            if (visited[nx][ny] || !is_lighted[nx][ny])
                continue;
            q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            res += (is_lighted[i][j] ? 1 : 0);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    is_lighted[1][1] = true;
    for (int i = 0; i < m; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        switches[a][b].push_back({c, d});
    }

    int res = bfs();

    while (true)
    {
        int next = bfs();
        if (res == next)
            break;
        res = next;
    }

    cout << res;
    return 0;
}