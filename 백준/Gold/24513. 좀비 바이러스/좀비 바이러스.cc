#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
int MAP[MAX][MAX];
int visited[MAX][MAX];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
queue<tuple<int, int, int>> q;
int n, m;

void bfs()
{
    while (!q.empty())
    {
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int time = get<2>(q.front());
        q.pop();
        if(MAP[x][y]==3)
        continue;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int ntime = time + 1;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (MAP[nx][ny] == MAP[x][y])
                continue;
            if (MAP[nx][ny] == 0)
            {
                MAP[nx][ny] = MAP[x][y];
                visited[nx][ny] = ntime;
                q.push({nx, ny, ntime});
            }
            else
            {
                if (visited[nx][ny] == ntime)
                {
                    MAP[nx][ny] = 3;
                }
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> MAP[i][j];
            if (MAP[i][j] == 1 || MAP[i][j] == 2)
            {
                q.push({i, j, 1});
                visited[i][j] = 1;
            }
        }
    }
    bfs();
    int res1,res2,res3;
    res1=res2=res3=0;

    for (int i = 0; i < n; i++)
    {
        for (int q = 0; q < m; q++)
        {
            if(MAP[i][q]==1)
            res1++;
            else if(MAP[i][q]==2)
            res2++;
            else if(MAP[i][q]==3)
            res3++;
        }
    }
    cout<<res1<<" "<<res2<<" "<<res3;
}