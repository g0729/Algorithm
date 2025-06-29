#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
ll dx[] = {1, -1, 0, 0};
ll dy[] = {0, 0, 1, -1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll c, n;
    cin >> c >> n;

    vector<pair<ll, ll>> v(n);

    for (auto &a : v) cin >> a.first >> a.second;

    vector<vector<ll>> dp(n + 1, vector<ll>(c + 101, INF));
    dp[0][0] = 0;
    for (ll i = 1; i <= n; i++) {
        ll val = v[i - 1].first;
        ll weight = v[i - 1].second;

        dp[i][val] = weight;
        dp[i][0] = 0;
        for (ll j = 1; j < c + 101; j++) {

            if (j >= weight)
                dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - weight] + val, dp[i][j - weight] + val));
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    ll res = INF;

    for (ll i = c; i < c + 101; i++) res = min(res, dp[n][i]);

    cout << res;

    return 0;
}