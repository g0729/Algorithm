#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int r, c;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int MAP[5][5];
bool visited[5][5][7];
int bfs()
{
    queue<pair<pair<int, int>, int>> q;
    q.push({{r, c}, 0});
    visited[r][c][0] = true;
    int res = 0;

    while (q.size())
    {
        int size = q.size();
        while (size--)
        {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int level = q.front().second;
            q.pop();

            if (level == 6)
                return res;
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5)
                    continue;
                if (visited[nx][ny][level])
                    continue;
                if (MAP[nx][ny] == -1)
                    continue;

                int nlevel = level;
                if (MAP[nx][ny] == level + 1)
                    nlevel++;
                q.push({{nx, ny}, nlevel});
                visited[nx][ny][nlevel] = true;
            }
        }
        res++;
    }
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> MAP[i][j];
        }
    }
    cin >> r >> c;

    cout << bfs();
    return 0;
}