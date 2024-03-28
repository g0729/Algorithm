#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000
ll dp[100][100];
int MAP[100][100];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    dp[0][0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> MAP[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 1; k < 10; k++)
            {
                if (j - k >= 0)
                {
                    if (MAP[i][j - k] == k)
                    {
                        dp[i][j] += dp[i][j - k];
                    }
                }
                if (i - k >= 0)
                {
                    if (MAP[i - k][j] == k)
                    {
                        dp[i][j] += dp[i - k][j];
                    }
                }
            }
        }
    }

    cout << dp[n - 1][n - 1];

    return 0;
}