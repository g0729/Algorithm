#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000

int dp[21][101];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> v2(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < n; i++)
        cin >> v2[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= 100; j++)
        {
            if (j - v[i] <= 0)
                dp[i + 1][j] = dp[i][j];
            else
                dp[i + 1][j] = max(dp[i][j], dp[i][j - v[i]] + v2[i]);
        }
    }

    cout << dp[n][100];
    return 0;
}