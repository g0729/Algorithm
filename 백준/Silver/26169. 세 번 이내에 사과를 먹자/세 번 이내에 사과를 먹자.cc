#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int MAP[5][5];
bool visited[5][5];
bool flag;
void dfs(int cnt, int x, int y, int apple)
{
    if (cnt == 3)
    {
        if (apple >= 2)
            flag = true;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5)
            continue;
        if (visited[nx][ny])
            continue;
        if (MAP[nx][ny] == -1)
            continue;

        int temp = apple;
        if (MAP[nx][ny] == 1)
            temp++;
        visited[nx][ny] = true;
        dfs(cnt + 1, nx, ny, temp);
        visited[nx][ny] = false;
    }
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

    int r, c;
    cin >> r >> c;

    visited[r][c] = true;
    dfs(0, r, c, 0);

    if (flag)
        cout << "1";
    else
        cout << "0";
    return 0;
}