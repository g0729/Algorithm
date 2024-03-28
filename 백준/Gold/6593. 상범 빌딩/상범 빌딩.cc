#include <bits/stdc++.h>
using namespace std;
#define MAX 30

queue<tuple<int, int, int>> q;
char MAP[MAX][MAX][MAX];
int visited[MAX][MAX][MAX];
int l, r, c;
int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};

void bfs()
{
    while (!q.empty())
    {
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int z = get<2>(q.front());
        q.pop();
        for (int i = 0; i < 6; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];
            if (nx < 0 || nx >= r || ny < 0 || ny >= c || nz < 0 || nz >= l)
                continue;
            if (visited[nx][ny][nz] != 0)
                continue;
            if (MAP[nx][ny][nz] == '#')
                continue;
            q.push({nx, ny, nz});
            visited[nx][ny][nz] = visited[x][y][z] + 1;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (1)
    {
        int X, Y, Z;
        cin >> l >> r >> c;
        if(l==0&&r==0&&c==0)
        return 0;
        for (int z = 0; z < l; z++)
        {
            for (int x = 0; x < r; x++)
            {
                string s;
                cin >> s;
                for (int y = 0; y < c; y++)
                {
                    MAP[x][y][z] = s[y];
                    if (MAP[x][y][z] == 'S')
                    {
                        q.push({x, y, z});
                        visited[x][y][z] = 1;
                    }
                    if (MAP[x][y][z] == 'E')
                    {
                        X = x;
                        Y = y;
                        Z = z;
                    }
                }
            }
        }

        bfs();

        if (visited[X][Y][Z] == 0)
            cout << "Trapped!\n";
        else
        {
            cout << "Escaped in " << visited[X][Y][Z] - 1 << " minute(s).\n";
        }
        memset(visited,0,sizeof(visited));
    }
}
