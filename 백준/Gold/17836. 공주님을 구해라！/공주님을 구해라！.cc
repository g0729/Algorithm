#include <bits/stdc++.h>
using namespace std;
#define MAX 100
int n, m, t;
int MAP[MAX][MAX];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int visited[MAX][MAX][2];
void bfs()
{
    queue<tuple<int, int, bool>> q;
    q.push({0, 0, false});
    while (!q.empty())
    {
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        bool sword = get<2>(q.front());
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (visited[nx][ny][sword] != 0)
                continue;
            if (MAP[nx][ny] == 1)
            {
                if (!sword)
                    continue;
                else
                {
                    q.push({nx, ny, sword});
                    visited[nx][ny][sword] = visited[x][y][sword] + 1;
                    continue;
                }
            }
            if (MAP[nx][ny] == 2)
            {
                visited[nx][ny][1] = visited[x][y][0] + 1;
                q.push({nx, ny, true});
            }
            else
                q.push({nx, ny, sword});
            visited[nx][ny][sword] = visited[x][y][sword] + 1;
        }
    }
}
int main()
{
    cin >> n >> m >> t;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> MAP[i][j];
        }
    }
    bfs();
    int res ;
    if(visited[n-1][m-1][0]==0||visited[n-1][m-1][1]==0)
    {
        res=max(visited[n-1][m-1][1],visited[n-1][m-1][0]);
    }
    else
    {
        res=min(visited[n-1][m-1][1],visited[n-1][m-1][0]);
    }
    if (res == 0 || res > t)
        cout << "Fail";
    else
        cout << res;
}