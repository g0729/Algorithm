#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321

int dp[1001][1001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string a, b;
    cin >> a >> b;

    for (int i = 1; i <= a.length() / 3; i++)
    {
        for (int j = 1; j <= b.length() / 3; j++)
        {
            int idx = (i - 1) * 3;
            int idx2 = (j - 1) * 3;
            if (a[idx] == b[idx2] && a[idx + 1] == b[idx2 + 1] && a[idx + 2] == b[idx2 + 2])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    cout << dp[a.length() / 3][b.length() / 3];
    return 0;
}