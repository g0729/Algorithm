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

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<int> dp(n);
    dp[0] = 1;

    for (int i = 1; i < n; i++)
    {
        if (v[i] > v[i - 1])
            dp[i] = dp[i - 1] + 1;
        else
        {
            if (dp[i - 1] + 1 <= v[i])
                dp[i] = dp[i - 1] + 1;
            else
                dp[i] = v[i];
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res = max(res, dp[i]);
    }

    cout << res;

    return 0;
}
