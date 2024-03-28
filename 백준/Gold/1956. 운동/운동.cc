#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 401

int MAP[MAX][MAX];

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
    }

    for (int k = 1; k < n + 1; k++)
    {
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                if (MAP[i][k] && MAP[k][j])
                {
                    if (MAP[i][j] == 0)
                        MAP[i][j] = MAP[i][k] + MAP[k][j];
                    else
                        MAP[i][j] = min(MAP[i][j], MAP[i][k] + MAP[k][j]);
                }
            }
        }
    }

    int res = INF;

    for (int i = 1; i <= n; i++)
    {
        if (MAP[i][i] != 0)
            res = min(res, MAP[i][i]);
    }

    if (res == INF)
        cout << "-1";
    else
        cout << res;

    return 0;
}