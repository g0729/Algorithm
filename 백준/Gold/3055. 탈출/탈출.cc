#include <bits/stdc++.h>
using namespace std;
#define MAX 50
int waterMAP[MAX][MAX];
char MAP[MAX][MAX];
int visited[MAX][MAX];
queue<pair<int, int>> waterq;
queue<pair<int, int>> q;
int r, c;
pair<int, int> escloc;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
void waterbfs()
{
    while (!waterq.empty())
    {
        int x = waterq.front().first;
        int y = waterq.front().second;
        waterq.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= r || ny < 0 || ny >= c)
                continue;
            if (MAP[nx][ny] == 'X'||MAP[nx][ny]=='D')
                continue;
            if (waterMAP[nx][ny] != 0)
                continue;
            waterq.push({nx, ny});
            waterMAP[nx][ny] = waterMAP[x][y] + 1;
        }
    }
}
int bfs()
{
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx==escloc.first&&ny==escloc.second)
            return visited[x][y];
            if (nx < 0 || nx >= r || ny < 0 || ny >= c)
                continue;
            if (MAP[nx][ny] == 'X')
                continue;
            if (visited[nx][ny] != 0)
                continue;
            if (visited[x][y] + 1 >= waterMAP[nx][ny]&&waterMAP[nx][ny]!=0)
                continue;
            visited[nx][ny] = visited[x][y] + 1;
            q.push({nx, ny});
        }
    }
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> MAP[i][j];
            if (MAP[i][j] == 'S')
            {
                q.push({i, j});
                visited[i][j] = 1;
            }
            if (MAP[i][j] == 'D')
                escloc = {i, j};
            if (MAP[i][j] == '*')
            {
                waterq.push({i, j});
                waterMAP[i][j] = 1;
            }
        }
    }
    waterbfs();
    int res = bfs();

    if(res==-1)
    cout<<"KAKTUS";
    else
    cout << res;
}