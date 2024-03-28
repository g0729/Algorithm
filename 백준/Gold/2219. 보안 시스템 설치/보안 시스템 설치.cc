#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321

vector<vector<int>> MAP(201, vector<int>(201));

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        MAP[a][b] = c;
        MAP[b][a] = c;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if (MAP[j][i] && MAP[i][k])
                {
                    if (MAP[j][k] == 0)
                        MAP[j][k] = MAP[j][i] + MAP[i][k];
                    else
                        MAP[j][k] = min(MAP[j][k], MAP[j][i] + MAP[i][k]);
                }
            }
        }
    }
    int res = INF;
    int res_idx = 1;

    for (int i = 1; i <= n; i++)
    {
        int temp = 0;
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                continue;
            temp += MAP[i][j];
        }
        if (temp < res)
        {
            res = temp;
            res_idx = i;
        }
    }

    cout << res_idx;
    return 0;
}