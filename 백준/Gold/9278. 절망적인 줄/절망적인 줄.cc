#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    while (cin >> s)
    {
        int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        dp[1][1] = 1;
        if (s[0] == ')')
        {
            cout << "0\n";
            continue;
        }
        for (int i = 2; i <= n; i++)
        {
            if (s[i - 1] == '(')
            {
                for (int j = (i + 1) / 2; j <= i && j <= n / 2; j++)
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
            else if (s[i - 1] == ')')
            {
                for (int j = (i + 1) / 2; j <= i && j <= n / 2; j++)
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
            else
            {
                for (int j = (i + 1) / 2; j <= i && j <= n / 2; j++)
                {
                    dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % 1000000;
                }
            }
        }
        cout << dp[n][n / 2] << "\n";
    }
    return 0;
}