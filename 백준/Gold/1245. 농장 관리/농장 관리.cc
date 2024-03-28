#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100

int n, m;
int MAP[MAX][MAX];
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
bool visited[MAX][MAX];
int ans;
void bfs(int x, int y, int h)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    bool check = true;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (MAP[nx][ny] > h)
                check = false;
            else if (!visited[nx][ny] && MAP[nx][ny] == h)
            {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }

    if (check)
        ans++;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    int temp = 1e9;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> MAP[i][j];
            temp = min(MAP[i][j], temp);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (MAP[i][j] > temp && !visited[i][j])
                bfs(i, j, MAP[i][j]);
        }
    }

    cout << ans;
    return 0;
}