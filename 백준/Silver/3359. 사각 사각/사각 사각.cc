#include <bits/stdc++.h>
using namespace std;

int main()
{
    int dp[4];

    int n;

    cin >> n;

    int w, h, wNow, hNow;

    cin >> w >> h;

    dp[0] = w;
    dp[1] = h;

    for (int i = 1; i < n ; i++)
    {
        cin >> wNow >> hNow;

        dp[2] = max(dp[0] + abs(hNow - h) + wNow, dp[1] + abs(hNow - w) + wNow);
        dp[3] = max(dp[0] + abs(wNow - h) + hNow, dp[1] + abs(wNow - w) + hNow);
        dp[0] = dp[2];
        dp[1] = dp[3];
        w = wNow;
        h = hNow;
    }

    cout<<max(dp[0],dp[1]);
}