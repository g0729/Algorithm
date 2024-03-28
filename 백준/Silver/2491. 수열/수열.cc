#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

int dp[MAX];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    dp[0] = 1;

    for (int i = 1; i < n; i++)
    {
        if (v[i] >= v[i - 1])
            dp[i] = dp[i - 1] + 1;
        else
            dp[i] = 1;
    }

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res = max(res, dp[i]);
    }

    for (int i = 1; i < n; i++)
    {
        if (v[i] <= v[i - 1])
            dp[i] = dp[i - 1] + 1;
        else
            dp[i] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        res = max(res, dp[i]);
    }
    cout << res;
    return 0;
}