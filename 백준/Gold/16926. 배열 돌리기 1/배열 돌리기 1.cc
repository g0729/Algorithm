#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int n, m, r;

void rotate(int start_x, int end_x, int start_y, int end_y, vector<vector<int>> &v)
{
    if (start_x >= end_x || start_y >= end_y)
        return;
    int cur_x = start_x, cur_y = start_y;
    int temp = v[cur_x][cur_y];
    int dir = 0;

    while (true)
    {
        int nx = cur_x + dx[dir], ny = cur_y + dy[dir];

        if (nx == start_x && ny == start_y)
            break;

        v[cur_x][cur_y] = v[nx][ny];
        if (dir == 0 && ny == end_y)
            dir++;
        else if (dir == 1 && nx == end_x)
            dir++;
        else if (dir == 2 && ny == start_y)
            dir++;
        cur_x = nx;
        cur_y = ny;
    }
    v[start_x + 1][start_y] = temp;
    rotate(start_x + 1, end_x - 1, start_y + 1, end_y - 1, v);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> r;
    vector<vector<int>> v(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }

    for (int i = 0; i < r; i++)
        rotate(0, n - 1, 0, m - 1, v);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << v[i][j] << " ";
        cout << endl;
    }

    return 0;
}