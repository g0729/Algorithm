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
    int n, k;
    cin >> n >> k;
    vector<int> s(n + 1);
    vector<int> h(n + 1);

    for (int i = 1; i < n + 1; i++)
        cin >> s[i];
    for (int i = 1; i < n + 1; i++)
        cin >> h[i];

    vector<vector<int>> dp(n + 1, vector<int>(101));

    for (int i = 1; i < n + 1; i++)
    {
        dp[i][100 - h[i]] = s[i];

        for (int j = 0; j < 101; j++)
        {
            if (!dp[i - 1][j])
                continue;
            int hp = min(100, j + k);
            dp[i][hp] = max(dp[i][hp], dp[i - 1][j]);
            if ((hp - h[i]) >= 0)
                dp[i][hp - h[i]] = max(dp[i][hp - h[i]], dp[i - 1][j] + s[i]);
        }
    }

    int res = 0;

    for (int i = 0; i < 101; i++)
        res = max(res, dp[n][i]);

    cout << res;
    return 0;
}