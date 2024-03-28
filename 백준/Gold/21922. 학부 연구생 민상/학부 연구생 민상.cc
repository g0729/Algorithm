#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 2001

int MAP[MAX][MAX];
int air[MAX][MAX];
int visited[MAX][MAX][5];
int n, m;
int dx[] = {0, -1, 0, 1, 0};
int dy[] = {0, 0, 1, 0, -1};
void dfs(int x, int y, int dir)
{
    air[x][y] = 1;

    visited[x][y][dir] = true;
    int nextDir;

    if (MAP[x][y] == 0)
        nextDir = dir;
    else if (MAP[x][y] == 1)
    {
        if (dir % 2 == 0)
            return;
        nextDir = dir;
    }
    else if (MAP[x][y] == 2)
    {
        if (dir % 2 == 1)
            return;
        nextDir = dir;
    }
    else if (MAP[x][y] == 3)
    {
        if (dir == 1)
            nextDir = 2;
        if (dir == 2)
            nextDir = 1;
        if (dir == 3)
            nextDir = 4;
        if (dir == 4)
            nextDir = 3;
    }
    else if (MAP[x][y] == 4)
    {
        if (dir == 1)
            nextDir = 4;
        if (dir == 2)
            nextDir = 3;
        if (dir == 3)
            nextDir = 2;
        if (dir == 4)
            nextDir = 1;
    }

    int nx = x + dx[nextDir];
    int ny = y + dy[nextDir];

    if (nx <= 0 || nx > n || ny <= 0 || ny > m)
        return;
    if(visited[nx][ny][nextDir])
        return;
        
    dfs(nx, ny, nextDir);
}
void start(int x, int y)
{
    air[x][y] = 1;

    dfs(x - 1, y, 1);
    dfs(x, y + 1, 2);
    dfs(x + 1, y, 3);
    dfs(x, y - 1, 4);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> MAP[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (MAP[i][j] == 9)
                start(i, j);
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (air[i][j])
                res++;
        }
    }

    cout << res;
    return 0;
}