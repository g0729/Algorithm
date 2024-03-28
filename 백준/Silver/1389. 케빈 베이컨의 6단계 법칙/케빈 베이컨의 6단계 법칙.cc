#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;

    cin >> n >> m;

    vector<vector<int>> v(n + 1, vector<int>(n + 1));

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a][b] = 1;
        v[b][a] = 1;
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (i == j)
                v[i][j] = 0;
            else if (v[i][j] == 0)
                v[i][j] = INF;
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            for (int k = 1; k < n + 1; k++)
            {
                v[j][k] = min(v[j][k], v[j][i] + v[i][k]);
            }
        }
    }

    int idx, res;

    res = 1e9;

    for (int i = 1; i <= n; i++)
    {
        int temp = 0;
        for (int j = 1; j <= n; j++)
        {
            temp += v[i][j];
        }

        if (temp < res)
        {
            res = temp;
            idx = i;
        }
    }

    cout << idx;

    return 0;
}