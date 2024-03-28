#include <bits/stdc++.h>
using namespace std;
#define MAX 500
int MAP[MAX][MAX];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m;
int k;
void dfs(int x, int y)
{
    MAP[x][y] = 0;
    k++;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && MAP[nx][ny] == 1)
        {
            dfs(nx, ny);
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
        for (int q = 0; q < m; q++)
        {
            cin >> MAP[i][q];
        }
    }
    int res = 0;
    int rescnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int q = 0; q < m; q++)
        {
            if (MAP[i][q] == 1)
            {
                k = 0;
                dfs(i, q);
                rescnt++;
                res = max(k, res);
            }
        }
    }
    cout << rescnt << endl
         << res;
}