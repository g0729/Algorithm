#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 1000

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n, k, resX, resY;
int MAP[MAX][MAX];
void dfs()
{
    int x = n / 2;
    int y = n / 2;
    MAP[x][y] = 1;
    int now = 1;
    int cnt = 0;
    int dir = 0;
    int idx = 2;
    int changCnt = 0;
    while (1)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || ny < 0 || nx >= n || ny >= n)
            break;
        MAP[nx][ny] = idx;
        if (idx == k)
        {
            resX = nx + 1;
            resY = ny + 1;
        }
        idx++;
        cnt++;
        x = nx;
        y = ny;
        if (cnt == now)
        {
            cnt = 0;
            dir = (dir + 1) % 4;
            changCnt++;

            if (changCnt == 2)
            {
                now++;
                changCnt = 0;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    dfs();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << MAP[i][j] << " ";
        }
        cout << "\n";
    }
    if (k == 1)
        cout << n / 2 + 1 << " " << n / 2 + 1;
    else
        cout << resX << " " << resY;
    return 0;
}