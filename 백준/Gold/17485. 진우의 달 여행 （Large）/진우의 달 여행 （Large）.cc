#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;

    vector<vector<int>> v(n, vector<int>(m));
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(3)));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (j == 0)
                dp[i][j][0] = 1e9;
            if (j == (m - 1))
                dp[i][j][2] = 1e9;
            cin >> v[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            dp[0][i][j] = v[0][i];
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (j != 0)
                dp[i][j][0] = v[i][j] + min(dp[i - 1][j - 1][1], dp[i - 1][j - 1][2]);
            if (j != (m - 1))
                dp[i][j][2] = v[i][j] + min(dp[i - 1][j + 1][0], dp[i - 1][j + 1][1]);
            dp[i][j][1] = v[i][j] + min(dp[i - 1][j][0], dp[i - 1][j][2]);
        }
    }

    int res = 1e9;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (dp[n - 1][i][j])
                res = min(res, dp[n - 1][i][j]);
        }
    }

    cout << res;

    return 0;
}