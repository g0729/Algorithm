#include <bits/stdc++.h>
using namespace std;
int dp[101][51];
int sum[101];
int n, m;

int cal(int now, int nowarea)
{
    if (nowarea == 0)
        return 0;
    if (now <= 0)
        return -100000000;
    if (dp[now][nowarea] != -1)
        return dp[now][nowarea];

    dp[now][nowarea] = cal(now - 1, nowarea);

    for(int i = 1;i<=now;i++)
    {
        dp[now][nowarea]=max(dp[now][nowarea],cal(i-1,nowarea-1)+sum[now]-sum[i-1]);
    }
    return dp[now][nowarea];
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        sum[i] = sum[i - 1] + a;
    }
    memset(dp, -1, sizeof(dp));
    cout<<cal(n,m);
}