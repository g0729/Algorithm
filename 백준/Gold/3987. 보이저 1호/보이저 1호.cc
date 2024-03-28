#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 501

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n, m;
char MAP[MAX][MAX];
bool visited[MAX][MAX][4];

int dfs(int x, int y, int cnt, int dir)
{
    if (x < 0 || y < 0 || x >= n || y >= m || MAP[x][y] == 'C')
        return cnt;
    if (visited[x][y][dir])
        return 1e9;
    visited[x][y][dir] = true;
    if (MAP[x][y] == '/')
    {
        if (dir % 2 == 0)
            dir += 1;
        else
            dir -= 1;
    }
    if (MAP[x][y] == '\\')
    {
        if (dir % 2 == 0)
            dir = (dir + 3) % 4;
        else
            dir = (dir + 1) % 4;
    }
    int nx = x + dx[dir];
    int ny = y + dy[dir];

    return dfs(nx, ny, cnt + 1, dir);
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
            cin >> MAP[i][j];
        }
    }

    int res = 0;
    int res_idx;
    int a, b;
    cin >> a >> b;
    for (int i = 0; i < 4; i++)
    {
        int temp = dfs(a - 1, b - 1, 0, i);

        if (res < temp)
        {
            res = temp;
            res_idx = i;
        }
        memset(visited, 0, sizeof(visited));
    }

    vector<char> v = {'U', 'R', 'D', 'L'};
    cout << v[res_idx] << "\n";

    if (res == 1e9)
        cout << "Voyager";
    else
        cout << res;

    return 0;
}