#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321

int dp[101][101][101];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string a, b, c;
    cin >> a >> b >> c;

    for (int i = 1; i <= a.length(); i++)
    {
        for (int j = 1; j <= b.length(); j++)
        {
            for (int k = 1; k <= c.length(); k++)
            {
                if (a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1])
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                else
                    dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
            }
        }
    }

    cout << dp[a.length()][b.length()][c.length()];
    return 0;
}