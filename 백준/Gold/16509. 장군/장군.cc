#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
int mov[8][3] = {{0, 1, 1}, {0, 7, 7}, {2, 1, 1}, {2, 3, 3}, {4, 3, 3}, {4, 5, 5}, {6, 5, 5}, {6, 7, 7}};
bool visited[10][9];
int r1, c1, r2, c2;

bool check(int x, int y, int dir)
{
    int nx = x;
    int ny = y;

    for (int i = 0; i < 2; i++)
    {
        nx = nx + dx[mov[dir][i]];
        ny = ny + dy[mov[dir][i]];

        if (nx == r2 && ny == c2)
            return false;
    }
    return true;
}
int bfs()
{
    queue<pair<int, int>> q;

    q.push({r1, c1});
    visited[r1][c1] = true;

    int level = 0;
    while (!q.empty())
    {
        int size = q.size();

        bool flag = false;
        while (size--)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < 8; i++)
            {
                if (check(x, y, i))
                {
                    int nx = x;
                    int ny = y;

                    for (int j = 0; j < 3; j++)
                    {
                        nx += dx[mov[i][j]];
                        ny += dy[mov[i][j]];
                    }

                    if (nx < 0 || nx >= 10 || ny < 0 || ny >= 9)
                        continue;
                    if (visited[nx][ny])
                        continue;
                    if (nx == r2 && ny == c2)
                    {
                        flag = true;
                        break;
                    }
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
            if (flag)
                break;
        }
        level++;
        if (flag)
            return level;
    }

    return -1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> r1 >> c1 >> r2 >> c2;

    cout << bfs();
    return 0;
}