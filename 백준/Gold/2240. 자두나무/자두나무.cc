#include <bits/stdc++.h>
using namespace std;
int dp[1001][31][2];
int main()
{
    int n, w;
    cin >> n >> w;
    int res = 0;

    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        if (temp == 1)
        {
            dp[i][0][0] = dp[i - 1][0][0] + 1;
        }
        for (int j = 1; j <= w; j++)
        {
            dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j - 1][1]) + abs(temp - 2);
            dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0]) + abs(temp - 1);
        }
    }

    for (int i = 0; i <= w; i++)
    {
        res = max(res, dp[n][i][0]);
        res = max(res, dp[n][i][1]);
    }
    cout << res;
}