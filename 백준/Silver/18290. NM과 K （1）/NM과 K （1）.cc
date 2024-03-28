#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

int MAP[10][10];
bool check[10][10];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m;
int res = -1e4;

void dfs(int now, int cnt, int sum)
{
    if (now == cnt)
    {
        res = max(sum, res);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            bool flag = true;

            if (!check[i][j])
            {
                for (int d = 0; d < 4; d++)
                {
                    int nx = i + dx[d];
                    int ny = j + dy[d];

                    if (nx < 0 && nx >= n && ny < 0 && ny >= m)
                        continue;
                    if (check[nx][ny])
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    check[i][j] = true;
                    dfs(now + 1, cnt, sum + MAP[i][j]);
                    check[i][j] = false;
                }
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int k;
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> MAP[i][j];
        }
    }

    dfs(0, k, 0);

    cout << res;

    return 0;
}