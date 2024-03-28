#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int MAP[300][300];
bool visited[300][300];
int n, m;
int dx[] = {1, 0};
int dy[] = {0, 1};
bool bfs()
{
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 2; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (visited[nx][ny])
                continue;
            if (MAP[nx][ny] == 0)
                continue;
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }

    return visited[n - 1][m - 1];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> MAP[i][j];
        }
    }

    if (bfs())
        cout << "Yes";
    else
        cout << "No";
    return 0;
}