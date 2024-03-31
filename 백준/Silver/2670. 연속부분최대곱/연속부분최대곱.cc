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

    int n;
    cin >> n;
    vector<double> v(n + 1);
    vector<double> dp(n + 1);
    for (int i = 0; i < n; i++)
        cin >> v[i + 1];

    double res = v[1];
    dp[1] = v[1];

    for (int i = 2; i <= n; i++)
    {
        if (dp[i - 1] * v[i] > v[i])
            dp[i] = dp[i - 1] * v[i];
        else
            dp[i] = v[i];
        res = max(res, dp[i]);
    }

    cout << fixed;
    cout.precision(3);
    cout << res;

    return 0;
}