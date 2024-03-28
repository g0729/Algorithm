#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000

int n, m;
char MAPA[51][51];
char MAPB[51][51];
bool visited[51][51];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
void bfs(int x, int y, char c)
{
    char color = MAPA[x][y];
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    MAPA[x][y] = c;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if (visited[nx][ny])
                continue;
            if (MAPA[nx][ny] != color)
                continue;

            MAPA[nx][ny] = c;
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> MAPA[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> MAPB[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (MAPA[i][j] != MAPB[i][j])
            {
                if (!visited[i][j])
                    bfs(i, j, MAPB[i][j]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (MAPA[i][j] != MAPB[i][j])
            {
                cout << "NO";
                return 0;
            }
        }
    }

    cout << "YES";
    return 0;
}